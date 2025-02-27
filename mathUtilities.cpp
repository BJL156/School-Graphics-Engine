#include "mathUtilities.h"

namespace brayjl {
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
        Vec3 v0 = b - a;
        Vec3 v1 = c - a;
        Vec3 v2 = p - a;

        double d00 = dot(v0, v0);
        double d01 = dot(v0, v1);
        double d11 = dot(v1, v1);
        double d20 = dot(v2, v0);
        double d21 = dot(v2, v1);

        double denom = d00 * d11 - d01 * d01;
        double beta = (d20 * d11 - d21 * d01) / denom;
        double gamma = (d21 * d00 - d20 * d01) / denom;
        double alpha = 1.0 - beta - gamma;

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
}