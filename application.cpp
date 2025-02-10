#include "application.h"

// libs to eventually remove
#include <cmath>
#include <chrono>

Vec3 fragmentShader(const Vec3 &barycentric, const Vec3 &fragPos, const Uniforms &uniforms) {
    Vec3 fragColor{ barycentric };

    double wave = sin(fragPos.x * 0.1 + uniforms.frameCount) * 0.5 + 0.5;

    return fragColor * wave;
}

Application::Application() {

}

Application::~Application() {

}

void Application::run() {
    Mat4 translationMat = translate({ 0.2, 0.3, 0.0 });
    Mat4 scaleMat = scale({ 1.0 });

    std::vector<Vec3> vertices = {
        {  0.0,  0.5, 0.0, },
        { -0.5, -0.5, 0.0, },
        {  0.5, -0.5, 0.0, }
    };

    for (Vec3 &vertex : vertices) {
        vertex = translationMat * scaleMat * vertex;
    }

    std::uint32_t frameCount = 0;

    while (true) {
        m_framebuffer.clear();

        Uniforms simpleUniforms{
            m_framebuffer.getWidth(),
            m_framebuffer.getHeight(),
            frameCount
        };
        frameCount++;

        m_rasterizer.drawTriangle(
            vertices,
            fragmentShader,
            simpleUniforms);

        clearTerminal();
        m_framebuffer.present();

        printDebugMessage();

        std::cin.get();
    }
}