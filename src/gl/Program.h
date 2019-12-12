#pragma once

#include <GLFW/glfw3.h>

class Program {
 private:
  GLuint m_program_id;

 public:
  Program(const char* vertex, const char* fragment);
  virtual ~Program();

  void use();

  GLuint getUniformLocation(const char* name) const;
};