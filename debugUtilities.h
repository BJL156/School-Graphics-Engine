#ifndef DEBUG_UTILITIES_H
#define DEBUG_UTILITIES_H

#include "framebuffer.h"

#include <iostream>
#include <cstdint>
#include <chrono>

void printWelcomeMessage(const Framebuffer &framebuffer);

void printDebugMessage();

#endif