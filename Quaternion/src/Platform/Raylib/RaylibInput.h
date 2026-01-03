#pragma once

#include "raylib.h"
#include "Quaternion/Input.h"

namespace QUA {

    class RaylibInput : public Input
    {
    public:

        RaylibInput();
        ~RaylibInput();

        //Keyboard
        bool KeyDown(Key k) const override;
        bool KeyUp(Key k) const override;
        bool KeyPressed(Key k) const override;
        bool KeyReleased(Key k) const override;


        //Mouse
        bool MouseButtonDown(MouseButton b) const override;
        bool MouseButtonPressed(MouseButton b) const override;
        bool MouseButtonReleased(MouseButton b) const override;
        bool MouseButtonUp(MouseButton b) const override;

        int MousePosX() const override;
        int MousePosY() const override;
        float   MouseWheelMove() const override;

    };
}