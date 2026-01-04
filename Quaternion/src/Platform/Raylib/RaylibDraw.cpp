#pragma once
#include "pch.h"
#include "RaylibDraw.h"

namespace QUA {

	Draw* Draw::Create()
	{
		return new RaylibDraw();
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

	void RaylibDraw::drawText(std::string_view text, int x, int y, int fontSize, Colour colour) const
	{
		std::string s(text);
		DrawText(s.c_str(), x, y, fontSize, RaylibColor(colour));
	}

	void RaylibDraw::drawLine(float x1, float y1, float x2, float y2, float thickness, Colour colour) const
	{
		DrawLineEx(Vector2 {x1, y1}, Vector2 {x2, y2}, thickness, RaylibColor(colour));
	}

	void RaylibDraw::drawRect(float x, float y, float width, float height, Colour colour) const
	{
		DrawRectangleRec(Rectangle{x, y, width, height}, RaylibColor(colour));
	}

	void RaylibDraw::drawCircle(float x, float y, float radius, Colour colour) const
	{
		DrawCircleV(Vector2{ x, y }, radius, RaylibColor(colour));
	}

	/*void drawTexture(TextureHandle tex, float x, float y, Colour colour) const
	{
		DrawTextureV(tex, Vector2{ x, y }, RaylibColor(colour));
	}*/

}