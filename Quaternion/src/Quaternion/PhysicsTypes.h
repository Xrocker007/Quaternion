#pragma once
#include "pch.h"

namespace QUA {

    //Will have to be changed if Box2D changed

    enum class BodyType : std::uint8_t {
        Static,
        Kinematic,
        Dynamic
    };

    struct BodyDef {
        BodyType type{ BodyType::Static };
        Vec2 position{ 0.0f, 0.0f };
        float angleRadians{ 0.0f };
        float linearDamping{ 0.0f };
        float angularDamping{ 0.0f };
        bool allowSleep{ true };
        bool awake{ true };
        bool fixedRotation{ false };
        bool bullet{ false };
        float gravityScale{ 1.0f };
    };

    struct ShapeProps {
        float friction{ 0.3f };
        float restitution{ 0.0f };
        float density{ 1.0f };
    };

    struct World { std::uint32_t value{}; };
    struct Body { std::uint32_t value{}; };
}
