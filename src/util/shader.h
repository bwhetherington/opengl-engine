#pragma once
#include <GLFW/glfw3.h>

#include <string>

GLuint compileShaders(std::string vertex_shader, std::string fragment_shader);

GLuint loadShaders(const char* vertex_shader, const char* fragment_shader);