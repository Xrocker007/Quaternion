#include "pch.h"
#include "RaylibCamera2D.h"
#include"raylib.h"

namespace QUA {

    CameraManager* CameraManager::Create()
    {
        return new RaylibCamera2D();
    }

    ::Camera2D ToRaylibCam(const QUA::Camera2D& cam) {
        ::Camera2D camera{};
        camera.target = Vector2{ cam.getPos().y, -cam.getPos().x };
        camera.offset = Vector2{ cam.getOffset().x, cam.getOffset().y };
        camera.rotation = cam.getRotation();
        camera.zoom = cam.getZoom();
        return camera;
    }

    RaylibCamera2D::RaylibCamera2D()
    {

    }
    RaylibCamera2D::~RaylibCamera2D()
    {

    }

    void RaylibCamera2D::startCamera(QUA::Camera2D& cam)
    {
        BeginMode2D(ToRaylibCam(cam));
    }
    void RaylibCamera2D::endCamera()
    {
        EndMode2D();
    }
}