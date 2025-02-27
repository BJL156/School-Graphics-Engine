#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

#include "vec3.h"
#include "ansiUtilities.h"

#include <cstdint>
#include <limits>
#include <vector>
#include <string>
#include <iostream>

namespace brayjl {
    class Framebuffer {
    public:
        Framebuffer(
            const std::uint32_t &width,
            double aspectRatio);
        ~Framebuffer();

        void setPixel(
            const std::uint32_t &x,
            const std::uint32_t &y,
            const Vec3 &color,
            double depth);

        void clear();
        void present();

        const std::uint32_t getWidth() const;
        const std::uint32_t getHeight() const;
    private:
        void createColorAttachment(const std::uint32_t &pixelCount);
        void createDepthBuffer(const std::uint32_t &pixelCount);

        std::uint32_t getCorrectedHeight(
            const std::uint32_t &width,
            double aspectRatio);

        const std::uint32_t m_width;
        const std::uint32_t m_height;

        Vec3 m_clearColor = { 0.1, 0.1, 0.1 };

        std::vector<Vec3> m_colorAttachment;
        std::vector<double> m_depthBuffer;
    };
}

#endif