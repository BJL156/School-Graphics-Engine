#ifndef MAT4_H
#define MAT4_H

#include "vec3.h"

#include <cstdint>

struct Mat4 {
    Mat4(double x);
    ~Mat4();

    double *operator[](std::size_t i);
    const double *operator[](std::size_t i) const;

    double data[4][4];
};


Mat4 operator*(const Mat4 &m0, const Mat4 &m1);
Vec3 operator*(const Mat4 &m0, const Vec3 &v0);

#endif