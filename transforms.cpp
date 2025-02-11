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

Mat4 rotateX(double angle) {
    Mat4 result{ 1.0 };

    double cosAngle = std::cos(angle);
    double sinAngle = std::sin(angle);

    result[1][1] = cosAngle;
    result[2][1] = -sinAngle;
    result[1][2] = sinAngle;
    result[2][2] = cosAngle;

    return result;
}

Mat4 rotateY(double angle) {
    Mat4 result{ 1.0 };

    double cosAngle = std::cos(angle);
    double sinAngle = std::sin(angle);

    result[0][0] = cosAngle;
    result[0][2] = -sinAngle;
    result[2][0] = sinAngle;
    result[2][2] = cosAngle;

    return result;
}

Mat4 rotateZ(double angle) {
    Mat4 result{ 1.0 };

    double cosAngle = std::cos(angle);
    double sinAngle = std::sin(angle);

    result[0][0] = cosAngle;
    result[0][1] = -sinAngle;
    result[1][0] = sinAngle;
    result[1][1] = cosAngle;

    return result;
}

Mat4 perspective(
    double fov,
    double aspectRatio,
    double near, double far) {
    Mat4 result{ 1.0 };
    double tanHalfFov = std::tan(fov / 2.0);

    result[0][0] = 1.0 / (aspectRatio * tanHalfFov);
    result[1][1] = 1.0 / tanHalfFov;
    result[2][2] = -(far + near) / (far - near);
    result[2][3] = -(2.0 * far * near) / (far - near);
    result[3][2] = -1.0;
    result[3][3] = 0.0;

    return result;
}

Mat4 getModelMat(
    const Vec3 &translation,
    const Vec3 &dilation,
    const Vec3 &rotation) {
    Mat4 scaleMat = scale(dilation);
    Mat4 rotationMat = rotateZ(rotation.z) * rotateY(rotation.y) * rotateX(rotation.x);
    Mat4 translationMat = translate(translation);

    return translationMat * rotationMat * scaleMat;
}