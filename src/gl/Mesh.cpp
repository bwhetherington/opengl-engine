#include "Mesh.h"

#include <iostream>

template <typename T>
void writeBuffer(GLuint buffer, const std::vector<T> data) {
  // std::cout << "START_BUFFER (" << sizeof(T) << ")" << std::endl;

  // int len = data.size() * sizeof(T);
  // for (int i = 0; i < len; i++) {
  //   std::cout << &data[i] << std::endl;
  // }

  // std::cout << "END_BUFFER" << std::endl;

  glBindBuffer(GL_ARRAY_BUFFER, buffer);
  glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(T), &data[0],
               GL_STATIC_DRAW);
}

Mesh::Mesh(const std::vector<glm::vec4>& vertices,
           const std::vector<glm::vec4>& colors) {
  m_vertex_count = vertices.size();

  // Initialize VBOs
  glGenBuffers(1, &m_vertex_vbo);
  glGenBuffers(1, &m_color_vbo);

  writeBuffer(m_vertex_vbo, vertices);
  writeBuffer(m_color_vbo, colors);
}

Mesh::~Mesh() {
  glDeleteBuffers(1, &m_vertex_vbo);
  glDeleteBuffers(1, &m_color_vbo);
  std::cout << "Mesh::~Mesh()" << std::endl;
}

void Mesh::bindVertexBuffer() const {
  glBindBuffer(GL_ARRAY_BUFFER, m_vertex_vbo);
}

void Mesh::bindColorBuffer() const {
  glBindBuffer(GL_ARRAY_BUFFER, m_color_vbo);
}

void Mesh::draw(const Program& program, const glm::mat4& pv) {
  // Vertices
  bindVertexBuffer();
  glVertexAttribPointer(0, 4, GL_FLOAT, false, 0, 0);
  glEnableVertexAttribArray(0);

  // Colors
  bindColorBuffer();
  glVertexAttribPointer(1, 4, GL_FLOAT, false, 0, 0);
  glEnableVertexAttribArray(1);

  // Uniforms
  auto mat = pv * getTransform().getMatrix();

  auto mvp_location = program.getUniformLocation("mvp");
  glUniformMatrix4fv(mvp_location, 1, false, &mat[0][0]);

  glDrawArrays(GL_TRIANGLES, 0, m_vertex_count * sizeof(glm::vec4));

  glDisableVertexAttribArray(0);
  glDisableVertexAttribArray(1);
}

Transform& Mesh::getTransform() { return m_transform; }