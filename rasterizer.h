#ifndef RASTERIZER_H
#define RASTERIZER_H

#include "vec3.h"
#include "framebuffer.h"

#include <vector>
#include <functional>
#include <cstdint>

struct Uniforms {
    std::uint32_t width;
    std::uint32_t height;
    std::uint32_t frameCount;
};

class Rasterizer {
public:
    Rasterizer(Framebuffer &framebuffer);
    ~Rasterizer();

    void drawTriangle(
        const std::vector<Vec3> &vertices,
        std::function<Vec3(const Vec3 &, const Vec3 &, const Uniforms &)> fragmentShader,
        const Uniforms &uniforms);
private:
    bool pointInTriangle(const Vec3 &point, const Vec3 &barycentric);

    Framebuffer &m_framebuffer;
};

#endif