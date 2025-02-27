#include "vec3.h"

namespace brayjl {
    Vec3::Vec3()
        : x(0.0), y(0.0), z(0.0) {

    }

    Vec3::Vec3(double x)
        : x(x), y(x), z(x) {

    }

    Vec3::Vec3(double x, double y, double z)
        : x(x), y(y), z(z) {

    }

    Vec3 operator+(const Vec3 &v0, const Vec3 &v1) {
        return { v0.x + v1.x, v0.y + v1.y, v0.z + v1.z };
    }

    Vec3 operator-(const Vec3 &v0, const Vec3 &v1) {
        return { v0.x - v1.x, v0.y - v1.y, v0.z - v1.z };
    }

    Vec3 operator*(const Vec3 &v0, const Vec3 &v1) {
        return { v0.x * v1.x, v0.y * v1.y, v0.z * v1.z };
    }

    Vec3 operator/(const Vec3 &v0, const Vec3 &v1) {
        if (v1.x == 0 || v1.y == 0 || v1.z == 0) {
            throw std::runtime_error("Can't divide by zero.");
        }

        return { v0.x / v1.x, v0.y / v1.y, v0.z / v1.z };
    }

    Vec3 operator+(double t, const Vec3 &v0) {
        return { t + v0.x, t + v0.y, t + v0.z };
    }

    Vec3 operator-(double t, const Vec3 &v0) {
        return { t - v0.x, t - v0.y, t - v0.z };
    }

    Vec3 operator*(double t, const Vec3 &v0) {
        return { t * v0.x, t * v0.y, t * v0.z };
    }

    Vec3 operator/(double t, const Vec3 &v0) {
        if (v0.x == 0 || v0.y == 0 || v0.z == 0) {
            throw std::runtime_error("Can't divide by zero.");
        }

        return { t / v0.x, t / v0.y, t / v0.z };
    }

    Vec3 operator+(const Vec3 &v0, double t) {
        return { v0.x + t, v0.y + t, v0.z + t };
    }

    Vec3 operator-(const Vec3 &v0, double t) {
        return { v0.x - t, v0.y - t, v0.z - t };
    }

    Vec3 operator*(const Vec3 &v0, double t) {
        return { v0.x * t, v0.y * t, v0.z * t };
    }

    Vec3 operator/(const Vec3 &v0, double t) {
        if (t == 0) {
            throw std::runtime_error("Can't divide by zero");
        }

        return { v0.x / t, v0.y / t, v0.z / t };
    }

    Vec3 operator-(const Vec3 &v0) {
        return { -v0.x, -v0.y, -v0.z };
    }

    double dot(const Vec3 &v0, const Vec3 &v1) {
        return v0.x * v1.x + v0.y * v1.y + v0.z * v1.z;
    }

    double lengthSquared(const Vec3 &v0) {
        return v0.x * v0.x + v0.y * v0.y + v0.z * v0.z;
    }

    double length(const Vec3 &v0) {
        return std::sqrt(lengthSquared(v0));
    }

    Vec3 normalize(const Vec3 &v0) {
        double len = length(v0);
        if (len > 0.0) {
            return v0 / len;
        }

        return v0;
    }

    Vec3 cross(const Vec3 &v0, const Vec3 &v1) {
        return {
            v0.y * v1.z - v0.z * v1.y,
            v0.z * v1.x - v0.x * v1.z,
            v0.x * v1.y - v0.y * v1.x
        };
    }
}