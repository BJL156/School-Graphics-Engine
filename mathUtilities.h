#ifndef UTILITIES_H
#define UTILITIES_H

#include "vec3.h"

#include <algorithm>

#define PI 3.14159265358979323846

namespace brayjl {
    double clamp(double d, double min, double max);

    double deg2rad(double degrees);

    Vec3 ndc2ScreenSpace(
        const Vec3 &ndc,
        const std::uint32_t &width,
        const std::uint32_t &height);

    Vec3 getBarycentricCoords(
        const Vec3 &p,
        const Vec3 &a,
        const Vec3 &b,
        const Vec3 &c);

    Vec3 getInterpolation(
        const Vec3 &a,
        const Vec3 &b,
        const Vec3 &c,
        const Vec3 &barycentric);
}

#endif