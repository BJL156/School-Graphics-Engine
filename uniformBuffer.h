#ifndef UNIFORM_BUFFER_H
#define UNIFORM_BUFFER_H

#include "mat4.h"
#include "texture.h"

#include <cstdint>

namespace brayjl {
    struct UniformBuffer {
        std::uint32_t width;
        std::uint32_t height;
        std::uint32_t frameCount;
        Mat4 modelMat;
        Mat4 projMat;
        Texture texture;
    };
}

#endif