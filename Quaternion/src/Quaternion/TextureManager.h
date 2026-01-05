#pragma once

#include "Core.h"
#include "TextureTypes.h"

namespace QUA {

    class QUA_API TextureManager
    {
    public:

        virtual TextureHandle load(std::string_view path) = 0;
        virtual void release(TextureHandle h) = 0;
        virtual void unloadAll() = 0;

        virtual void drawTexture(TextureHandle  tex, Vec2 pos, Vec2 size, Vec2 UV1, Vec2 UV2, Colour colour) = 0;
        virtual void drawTexture(TextureHandle  tex, Vec2 pos, Vec2 size, Vec2 UV1, Vec2 UV2, Vec2 pivotPoint, float rotation, Colour colour) = 0;


        static TextureManager* Create();
    };
}