#ifndef DEBUG_UTILITIES_H
#define DEBUG_UTILITIES_H

#include "framebuffer.h"

#include <iostream>
#include <cstdint>
#include <chrono>

namespace brayjl {
    void printWelcomeMessage(const Framebuffer &framebuffer);

    void printDebugMessage();
}

#endif