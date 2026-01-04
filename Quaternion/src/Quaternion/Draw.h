#pragma once

#include "pch.h"
#include "Core.h"

namespace QUA {

    class QUA_API Draw
    {
    public:
        virtual void drawText(std::string_view text, int x, int y, int fontSize, Colour colour) const = 0;
        virtual void drawLine(float x1, float y1, float x2, float y2, float thickness, Colour colour) const = 0;
        virtual void drawRect(float x, float y, float width, float height, Colour colour) const = 0;
        virtual void drawCircle(float x, float y, float radius, Colour colour) const = 0;

        //virtual void drawTexture(TextureHandle tex, int x, int y, Colour colour) const = 0;

        static Draw* Create();
    };
}