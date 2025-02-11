#ifndef RASTERIZER_H
#define RASTERIZER_H

#include "vec3.h"
#include "framebuffer.h"
#include "uniformBuffer.h"

#include <vector>
#include <functional>
#include <cstdint>

class Rasterizer {
public:
    Rasterizer(Framebuffer &framebuffer);
    ~Rasterizer();

    void drawTriangle(
        const std::vector<Vec3> &vertices,
        std::function<Vec3(const Vec3 &, const UniformBuffer &)> vertexShader,
        std::function<Vec3(const Vec3 &, const Vec3 &, const UniformBuffer &)> fragmentShader,
        const UniformBuffer &uniformBuffer);
private:
    bool pointInTriangle(const Vec3 &point, const Vec3 &barycentric);

    Framebuffer &m_framebuffer;
};

#endif