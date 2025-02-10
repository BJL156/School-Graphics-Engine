#include "rasterizer.h"

Rasterizer::Rasterizer(Framebuffer &framebuffer)
    : m_framebuffer(framebuffer) {

}

Rasterizer::~Rasterizer() {

}

void Rasterizer::drawTriangle(
    const std::vector<Vec3> &vertices,
    std::function<Vec3(const Vec3 &, const Vec3 &, const Uniforms &)> fragmentShader,
    const Uniforms &uniforms) {
    if (vertices.size() != 3) {
        throw std::runtime_error("Triangles must have 3 vertices.");
    }

    const std::uint32_t width = m_framebuffer.getWidth();
    const std::uint32_t height = m_framebuffer.getHeight();

    std::vector<Vec3> ssVertices(vertices.size());
    for (std::size_t i = 0; i < vertices.size(); ++i) {
        ssVertices[i] = ndc2ScreenSpace(vertices[i], width, height);
    }

    int minX = static_cast<int>(clamp(std::floor(std::min({ ssVertices[0].x, ssVertices[1].x, ssVertices[2].x })), 0.0, width - 1));
    int maxX = static_cast<int>(clamp(std::ceil(std::max({ ssVertices[0].x, ssVertices[1].x, ssVertices[2].x })), 0.0, width - 1));
    int minY = static_cast<int>(clamp(std::floor(std::min({ ssVertices[0].y, ssVertices[1].y, ssVertices[2].y })), 0.0, height - 1));
    int maxY = static_cast<int>(clamp(std::ceil(std::max({ ssVertices[0].y, ssVertices[1].y, ssVertices[2].y })), 0.0, height - 1));

    for (int y = minY; y <= maxY; ++y) {
        for (int x = minX; x <= maxX; ++x) {
            Vec3 currentPixel = {
                static_cast<double>(x),
                static_cast<double>(y),
                0
            };

            Vec3 barycentric = getBarycentricCoords(
                currentPixel,
                ssVertices[0],
                ssVertices[1],
                ssVertices[2]);

            if (pointInTriangle(currentPixel, barycentric)) {
                Vec3 color = fragmentShader(barycentric, currentPixel, uniforms);
                m_framebuffer.setPixel(currentPixel.x, currentPixel.y, color);
            }
        }
    }
}

bool Rasterizer::pointInTriangle(const Vec3 &point, const Vec3 &barycentric) {
    const double epsilon = 1.0e-5;
    return
        barycentric.x >= -epsilon &&
        barycentric.y >= -epsilon &&
        barycentric.z >= -epsilon;
}