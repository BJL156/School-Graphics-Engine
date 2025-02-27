#ifndef ANSI_HANDLER
#define ANSI_HANDLER

#include "vec3.h"
#include "mathUtilities.h"

#include <string>
#include <iostream>

namespace brayjl {
    std::string getAnsiString(const Vec3 &color);

    void resetTerminal();

    void clearTerminal();
}

#endif