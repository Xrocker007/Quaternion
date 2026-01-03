#pragma once
#include "pch.h"
#include "RaylibInput.h"

namespace QUA {

    Input* Input::Create()
    {
        return new RaylibInput();
    }

    int RaylibKey(Key k) {

        switch (k)
        {
        case Key::A: return KEY_A; case Key::B: return KEY_B; case Key::C: return KEY_C;
        case Key::D: return KEY_D; case Key::E: return KEY_E; case Key::F: return KEY_F;
        case Key::G: return KEY_G; case Key::H: return KEY_H; case Key::I: return KEY_I;
        case Key::J: return KEY_J; case Key::K: return KEY_K; case Key::L: return KEY_L;
        case Key::M: return KEY_M; case Key::N: return KEY_N; case Key::O: return KEY_O;
        case Key::P: return KEY_P; case Key::Q: return KEY_Q; case Key::R: return KEY_R;
        case Key::S: return KEY_S; case Key::T: return KEY_T; case Key::U: return KEY_U;
        case Key::V: return KEY_V; case Key::W: return KEY_W; case Key::X: return KEY_X;
        case Key::Y: return KEY_Y; case Key::Z: return KEY_Z;

        case Key::ZERO:  return KEY_ZERO; case Key::ONE:   return KEY_ONE; case Key::TWO:   return KEY_TWO;
        case Key::THREE: return KEY_THREE; case Key::FOUR:  return KEY_FOUR; case Key::FIVE:  return KEY_FIVE;
        case Key::SIX:   return KEY_SIX; case Key::SEVEN: return KEY_SEVEN; case Key::EIGHT: return KEY_EIGHT; 
        case Key::NINE:  return KEY_NINE;

        case Key::Space:     return KEY_SPACE;
        case Key::Enter:     return KEY_ENTER;
        case Key::Escape:    return KEY_ESCAPE;
        case Key::Tab:       return KEY_TAB;
        case Key::Backspace: return KEY_BACKSPACE;

        case Key::Left:  return KEY_LEFT;
        case Key::Right: return KEY_RIGHT;
        case Key::Up:    return KEY_UP;
        case Key::Down:  return KEY_DOWN;

        case Key::LeftShift: return KEY_LEFT_SHIFT;
        case Key::LeftCtrl:  return KEY_LEFT_CONTROL;
        case Key::LeftAlt:   return KEY_LEFT_ALT;

        case Key::RightShift: return KEY_RIGHT_SHIFT;
        case Key::RightCtrl:  return KEY_RIGHT_CONTROL;
        case Key::RightAlt:   return KEY_RIGHT_ALT;

        default: return KEY_NULL;
        }
    }

    int RaylibMouse(MouseButton b) {
        switch (b) {
        case MouseButton::Left: return MOUSE_BUTTON_LEFT;
        case MouseButton::Right: return MOUSE_BUTTON_RIGHT;
        case MouseButton::Middle: return MOUSE_BUTTON_MIDDLE;
        case MouseButton::Side: return MOUSE_BUTTON_SIDE;
        case MouseButton::Extra: return MOUSE_BUTTON_EXTRA;
        case MouseButton::Forward: return MOUSE_BUTTON_FORWARD;
        case MouseButton::Back: return MOUSE_BUTTON_BACK;
        default: return 0;
        }
    }

	RaylibInput::RaylibInput()
	{

	}

	RaylibInput::~RaylibInput()
	{

	}

    //Keyboard
    bool RaylibInput::KeyDown(Key k) const
    { 
        return IsKeyDown(RaylibKey(k));
    }
    bool RaylibInput::KeyUp(Key k) const
    { 
        return IsKeyUp(RaylibKey(k));
    }
    bool RaylibInput::KeyPressed(Key k) const
    { 
        return IsKeyPressed(RaylibKey(k));
    }
    bool RaylibInput::KeyReleased(Key k) const
    { 
        return IsKeyReleased(RaylibKey(k));
    }


    //Mouse
    bool RaylibInput::MouseButtonDown(MouseButton b) const
    { 
        return IsMouseButtonDown(RaylibMouse(b));
    }
    bool RaylibInput::MouseButtonPressed(MouseButton b) const
    { 
        return IsMouseButtonPressed(RaylibMouse(b));
    }
    bool RaylibInput::MouseButtonReleased(MouseButton b) const
    { 
        return IsMouseButtonReleased(RaylibMouse(b));
    }
    bool RaylibInput::MouseButtonUp(MouseButton b) const
    { 
        return IsMouseButtonUp(RaylibMouse(b));
    }

    int RaylibInput::MousePosX() const
    { 
        return GetMouseX(); 
    }
    int RaylibInput::MousePosY() const
    { 
        return GetMouseY();
    }
    float RaylibInput::MouseWheelMove() const
    { 
        return GetMouseWheelMove(); 
    }
}