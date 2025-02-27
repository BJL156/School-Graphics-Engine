#ifndef VEC3_H
#define VEC3_H

#include <stdexcept>
#include <cmath>

namespace brayjl {
    struct Vec3 {
        Vec3();
        Vec3(double x);
        Vec3(double x, double y, double z);
        ~Vec3() = default;

        double x = 0.0;
        double y = 0.0;
        double z = 0.0;
    };

    Vec3 operator+(const Vec3 &v0, const Vec3 &v1);
    Vec3 operator-(const Vec3 &v0, const Vec3 &v1);
    Vec3 operator*(const Vec3 &v0, const Vec3 &v1);
    Vec3 operator/(const Vec3 &v0, const Vec3 &v1);
    Vec3 operator+(double t, const Vec3 &v0);
    Vec3 operator-(double t, const Vec3 &v0);
    Vec3 operator*(double t, const Vec3 &v0);
    Vec3 operator/(double t, const Vec3 &v0);
    Vec3 operator+(const Vec3 &v0, double t);
    Vec3 operator-(const Vec3 &v0, double t);
    Vec3 operator*(const Vec3 &v0, double t);
    Vec3 operator/(const Vec3 &v0, double t);
    Vec3 operator-(const Vec3 &v0);

    double dot(const Vec3 &v0, const Vec3 &v1);
    double lengthSquared(const Vec3 &v0);
    double length(const Vec3 &v0);
    Vec3 normalize(const Vec3 &v0);
    Vec3 cross(const Vec3 &v0, const Vec3 &v1);
}

#endif