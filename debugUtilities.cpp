#include "debugUtilities.h"

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