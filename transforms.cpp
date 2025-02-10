#include "transforms.h"

Mat4 translate(const Vec3 &v0) {
    Mat4 result{ 1.0 };

    result[0][3] = v0.x;
    result[1][3] = v0.y;
    result[2][3] = v0.z;

    return result;
}

Mat4 scale(const Vec3 &v0) {
    Mat4 result{ 1.0 };

    result[0][0] = v0.x;
    result[1][1] = v0.y;
    result[2][2] = v0.z;

    return result;
}