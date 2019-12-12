#pragma once

class Vec4 {
 private:
  float m_x;
  float m_y;
  float m_z;
  float m_w;

  Vec4 add(float x = 0, float y = 0, float z = 0, float w = 1) const;

 public:
  Vec4(float x = 0, float y = 0, float z = 0, float w = 0);

  // Operators

  Vec4 operator+(const Vec4& other) const;
  Vec4 operator-(const Vec4& other) const;
  Vec4 operator*(float scalar) const;

  float getX() const;
  float getY() const;
  float getZ() const;
  float getW() const;
};