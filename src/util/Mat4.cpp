#include "Mat4.h"
#include <cmath>

Mat4::Mat4() {}

Mat4::Mat4(float v_00, float v_01, float v_02, float v_03, float v_10,
           float v_11, float v_12, float v_13, float v_20, float v_21,
           float v_22, float v_23, float v_30, float v_31, float v_32,
           float v_33) {
  // Row 0
  m_00 = v_00;
  m_01 = v_01;
  m_02 = v_02;
  m_03 = v_03;

  // Row 1
  m_10 = v_10;
  m_11 = v_11;
  m_12 = v_12;
  m_13 = v_13;

  // Row 2
  m_20 = v_20;
  m_21 = v_21;
  m_22 = v_22;
  m_23 = v_23;

  // Row 3
  m_30 = v_30;
  m_31 = v_31;
  m_32 = v_32;
  m_33 = v_33;
}

Mat4 Mat4::identity() {
  Mat4 mat(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);
  return mat;
}

Mat4 Mat4::scale(float x, float y, float z) {
  Mat4 mat(x, 0, 0, 0, 0, y, 0, 0, 0, 0, y, 0, 0, 0, 0, 1);
  return mat;
}

Mat4 Mat4::translate(float x, float y, float z) {
  Mat4 mat(1, 0, 0, x, 0, 1, 0, y, 0, 0, 1, z, 0, 0, 0, 1);
  return mat;
}

Mat4 Mat4::rotateX(float theta) {
  auto c = cos(theta);
  auto s = cos(theta);
  return Mat4(1, 0, 0, 0, 0, c, -s, 0, 0, s, c, 0, 0, 0, 0, 1);
}

Mat4 Mat4::rotateY(float theta) {
  auto c = cos(theta);
  auto s = cos(theta);
  return Mat4(c, 0, s, 0, 0, 1, 0, 0, -s, 0, c, 0, 0, 0, 0, 1);
}

Mat4 Mat4::rotateZ(float theta) {
  auto c = cos(theta);
  auto s = cos(theta);
  return Mat4(c, -s, 0, 0, s, c, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);
}

void Mat4::operator*=(const Mat4& other) {
  // Row 0
  m_00 = (m_00 * other.m_00) + (m_01 * other.m_10) + (m_02 * other.m_20) +
         (m_03 * other.m_30);
  m_01 = (m_00 * other.m_01) + (m_01 * other.m_11) + (m_02 * other.m_21) +
         (m_03 * other.m_31);
  m_02 = (m_00 * other.m_02) + (m_01 * other.m_12) + (m_02 * other.m_22) +
         (m_03 * other.m_32);
  m_03 = (m_00 * other.m_03) + (m_01 * other.m_13) + (m_02 * other.m_23) +
         (m_03 * other.m_33);

  // Row 1
  m_10 = (m_10 * other.m_00) + (m_11 * other.m_10) + (m_12 * other.m_20) +
         (m_13 * other.m_30);
  m_11 = (m_10 * other.m_01) + (m_11 * other.m_11) + (m_12 * other.m_21) +
         (m_13 * other.m_31);
  m_12 = (m_10 * other.m_02) + (m_11 * other.m_12) + (m_12 * other.m_22) +
         (m_13 * other.m_32);
  m_13 = (m_10 * other.m_03) + (m_11 * other.m_13) + (m_12 * other.m_23) +
         (m_13 * other.m_33);

  // Row 2
  m_20 = (m_20 * other.m_00) + (m_21 * other.m_10) + (m_22 * other.m_20) +
         (m_23 * other.m_30);
  m_21 = (m_20 * other.m_01) + (m_21 * other.m_11) + (m_22 * other.m_21) +
         (m_23 * other.m_31);
  m_22 = (m_20 * other.m_02) + (m_21 * other.m_12) + (m_22 * other.m_22) +
         (m_23 * other.m_32);
  m_23 = (m_20 * other.m_03) + (m_21 * other.m_13) + (m_22 * other.m_23) +
         (m_23 * other.m_33);

  // Row 3
  m_30 = (m_30 * other.m_00) + (m_31 * other.m_10) + (m_32 * other.m_20) +
         (m_33 * other.m_30);
  m_31 = (m_30 * other.m_01) + (m_31 * other.m_11) + (m_32 * other.m_21) +
         (m_33 * other.m_31);
  m_32 = (m_30 * other.m_02) + (m_31 * other.m_12) + (m_32 * other.m_22) +
         (m_33 * other.m_32);
  m_33 = (m_30 * other.m_03) + (m_31 * other.m_13) + (m_32 * other.m_23) +
         (m_33 * other.m_33);
}

Vec4 Mat4::operator*(const Vec4& other) const {
  auto x = other.getX();
  auto y = other.getY();
  auto z = other.getZ();
  auto w = other.getW();
  Vec4 vec((m_00 * x) + (m_01 * y) + (m_02 * z) + (m_03 * w),
           (m_10 * x) + (m_11 * y) + (m_12 * z) + (m_13 * w),
           (m_20 * x) + (m_21 * y) + (m_22 * z) + (m_23 * w),
           (m_30 * x) + (m_31 * y) + (m_32 * z) + (m_33 * w));
  return vec;
}
