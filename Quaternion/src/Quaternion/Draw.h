#pragma once

#include "Core.h"
#include "TextureTypes.h"

namespace QUA {

    class QUA_API Draw
    {
    public:

        virtual void drawText(std::string_view text, Vec2 pos, int fontSize, Colour colour) = 0;
        virtual void drawLine(Vec2 startPos, Vec2 endPos, float thickness, Colour colour) = 0;
        virtual void drawRect(Vec2 pos, Vec2 size, Colour colour) = 0;
        virtual void drawRect(Vec2 pos, Vec2 size, Vec2 pivotPoint, float rotation, Colour colour) = 0;
        virtual void drawCircle(Vec2 pos, float radius, Colour colour) = 0;

        static Draw* Create();
    };
}