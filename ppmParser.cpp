#include "ppmParser.h"

namespace brayjl {
    Texture readPPM(const std::string &filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            throw std::runtime_error("Failed to open file: " + filename);
        }

        std::string line;
        std::getline(file, line);
        if (line != "P3") {
            throw std::runtime_error("PPM image isn't ASCII.");
        }

        std::getline(file, line);
        std::istringstream dimensions(line);
        int width, height;
        dimensions >> width >> height;

        std::getline(file, line);
        std::istringstream maxColor(line);
        int maxColorValue;
        maxColor >> maxColorValue;
        if (maxColorValue != 255) {
            throw std::runtime_error("PPM parser only supports a maximum value of 255.");
        }

        std::vector<Vec3> pixels;
        pixels.reserve(width * height);

        Vec3 pixel{ 0.0 };
        while (file >> pixel.x >> pixel.y >> pixel.z) {
            Vec3 normalizedPixel = { pixel.x / 255.0, pixel.y / 255.0, pixel.z / 255.0 };
            pixels.emplace_back(normalizedPixel);
        }

        file.close();

        Texture texture;
        texture.pixels = pixels;
        texture.width = width;
        texture.height = height;

        return texture;
    }
}