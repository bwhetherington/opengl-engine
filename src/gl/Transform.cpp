#include "Transform.h"

#include <glm/gtx/transform.hpp>
#include <iostream>

using namespace glm;

Transform::Transform() {
  m_mat = mat4(1.0f);
  m_translate = vec3(0.0f, 0.0f, 0.0f);
  m_scale = vec3(1.0f, 1.0f, 1.0f);
  m_rotate = vec3(0.0f, 0.0f, 0.0f);
}

void Transform::calculate() {
  mat4 sc = scale(m_scale);
  mat4 tx = translate(m_translate);

  // Calculate rotation
  mat4 x_rot = rotate(m_rotate.x, vec3(1, 0, 0));
  mat4 y_rot = rotate(m_rotate.y, vec3(0, 1, 0));
  mat4 z_rot = rotate(m_rotate.z, vec3(0, 0, 1));

  mat4 rot = x_rot * y_rot * z_rot;

  m_mat = rot * sc * tx;
}

mat4 Transform::getMatrix() {
  if (m_should_recalculate) {
    calculate();
    m_should_recalculate = false;
  }

  return m_mat;
}

void Transform::setTranslate(float x, float y, float z) {
  m_translate = vec3(x, y, z);
  m_should_recalculate = true;
}

void Transform::setTranslate(vec3 translate) {
  m_translate = translate;
  m_should_recalculate = true;
}

void Transform::setRotation(float x, float y, float z) {
  m_rotate = vec3(x, y, z);
  m_should_recalculate = true;
}

void Transform::setRotation(vec3 rotate) {
  m_rotate = rotate;
  m_should_recalculate = true;
}

void Transform::setScale(float x, float y, float z) {
  m_scale = vec3(x, y, z);
  m_should_recalculate = true;
}

void Transform::setScale(vec3 scale) {
  m_scale = scale;
  m_should_recalculate = true;
}