#include "ansiUtilities.h"

std::string getAnsiString(const Vec3 &color) {
    Vec3 scaledColor = {
        clamp(color.x * 255.0, 0.0, 255.0),
        clamp(color.y * 255.0, 0.0, 255.0),
        clamp(color.z * 255.0, 0.0, 255.0)
    };

    std::string result = "\033[48;2;" +
        std::to_string(static_cast<int>(scaledColor.x)) + ";" +
        std::to_string(static_cast<int>(scaledColor.y)) + ";" +
        std::to_string(static_cast<int>(scaledColor.z)) + "m";

    return result;
}

void resetTerminal() {
    std::cout << "\033[0m";
}

void clearTerminal() {
    std::cout << "\033[2J\033[1;1H";
}