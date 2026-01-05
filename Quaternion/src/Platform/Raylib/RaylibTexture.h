#pragma once

#include "raylib.h"
#include "Quaternion/TextureManager.h"


namespace QUA {

    struct Entry {
        ::Texture2D tex{};
        int refCount{ 0 };
        std::string path;
        bool alive{ false };
    };

	class RaylibTexture : public TextureManager
	{
	public:
        RaylibTexture();
		~RaylibTexture();

		 TextureHandle load(std::string_view path) override;
		 void release(TextureHandle h) override;
		 void unloadAll() override;

         void drawTexture(TextureHandle tex, Vec2 pos, Vec2 size, Vec2 UV1, Vec2 UV2, Colour colour) override;
         void drawTexture(TextureHandle tex, Vec2 pos, Vec2 size, Vec2 UV1, Vec2 UV2, Vec2 pivotPoint, float rotation, Colour colour) override;

         const ::Texture2D& getRaylibTexture(TextureHandle h) const {
             return entryConst(h).tex;
         }

    private:

         std::uint32_t allocateSlot() {
             //use old freed slots first
             if (!freeList.empty()) {
                 std::uint32_t h = freeList.back();
                 freeList.pop_back();
                 return h;
             }
             entries.push_back(Entry{});
             return static_cast<std::uint32_t>(entries.size());
         }

         //return entry if there
         Entry& entry(TextureHandle h) {
             assert(h.value >= 1 && h.value <= entries.size());
             Entry& e = entries[h.value - 1];
             assert(e.alive && "TextureHandle refers to unloaded texture");
             return e;
         }

         const Entry& entryConst(TextureHandle h) const {
             assert(h.value >= 1 && h.value <= entries.size());
             const Entry& e = entries[h.value - 1];
             assert(e.alive && "TextureHandle refers to unloaded texture");
             return e;
         }

    
        std::unordered_map<std::string, std::uint32_t> pathToHandle;
        std::vector<Entry> entries;
        std::vector<std::uint32_t> freeList;
	};

}
