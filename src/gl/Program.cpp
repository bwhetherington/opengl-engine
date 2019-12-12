#include "Program.h"
#include <iostream>
#include "../util/shader.h"

Program::Program(const char* vertex, const char* fragment) {
  m_program_id = loadShaders(vertex, fragment);
}

Program::~Program() { glDeleteProgram(m_program_id); }

void Program::use() { glUseProgram(m_program_id); }

GLuint Program::getUniformLocation(const char* name) const {
  return glGetUniformLocation(m_program_id, name);
}