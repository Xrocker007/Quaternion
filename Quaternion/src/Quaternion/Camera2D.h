#include "pch.h"
#include "Core.h"

namespace QUA {

    class QUA_API Camera2D
    {
    public:

        Camera2D() {}
        ~Camera2D() {}

        void setPos(Vec2 pos)               { posVar = pos; }
        void setOffset(Vec2 screenOffset)   { offsetVar = screenOffset; }
        void setRotation(float degrees)     { rotationVar = degrees; }
        void setZoom(float zoom)            { zoomVar = zoom; }


        Vec2 getPos() const         { return posVar; }
        Vec2 getOffset() const      { return offsetVar; }
        float getRotation() const   { return rotationVar; }
        float getZoom() const       { return zoomVar; }

    private:
        Vec2  posVar{ 0, 0 };
        Vec2  offsetVar{ 0, 0 };
        float rotationVar{ 0.0f };
        float zoomVar{ 1.0f };

    };

}