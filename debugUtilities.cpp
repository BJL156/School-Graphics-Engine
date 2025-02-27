#include "debugUtilities.h"

namespace brayjl {
    void printWelcomeMessage(const Framebuffer &framebuffer) {
        char chr = '#';

        for (std::uint32_t y = 0; y < framebuffer.getHeight(); ++y) {
            for (std::uint32_t x = 0; x < framebuffer.getWidth(); ++x) {
                std::cout << chr << chr;
            }
            std::cout << '\n';
        }

        std::cout << "Resize until the " << chr << "s create a rectangle. Then press enter to start rendering...\n";
        std::cin.get();
    }

    void printDebugMessage() {
        static std::uint32_t frameCount = 0;
        static std::uint32_t totalFrameCount = 0;
        static auto lastFrameTime = std::chrono::high_resolution_clock::now();
        static double fps = 0.0;

        frameCount++;
        auto currentFrameTime = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsedTime = currentFrameTime - lastFrameTime;

        if (elapsedTime.count() > 1.0) {
            fps = frameCount / elapsedTime.count();

            frameCount = 0;
            lastFrameTime = currentFrameTime;
        }

        totalFrameCount++;
        std::cout <<
            "Frame count: " << totalFrameCount << ' ' <<
            "FPS: " << fps << '\n';
    }
}