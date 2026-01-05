#pragma once
#include "pch.h"
#include "Core.h"
#include "Camera2D.h"

namespace QUA {

    class QUA_API CameraManager
    {
    public:

        virtual void startCamera(QUA::Camera2D& cam) = 0;
        virtual void endCamera() = 0;

        static CameraManager* Create();
    };

}