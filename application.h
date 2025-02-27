#ifndef APPLICATION_H
#define APPLICATION_H

#include "framebuffer.h"
#include "ansiUtilities.h"
#include "rasterizer.h"
#include "uniformBuffer.h"
#include "debugUtilities.h"
#include "ppmParser.h"
#include "mat4.h"
#include "transforms.h"
#include "texture.h"

#include <cstdint>
#include <chrono>

namespace brayjl {
    class Application {
    public:
        Application();
        ~Application();

        void run();
    private:
        Framebuffer m_framebuffer{ 64, 4.0 / 3.0 };
        Rasterizer m_rasterizer{ m_framebuffer };
    };
}

#endif