#include "mat4.h"

namespace brayjl {
    Mat4::Mat4(double x) {
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                data[i][j] = (i == j) ? x : 0.0;
            }
        }
    }

    Mat4::~Mat4() {

    }

    double *Mat4::operator[](std::size_t i) {
        return data[i];
    }

    const double *Mat4::operator[](std::size_t i) const {
        return data[i];
    }

    Mat4 operator*(const Mat4 &m0, const Mat4 &m1) {
        Mat4 result{ 1.0 };

        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                result[i][j] = 0.0;

                for (int k = 0; k < 4; ++k) {
                    result[i][j] += m0[i][k] * m1[k][j];
                }
            }
        }

        return result;
    }

    Vec3 operator*(const Mat4 &m0, const Vec3 &v0) {
        double x = v0.x;
        double y = v0.y;
        double z = v0.z;
        double w = 1.0;

        double clipX = m0[0][0] * x + m0[0][1] * y + m0[0][2] * z + m0[0][3] * w;
        double clipY = m0[1][0] * x + m0[1][1] * y + m0[1][2] * z + m0[1][3] * w;
        double clipZ = m0[2][0] * x + m0[2][1] * y + m0[2][2] * z + m0[2][3] * w;
        double clipW = m0[3][0] * x + m0[3][1] * y + m0[3][2] * z + m0[3][3] * w;

        if (clipW != 0.0) {
            clipX /= clipW;
            clipY /= clipW;
            clipZ /= clipW;
        }

        return { clipX, clipY, clipZ };
    }
}