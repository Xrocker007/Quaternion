#pragma once

#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>

#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

typedef struct Colour {
     float r;        // Color red value
     float g;        // Color green value
     float b;        // Color blue value
     float a;        // Color alpha value
} Colour;

typedef struct Vec2 {
    float x;                // Vector x component
    float y;                // Vector y component
} Vec2;