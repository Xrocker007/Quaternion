#pragma once

#include "raylib.h"
#include "Quaternion/Draw.h"

namespace QUA {

	class RaylibDraw : public Draw
	{
	public:
		RaylibDraw();
		~RaylibDraw();

		void drawText(std::string_view text, Vec2 pos, int fontSize, Colour colour) override;
		void drawLine(Vec2 startPos, Vec2 endPos, float thickness, Colour colour) override;
		void drawRect(Vec2 pos, Vec2 size, Colour colour) override;
		void drawRect(Vec2 pos, Vec2 size, Vec2 pivotPoint, float rotation, Colour colour) override;
		void drawCircle(Vec2 pos, float radius, Colour colour) override;
		
		//void drawTexture(Texture2D tex, Vec2 pos, Colour colour) const override;
		//void drawTexture(Texture2D tex, Vec2 pos, Vec2 size, Vec2 UV1, Vec2 UV2, Vec2 pivotPoint, float rotation, Colour colour) const override;
	};

}