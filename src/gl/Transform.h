#pragma once

#include <glm/mat4x4.hpp>

class Transform {
 private:
  glm::mat4 m_mat;
  bool m_should_recalculate;

  glm::vec3 m_translate;
  glm::vec3 m_rotate;
  glm::vec3 m_scale;

  void calculate();

 public:
  Transform();

  void setTranslate(float x = 0, float y = 0, float z = 0);
  void setTranslate(glm::vec3 translate);

  void setRotation(float x, float y, float z);
  void setRotation(glm::vec3 rotation);

  void setScale(float x, float y, float z);
  void setScale(glm::vec3 rotation);

  glm::mat4 getMatrix();
};