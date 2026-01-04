#pragma once

#include "raylib.h"
#include "Quaternion/Draw.h"

namespace QUA {

	class RaylibDraw : public Draw
	{
	public:
		RaylibDraw();
		~RaylibDraw();

		void drawText(std::string_view text, int x, int y, int fontSize, Colour colour) const override;
		void drawLine(float x1, float y1, float x2, float y2, float thickness, Colour colour) const override;
		void drawRect(float x, float y, float width, float height, Colour colour) const override;
		void drawCircle(float x, float y, float radius, Colour colour) const override;
		
		//void drawTexture(TextureHandle tex, int x, int y, unsigned int hexColour)
	};

}