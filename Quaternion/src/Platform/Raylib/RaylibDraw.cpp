#pragma once
#include "pch.h"
#include "RaylibDraw.h"
#include "raylib.h"

namespace QUA {

	Draw* Draw::Create()
	{
		return new RaylibDraw();
	}

	//flip y as raylib has 0 at the top
	float flipY(float y)
	{
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
		DrawRectanglePro(Rectangle{ pos.x + pivotPoint.x, flipY(pos.y) + pivotPoint.y, size.x, size.y }, 
						Vector2{ size.x/2 +pivotPoint.x, size.y/2 + pivotPoint.y }, rotation, RaylibColor(colour));
	}

	void RaylibDraw::drawCircle(Vec2 pos, float radius, Colour colour)
	{
		DrawCircleV(Vector2{ pos.x, flipY(pos.y) }, radius, RaylibColor(colour));
	}

}