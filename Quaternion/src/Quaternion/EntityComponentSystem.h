#pragma once

#include "pch.h"
#include "Core.h"


namespace QUA {

    struct Entity {
        std::uint32_t id{ 0 };
        std::uint32_t gen{ 0 };

        //Makes sure that even if entities have the same id they are also the same gen to be the same
        friend bool operator==(const Entity& a, const Entity& b) { return a.id == b.id && a.gen == b.gen; }
        friend bool operator!=(const Entity& a, const Entity& b) { return !(a == b); }
        explicit operator bool() const { return id != 0; }
    };

    template <class T>
    class SparseSet {
    public:

        //Checks if entity is in the sparse set
        bool has(std::uint32_t entityId) const 
        {
            if (entityId >= sparse.size()) return false;
            std::uint32_t idx = sparse[entityId];
            return idx != kInvalid && denseEntities[idx] == entityId;
        }

        //Gets the component 
        T& get(std::uint32_t entityId) 
        {
            assert(has(entityId) && "Component not found");
            return dense[sparse[entityId]];
        }

        //constant version
        const T& get(std::uint32_t entityId) const 
        {
            assert(has(entityId) && "Component not found");
            return dense[sparse[entityId]];
        }

        //Add component
        template <class... Args>
        T& emplace(std::uint32_t entityId, Args&&... args) {
            if (entityId >= sparse.size()) sparse.resize(entityId + 1, kInvalid);

            if (has(entityId)) {
                dense[sparse[entityId]] = T{ std::forward<Args>(args)... };
                return dense[sparse[entityId]];
            }

            std::uint32_t idx = static_cast<std::uint32_t>(dense.size());
            dense.push_back(T{ std::forward<Args>(args)... });
            denseEntities.push_back(entityId);
            sparse[entityId] = idx;
            return dense.back();
        }

        //swap remove
        void remove(std::uint32_t entityId) 
        {
            if (!has(entityId)) return;

            std::uint32_t idx = sparse[entityId];
            std::uint32_t last = static_cast<std::uint32_t>(dense.size() - 1);

            if (idx != last) 
            {
                dense[idx] = std::move(dense[last]);
                std::uint32_t movedEntity = denseEntities[last];
                denseEntities[idx] = movedEntity;
                sparse[movedEntity] = idx;
            }

            dense.pop_back();
            denseEntities.pop_back();
            sparse[entityId] = kInvalid;
        }

        //for only looping the entities that have the component
        const std::vector<std::uint32_t>& entities() const { return denseEntities; }

    private:
        static constexpr std::uint32_t kInvalid = 0xFFFFFFFFu;

        std::vector<std::uint32_t> sparse;
        std::vector<std::uint32_t> denseEntities;
        std::vector<T> dense;
    };

    struct IComponentPool {
        virtual ~IComponentPool() = default;
        virtual void onEntityDestroyed(std::uint32_t entityId) = 0;
    };

    template <class T>
    class ComponentPool final : public IComponentPool {
    public:
        SparseSet<T> storage;

        void onEntityDestroyed(std::uint32_t entityId) override 
        {
            storage.remove(entityId);
        }
    };

    class Registry {
    public:
        Registry() 
        {
            gens.push_back(0);
            alive.push_back(false);
        }

        //create entity
        Entity create() 
        {
            std::uint32_t id;
            if (!free.empty()) 
            {
                id = free.back();
                free.pop_back();
                alive[id] = true;
            }
            else 
            {
                id = static_cast<std::uint32_t>(gens.size());
                gens.push_back(0);
                alive.push_back(true);
            }
            return Entity{ id, gens[id] };
        }

        //destroy entity
        void destroy(Entity e) 
        {
            if (!isAlive(e)) return;

            for (auto& [_, pool] : pools) 
            {
                pool->onEntityDestroyed(e.id);
            }

            alive[e.id] = false;
            gens[e.id]++;
            free.push_back(e.id);
        }

        bool isAlive(Entity e) const 
        {
            return e.id < alive.size() && alive[e.id] && gens[e.id] == e.gen;
        }

        //Add component
        template <class T, class... Args>
        T& emplace(Entity e, Args&&... args) 
        {
            assert(isAlive(e) && "emplace on dead entity");
            return pool<T>().storage.emplace(e.id, std::forward<Args>(args)...);
        }

        //check if has component
        template <class T>
        bool has(Entity e) const 
        {
            if (!isAlive(e)) return false;
            return pool<T>().storage.has(e.id);
        }

        //get the component to modify
        template <class T>
        T& get(Entity e) 
        {
            assert(isAlive(e) && "get on dead entity");
            return pool<T>().storage.get(e.id);
        }

        //get constant component to read
        template <class T>
        const T& get(Entity e) const 
        {
            assert(isAlive(e) && "get on dead entity");
            return pool<T>().storage.get(e.id);
        }

        //remove component from entity
        template <class T>
        void remove(Entity e) 
        {
            if (!isAlive(e)) return;
            pool<T>().storage.remove(e.id);
        }

        //Run lamda for each entity that has that component
        template <class... Cs, class Func>
        void each(Func&& fn) 
        {
            
            auto& base = pool<std::tuple_element_t<0, std::tuple<Cs...>>>().storage;
            for (std::uint32_t id : base.entities()) {
                Entity e{ id, gens[id] };
                if (!alive[id]) continue;

                if ((pool<Cs>().storage.has(id) && ...)) {
                    fn(e, pool<Cs>().storage.get(id)...);
                }
            }
        }

    private:
        
        //create storage for components
        template <class T>
        ComponentPool<T>& pool() const 
        {
            std::type_index ti(typeid(T));
            auto it = pools.find(ti);
            if (it == pools.end()) {
                auto created = std::make_unique<ComponentPool<T>>();
                auto* ptr = created.get();
                pools.emplace(ti, std::move(created));
                return *ptr;
            }
            return *static_cast<ComponentPool<T>*>(it->second.get());
        }

        mutable std::unordered_map<std::type_index, std::unique_ptr<IComponentPool>> pools;

        std::vector<std::uint32_t> gens;
        std::vector<bool> alive;
        std::vector<std::uint32_t> free;
    };
}