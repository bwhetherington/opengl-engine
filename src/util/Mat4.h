#pragma once
#include "Vec4.h"

class Mat4 {
  //  private:

 public:
  float m_00, m_01, m_02, m_03, m_10, m_11, m_12, m_13, m_20, m_21, m_22, m_23,
      m_30, m_31, m_32, m_33;
  Mat4();
  Mat4(float v_00, float v_01, float v_02, float v_03, float v_10, float v_11,
       float v_12, float v_13, float v_20, float v_21, float v_22, float v_23,
       float v_30, float v_31, float v_32, float v_33);

  static Mat4 identity();

  static Mat4 scale(float x = 1, float y = 1, float z = 1);

  static Mat4 translate(float x = 0, float y = 0, float z = 0);

  static Mat4 rotateX(float theta);

  static Mat4 rotateY(float theta);

  static Mat4 rotateZ(float theta);

  void operator*=(const Mat4& other);

  Vec4 operator*(const Vec4& other) const;
};