#pragma once

#include "Quaternion/Physics.h"

#include "box2d/box2d.h"

namespace QUA {

	class Box2DPhysics : public Physics
	{
	public:
		Box2DPhysics();
		~Box2DPhysics();

        //World
        World createWorld(Vec2 gravity) override;
        void destroyWorld(World world) override;

        void step(World world, float timeStep, int velocityIterations = 8, int positionIterations = 3) override;

        void setGravity(World world, Vec2 gravity) override;
        Vec2 getGravity(World world) const override;

        //Bodies
        Body createBody(World world, const BodyDef& desc) override;
        void destroyBody(Body body) override;

        void setTransform(Body body, Vec2 pos, float angle) override;
        Vec2 getPosition(Body body) const override;
        float getAngle(Body body) const override;

        void setLinearVelocity(Body body, Vec2 v) override;
        Vec2 getLinearVelocity(Body body) const override;

        void applyForceToCenter(Body body, Vec2 force, bool wake) override;
        void applyLinearImpulseToCenter(Body body, Vec2 impulse, bool wake) override;

        void setAsBox(Body body, Vec2 size, const ShapeProps& shapeProps, bool isSensor) override;
        void setAsCircle(Body body, float radius, const ShapeProps& shapeProps, bool isSensor) override;

    private:
        b2World* worldPtr(World h) const {
            assert(h.value < worlds.size());
            assert(worlds[h.value] && "WorldHandle refers to destroyed world");
            return worlds[h.value].get();
        }

        b2Body* bodyPtr(Body h) const {
            assert(h.value < bodies.size());
            assert(bodies[h.value] && "BodyHandle refers to destroyed body");
            return bodies[h.value];
        }

        std::vector<std::unique_ptr<b2World>> worlds;
        std::vector<b2Body*> bodies;
    };
	
}
