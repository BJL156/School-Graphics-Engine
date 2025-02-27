#ifndef TEXTURE_H
#define TEXTURE_H

#include "vec3.h"

#include <vector>
#include <cstdint>

namespace brayjl {
    struct Texture {
        std::vector<Vec3> pixels;
        std::uint32_t width;
        std::uint32_t height;
    };
}

#endif