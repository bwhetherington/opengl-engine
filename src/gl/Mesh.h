#pragma once

#include <GLFW/glfw3.h>
#include <glm/mat4x4.hpp>
#include <glm/vec4.hpp>
#include <vector>

#include "Program.h"
#include "Transform.h"

class Mesh {
 private:
  int m_vertex_count;
  GLuint m_vertex_vbo;
  GLuint m_color_vbo;

  Transform m_transform;

  void bindVertexBuffer() const;
  void bindColorBuffer() const;

 public:
  Mesh(const std::vector<glm::vec4>& vertices,
       const std::vector<glm::vec4>& colors);
  virtual ~Mesh();

  void draw(const Program& program, const glm::mat4& pv);

  Transform& getTransform();
};