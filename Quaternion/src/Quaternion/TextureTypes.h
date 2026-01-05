#pragma once
#include "pch.h"

namespace QUA {

    struct TextureHandle {
        std::uint32_t value{ 0 };
        static constexpr TextureHandle Invalid() { return TextureHandle{ 0 }; }
        explicit constexpr operator bool() const { return value != 0; }
    };

}