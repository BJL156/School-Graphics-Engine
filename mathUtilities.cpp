#include "mathUtilities.h"

double clamp(double d, double min, double max) {
    return std::max(min, std::min(d, max));
}

double deg2rad(double degrees) {
    return degrees * (PI / 180.0);
}

Vec3 ndc2ScreenSpace(
    const Vec3 &ndc,
    const std::uint32_t &width,
    const std::uint32_t &height) {
    return {
        (ndc.x + 1.0) * 0.5 * width,
        (1.0 - ndc.y) * 0.5 * height,
        0.0
    };
}

Vec3 getBarycentricCoords(
    const Vec3 &p,
    const Vec3 &a,
    const Vec3 &b,
    const Vec3 &c) {
    double det = (b.y - c.y) * (a.x - c.x) + (c.x - b.x) * (a.y - c.y);
    double factorAlpha = (b.y - c.y) * (p.x - c.x) + (c.x - b.x) * (p.y - c.y);
    double factorBeta = (c.y - a.y) * (p.x - c.x) + (a.x - c.x) * (p.y - c.y);
    double alpha = factorAlpha / det;
    double beta = factorBeta / det;

    double gamma = 1.0 - alpha - beta;

    return { alpha, beta, gamma };
}

Vec3 getInterpolation(
    const Vec3 &a,
    const Vec3 &b,
    const Vec3 &c,
    const Vec3 &barycentric) {
    return {
    a.x * barycentric.x + b.x * barycentric.y + c.x * barycentric.z,
    a.y * barycentric.x + b.y * barycentric.y + c.y * barycentric.z,
    a.z * barycentric.x + b.z * barycentric.y + c.z * barycentric.z
    };
}