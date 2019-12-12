#include "Vec4.h"

Vec4::Vec4(float x, float y, float z, float w) {
  m_x = x;
  m_y = y;
  m_z = z;
  m_w = w;
}

float Vec4::getX() const { return m_x; }
float Vec4::getY() const { return m_y; }
float Vec4::getZ() const { return m_z; }
float Vec4::getW() const { return m_w; }

Vec4 Vec4::add(float x, float y, float z, float w) const {
  Vec4 vec(m_x + x, m_y + y, m_z + z, m_w + w);
  return vec;
}

Vec4 Vec4::operator+(const Vec4& other) const {
  return add(other.getX(), other.getY(), other.getZ(), other.getW());
}

Vec4 Vec4::operator-(const Vec4& other) const {
  return add(-other.getX(), -other.getY(), -other.getZ(), -other.getW());
}

Vec4 Vec4::operator*(float scalar) const {
  Vec4 product(m_x * scalar, m_y * scalar, m_z * scalar, m_w * scalar);
  return product;
}