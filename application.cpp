#include "application.h"

#include <cmath>
#include <chrono>

namespace brayjl {
    Vec3 vertexShader(const Vec3 &vertex, const UniformBuffer &uniformBuffer) {
        Vec3 position = uniformBuffer.projMat * uniformBuffer.modelMat * vertex;

        return position;
    }

    Vec3 fragmentShader(const Vec3 &barycentric, const Vec3 &fragPos, const UniformBuffer &uniformBuffer) {
        double u = clamp(barycentric.x * 0.0 + barycentric.y * 1.0 + barycentric.z * 0.0, 0.0, 1.0);
        double v = clamp(barycentric.x * 0.0 + barycentric.y * 0.0 + barycentric.z * 1.0, 0.0, 1.0);

        int textureX = static_cast<int>(u * uniformBuffer.texture.width);
        int textureY = static_cast<int>(v * uniformBuffer.texture.height);

        Vec3 finalColor = uniformBuffer.texture.pixels[textureY * uniformBuffer.texture.width + textureX];

        return finalColor;
    }

    double getDeltaTime() {
        static auto previousFrameTime = std::chrono::high_resolution_clock::now();
        auto currentFrameTime = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> duration = currentFrameTime - previousFrameTime;
        double deltaTime = duration.count();

        previousFrameTime = currentFrameTime;

        return deltaTime;
    }

    Application::Application() {

    }

    Application::~Application() {

    }

    void Application::run() {
        printWelcomeMessage(m_framebuffer);
        clearTerminal();

        std::string textureFilepath = "resources/texture.ppm";
        std::cout << "Loading texture: " << textureFilepath << "...\n";
        Texture texture = readPPM(textureFilepath);
        std::cout << "Successfully loaded texture: " << textureFilepath << '\n';

        std::vector<Vec3> vertices = {
            {  0.0,  0.5, 0.0, },
            { -0.5, -0.5, 0.0, },
            {  0.5, -0.5, 0.0, }
        };

        clearTerminal();
        std::cout << "\033[?25l";

        double rotationSpeed = 2.5;
        double tri0Angle = 0.0;
        double tri1Angle = 0.0;

        std::uint32_t frameCount = 0;
        while (true) {
            double deltaTime = getDeltaTime();

            tri0Angle += rotationSpeed * deltaTime;
            tri1Angle += rotationSpeed * deltaTime;

            m_framebuffer.clear();

            Mat4 modelMat = getModelMat(
                { 0.0, 0.0, -2.0 },
                { 1.0 },
                { 0.0, tri0Angle, tri0Angle });
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
                projMat,
                texture
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
                { tri1Angle, 0.0, 0.0 });
            uniformBuffer.modelMat = modelMat;
            m_rasterizer.drawTriangle(
                vertices,
                vertexShader,
                fragmentShader,
                uniformBuffer);

            std::cout << "\033[1;1H";
            m_framebuffer.present();

            std::cout << '\n';
            printDebugMessage();
        }

        std::cout << "\033[?25h";
    }
}