#include <GLFW/glfw3.h>

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

GLuint compileShaders(std::string vertex_shader, std::string fragment_shader) {
  GLuint vertex_shader_id = glCreateShader(GL_VERTEX_SHADER);
  GLuint fragment_shader_id = glCreateShader(GL_FRAGMENT_SHADER);

  GLint result = GL_FALSE;
  int info_log_length;

  const char* vertex_ptr = vertex_shader.c_str();
  glShaderSource(vertex_shader_id, 1, &vertex_ptr, NULL);
  glCompileShader(vertex_shader_id);

  // Check for errors
  glGetShaderiv(vertex_shader_id, GL_COMPILE_STATUS, &result);
  glGetShaderiv(vertex_shader_id, GL_INFO_LOG_LENGTH, &info_log_length);
  if (info_log_length > 0) {
    std::vector<char> error_message(info_log_length + 1);
    glGetShaderInfoLog(vertex_shader_id, info_log_length, NULL,
                       &error_message[0]);
    std::cout << &error_message[0] << std::endl;
  }

  const char* fragment_ptr = fragment_shader.c_str();
  glShaderSource(fragment_shader_id, 1, &fragment_ptr, NULL);
  glCompileShader(fragment_shader_id);

  // Check for errors
  glGetShaderiv(fragment_shader_id, GL_COMPILE_STATUS, &result);
  glGetShaderiv(fragment_shader_id, GL_INFO_LOG_LENGTH, &info_log_length);
  if (info_log_length > 0) {
    std::vector<char> error_message(info_log_length + 1);
    glGetShaderInfoLog(fragment_shader_id, info_log_length, NULL,
                       &error_message[0]);
    std::cout << &error_message[0] << std::endl;
  }

  // Link program
  GLuint program_id = glCreateProgram();
  glAttachShader(program_id, vertex_shader_id);
  glAttachShader(program_id, fragment_shader_id);
  glLinkProgram(program_id);

  // Check for linking errors
  glGetProgramiv(program_id, GL_LINK_STATUS, &result);
  glGetProgramiv(program_id, GL_INFO_LOG_LENGTH, &info_log_length);
  if (info_log_length > 0) {
    std::vector<char> error_message(info_log_length + 1);
    glGetProgramInfoLog(program_id, info_log_length, NULL, &error_message[0]);
    std::cout << &error_message[0] << std::endl;
  }

  glDetachShader(program_id, vertex_shader_id);
  glDetachShader(program_id, fragment_shader_id);

  glDeleteShader(vertex_shader_id);
  glDeleteShader(fragment_shader_id);

  return program_id;
}

GLuint loadShaders(const char* vertex_shader, const char* fragment_shader) {
  // Load vertex shader code
  std::string vertex_shader_code;
  std::ifstream vertex_shader_stream(vertex_shader, std::ios::in);

  if (vertex_shader_stream.is_open()) {
    std::stringstream ss;
    ss << vertex_shader_stream.rdbuf();
    vertex_shader_code = ss.str();
    vertex_shader_stream.close();
  }

  // Load fragment shader code
  std::string fragment_shader_code;
  std::ifstream fragment_shader_stream(fragment_shader, std::ios::in);

  if (fragment_shader_stream.is_open()) {
    std::stringstream ss;
    ss << fragment_shader_stream.rdbuf();
    fragment_shader_code = ss.str();
    fragment_shader_stream.close();
  }

  // Compile shaders
  return compileShaders(vertex_shader_code, fragment_shader_code);
}