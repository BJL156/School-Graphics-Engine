#include "application.h"

// libs to eventually remove
#include <cmath>
#include <chrono>

Vec3 vertexShader(const Vec3 &vertex, const UniformBuffer &uniformBuffer) {
    Vec3 position = uniformBuffer.projMat * uniformBuffer.modelMat * vertex;

    return position;
}

Vec3 fragmentShader(const Vec3 &barycentric, const Vec3 &fragPos, const UniformBuffer &uniformBuffer) {
    Vec3 fragColor{ barycentric };

    return fragColor;
}

Application::Application() {
    printWelcomeMessage(m_framebuffer);
}

Application::~Application() {

}

void Application::run() {
    std::vector<Vec3> vertices = {
        {  0.0,  0.5, 0.0, },
        { -0.5, -0.5, 0.0, },
        {  0.5, -0.5, 0.0, }
    };

    std::uint32_t frameCount = 0;
    while (true) {
        m_framebuffer.clear();

        Mat4 modelMat = getModelMat(
            { 0.0, 0.0, -2.0 },
            { 1.0 },
            { 0.0, 0.1 * frameCount, 0.1 * frameCount });
        Mat4 projMat = perspective(
            deg2rad(45.0),
            static_cast<double>(m_framebuffer.getWidth()) / m_framebuffer.getHeight(),
            0.01,
            100.0);

        UniformBuffer uniformBuffer{
            m_framebuffer.getWidth(),
            m_framebuffer.getHeight(),
            frameCount,
            modelMat,
            projMat
        };
        frameCount++;

        m_rasterizer.drawTriangle(
            vertices,
            vertexShader,
            fragmentShader,
            uniformBuffer);

        modelMat = getModelMat(
            { -0.3, 0.0, -3.0 },
            { 1.0 },
            { 0.1 * frameCount, 0.0, 0.0 });
        uniformBuffer.modelMat = modelMat;
        m_rasterizer.drawTriangle(
            vertices,
            vertexShader,
            fragmentShader,
            uniformBuffer);

        clearTerminal();
        m_framebuffer.present();

        printDebugMessage();

        std::cin.get();
    }
}