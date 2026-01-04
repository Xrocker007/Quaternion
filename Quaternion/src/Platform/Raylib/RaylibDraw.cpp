#pragma once
#include "pch.h"
#include "RaylibDraw.h"

namespace QUA {

	Draw* Draw::Create()
	{
		return new RaylibDraw();
	}

	float flipY(float y)
	{
		//return y;
		return GetScreenHeight() - y;
	}

    Color RaylibColor(Colour colour)
	{
		return ColorFromNormalized(Vector4{ colour.r, colour.g, colour.b, colour.a });
    }

	RaylibDraw::RaylibDraw()
	{

	}

	RaylibDraw::~RaylibDraw()
	{

	}

	void RaylibDraw::drawText(std::string_view text, Vec2 pos, int fontSize, Colour colour)
	{
		std::string s(text);
		DrawText(s.c_str(), pos.x, flipY(pos.y), fontSize, RaylibColor(colour));
	}

	void RaylibDraw::drawLine(Vec2 startPos, Vec2 endPos, float thickness, Colour colour)
	{
		DrawLineEx(Vector2 { startPos.x, flipY(startPos.y)}, Vector2 { endPos.x, flipY(endPos.y)}, thickness, RaylibColor(colour));
	}

	void RaylibDraw::drawRect(Vec2 pos, Vec2 size, Colour colour)
	{
		DrawRectangleV(Vector2{ pos.x - size.x/2, flipY(pos.y) - size.y/2 }, Vector2{size.x, size.y}, RaylibColor(colour));
	}

	void RaylibDraw::drawRect(Vec2 pos, Vec2 size, Vec2 pivotPoint, float rotation, Colour colour)
	{
		DrawRectanglePro(Rectangle{ pos.x - size.x/2 + size.x / 2 + pivotPoint.x, flipY(pos.y) - size.y/2 + size.y / 2 + pivotPoint.y, size.x, size.y }, Vector2{ size.x/2 +pivotPoint.x, size.y/2 + pivotPoint.y}, rotation, RaylibColor(colour));
	}

	void RaylibDraw::drawCircle(Vec2 pos, float radius, Colour colour)
	{
		DrawCircleV(Vector2{ pos.x, flipY(pos.y) }, radius, RaylibColor(colour));
	}

	/*void RaylibDraw::drawTexture(Texture2D tex, Vec2 pos, Colour colour)
	{
		DrawTextureV(tex, Vector2{ pos.x, flipY(pos.y) }, RaylibColor(colour));
	}

	void RaylibDraw::drawTexture(Texture2D tex, Vec2 pos, Vec2 size, Vec2 UV1, Vec2 UV2, Vec2 pivotPoint, float rotation, Colour colour)
	{
		Vector2 uv1 = Vector2{ UV1.x * tex.width, UV1.y * tex.height};
		Vector2 uv2 = Vector2{ UV2.x * tex.width, UV2.y * tex.height};

		DrawTexturePro(tex, Rectangle{ UV1.x, UV2.y, UV2.x, UV2.y }, Rectangle { pos.x, flipY(pos.y), size.x, size.y },
			Vector2{ pivotPoint.x, pivotPoint.y }, rotation, RaylibColor(colour));
	}*/

}