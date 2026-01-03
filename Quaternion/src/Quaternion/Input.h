#pragma once

#include "pch.h"
#include "Core.h"

namespace QUA {

    enum class Key : int
    {
        A, B, C, D, E, F, G, H, I,
        J, K, L, M, N, O, P, Q, R,
        S, T, U, V, W, X, Y, Z,

        ZERO, ONE, TWO, THREE, FOUR,
        FIVE, SIX, SEVEN, EIGHT, NINE,

        Space,
        Enter,
        Escape,
        Tab,
        Backspace,

        Left,
        Right,
        Up,
        Down,

        LeftShift,
        LeftCtrl,
        LeftAlt,

        RightShift,
        RightCtrl,
        RightAlt
    };

    enum class MouseButton : int
    {
        Left,
        Right,
        Middle,
        Side,
        Extra,
        Forward,
        Back
    };

    class QUA_API Input
    {
    public:
        //Keyboard
        virtual bool KeyDown(Key k) const = 0;
        virtual bool KeyUp(Key k) const = 0;
        virtual bool KeyPressed(Key k) const = 0;
        virtual bool KeyReleased(Key k) const = 0;

        //Mouse
        virtual bool MouseButtonDown(MouseButton b) const = 0;
        virtual bool MouseButtonPressed(MouseButton b) const = 0;
        virtual bool MouseButtonReleased(MouseButton b) const = 0;
        virtual bool MouseButtonUp(MouseButton b) const = 0;

        virtual int MousePosX() const = 0;
        virtual int MousePosY() const = 0;
        virtual float MouseWheelMove() const = 0;

        static Input* Create();
    };
}