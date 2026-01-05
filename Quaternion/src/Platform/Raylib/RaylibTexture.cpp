#include "pch.h"
#include "RaylibTexture.h"

namespace QUA {

	TextureManager* TextureManager::Create()
	{
		return new RaylibTexture();
	}

	RaylibTexture::RaylibTexture()
	{

	}
	RaylibTexture::~RaylibTexture()
	{

	}

	TextureHandle RaylibTexture::load(std::string_view pathSv)
	{
		std::string path(pathSv);

		//If already loaded 
		auto it = pathToHandle.find(path);
		if (it != pathToHandle.end()) {
			TextureHandle h{ it->second };
			auto& e = entry(h);
			e.refCount++;
			return h;
		}

		//Load from disk
		::Texture2D t = LoadTexture(path.c_str());
		if (t.id == 0) {
			//Load failed
			return TextureHandle::Invalid();
		}

		//Allocate a handle
		std::uint32_t slot = allocateSlot();
		Entry& e = entries[slot - 1];
		e.tex = t;
		e.refCount = 1;
		e.path = path;
		e.alive = true;

		pathToHandle[path] = slot;
		return TextureHandle{ slot };
	}
	void RaylibTexture::release(TextureHandle h)
	{
		//if invalid
		if (!h) return;

		Entry& e = entry(h);
		if (!e.alive) return;

		e.refCount--;
		//If last ref
		if (e.refCount <= 0) {
			//Remove handle
			if (!e.path.empty()) {
				auto it = pathToHandle.find(e.path);
				if (it != pathToHandle.end() && it->second == h.value) {
					pathToHandle.erase(it);
				}
			}

			//Unload texture
			UnloadTexture(e.tex);

			//Mark slot free
			e = Entry{};
			freeList.push_back(h.value);
		}
	}

	void RaylibTexture::unloadAll()
	{
		//for all entries unload them
		for (std::uint32_t i = 0; i < entries.size(); ++i) {
			Entry& e = entries[i];
			if (e.alive) {
				UnloadTexture(e.tex);
				e = Entry{};
			}
		}
		pathToHandle.clear();
		freeList.clear();
	}

	//flip y as raylib has 0 at the top
	float flipYTex(float y)
	{
		return GetScreenHeight() - y;
	}

	Color RaylibTexColor(Colour colour)
	{
		return ColorFromNormalized(Vector4{ colour.r, colour.g, colour.b, colour.a });
	}

	void RaylibTexture::drawTexture(TextureHandle tex, Vec2 pos, Vec2 size, Vec2 UV1, Vec2 UV2, Colour colour)
	{
		Texture2D raylibTex = getRaylibTexture(tex);

		Vector2 uv1 = Vector2{ UV1.x * raylibTex.width, UV1.y * raylibTex.height };
		Vector2 uv2 = Vector2{ UV2.x * raylibTex.width, UV2.y * raylibTex.height };

		DrawTexturePro(raylibTex, Rectangle{ uv1.x, uv1.y, uv2.x - uv1.x, uv2.y - uv1.y },
			Rectangle{ pos.x - size.x / 2, flipYTex(pos.y) - size.y / 2, size.x, size.y },
			Vector2{0, 0}, 0, RaylibTexColor(colour));
	}

	void RaylibTexture::drawTexture(TextureHandle tex, Vec2 pos, Vec2 size, Vec2 UV1, Vec2 UV2, Vec2 pivotPoint, float rotation, Colour colour)
	{
		Texture2D raylibTex = getRaylibTexture(tex);

		Vector2 uv1 = Vector2{ UV1.x * raylibTex.width, UV1.y * raylibTex.height};
		Vector2 uv2 = Vector2{ UV2.x * raylibTex.width, UV2.y * raylibTex.height};

		DrawTexturePro(raylibTex, Rectangle{ uv1.x, uv1.y, uv2.x - uv1.x, uv2.y - uv1.y }, 
			Rectangle { pos.x + pivotPoint.x, flipYTex(pos.y) + pivotPoint.y, size.x, size.y },
			Vector2{ size.x / 2 + pivotPoint.x, size.y / 2 + pivotPoint.y }, rotation, RaylibTexColor(colour));
	}
}