#ifndef PPM_PARSER_H
#define PPM_PARSER_H

#include "vec3.h"
#include "texture.h"

#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>
#include <sstream>

namespace brayjl {
    Texture readPPM(const std::string &filename);
}

#endif