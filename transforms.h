#ifndef TRANSFORMS_H
#define TRANSFORMS_H

#include "vec3.h"
#include "mat4.h"

Mat4 translate(const Vec3 &v0);
Mat4 scale(const Vec3 &v0);

Mat4 rotateX(double angle);
Mat4 rotateY(double angle);
Mat4 rotateZ(double angle);

Mat4 perspective(
    double fov,
    double aspectRatio,
    double near, double far);

Mat4 getModelMat(
    const Vec3 &translation,
    const Vec3 &dilation,
    const Vec3 &rotation);

#endif