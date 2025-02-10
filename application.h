#ifndef APPLICATION_H
#define APPLICATION_H

#include "framebuffer.h"
#include "ansiUtilities.h"
#include "rasterizer.h"
#include "debugUtilities.h"

#include "mat4.h"
#include "transforms.h"

#include <cstdint>

class Application {
public:
    Application();
    ~Application();

    void run();
private:
    Framebuffer m_framebuffer{ 64, 16.0 / 9.0 };
    Rasterizer m_rasterizer{ m_framebuffer };
};

#endif