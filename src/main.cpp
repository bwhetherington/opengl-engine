#include <iostream>

// Include GLEW
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/gtx/transform.hpp>
#include <glm/mat4x4.hpp>
#include <glm/vec4.hpp>
#include <vector>

#include "fs/object.h"
#include "gl/Mesh.h"
#include "gl/Program.h"
#include "gl/Transform.h"
#include "glfw/Window.h"
#include "util/Mat4.h"
#include "util/Timer.h"
#include "util/Vec4.h"
#include "util/shader.h"

int main() {
  if (!glfwInit()) {
    std::cerr << "Failed to initialize GLEW" << std::endl;
    return -1;
  }

  glfwWindowHint(GLFW_SAMPLES, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  Window window("Voxel Game", 720, 540);
  window.makeContextCurrent();

  // glfwMakeContextCurrent(window);

  // Initialize GLEW
  glewExperimental = true;  // Needed for core profile
  if (glewInit() != GLEW_OK) {
    // fprintf(stderr, "Failed to initialize GLEW\n");
    getchar();
    glfwTerminate();
    return -1;
  }

  window.setInputMode(GLFW_STICKY_KEYS, GL_TRUE);

  glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
  // Enable depth test
  glEnable(GL_DEPTH_TEST);
  // Accept fragment if it closer to the camera than the former one
  glDepthFunc(GL_LESS);

  GLuint va_id;
  glGenVertexArrays(1, &va_id);
  glBindVertexArray(va_id);

  // Create and compile our GLSL program from the shaders
  Program program("src/shaders/basic.vert", "src/shaders/basic.frag");

  // static const GLfloat g_vertex_buffer_data[] = {
  //     -1.0f, -1.0f, 0.0f, 1.0f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
  // };

  // std::vector<glm::vec4> vertices = {glm::vec4(-0.5f, -0.6f, 0.0f, 1.0f),
  //                                    glm::vec4(0.5f, -0.6f, 0.0f, 1.0f),
  //                                    glm::vec4(0.0f, 0.6f, 0.0f, 1.0f)};
  // std::vector<glm::vec4> colors = {glm::vec4(1.0f, 0.0f, 0.0f, 1.0f),
  //                                  glm::vec4(0.0f, 1.0f, 0.0f, 1.0f),
  //                                  glm::vec4(0.0f, 0.0f, 1.0f, 1.0f)};
  // Mesh mesh(vertices, colors);

  Transform trans;
  trans.setTranslate(0, -1, -3);
  trans.setRotation(0.25, 0, 0);

  glm::mat4 perspective =
      glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.0f);

  auto pv = perspective * trans.getMatrix();

  // auto mesh = loadObjectFile("gourd.obj");

  std::vector<Mesh*> meshes = {};
  // meshes.push_back(mesh);

  for (int i = 0; i < 1; i++) {
    // auto mesh = createCube();
    auto mesh = loadObjectFile("cube.obj");
    mesh->getTransform().setScale(0.5, 0.5, 0.5);
    meshes.push_back(mesh);
  }

  double last_time = 0;

  float rotate = 0;

  do {
    // Clear screen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Use our shader
    program.use();

    // Draw mesh
    // for (auto mesh : meshes) {
    //   std::cout << "mesh" << std::endl;
    //   mesh.getTransform().setRotation(rotate, rotate, rotate);
    //   mesh.draw(program);
    // }

    for (int i = 0; i < meshes.size(); i++) {
      // std::cout << i << ": " << &meshes[i] << std::endl;
      auto offset = rotate * ((i + 1) * 0.5);
      auto mesh = meshes[i];
      mesh->getTransform().setRotation(offset, offset, offset);
      mesh->draw(program, pv);
    }

    // Swap buffers
    window.swapBuffers();
    window.pollEvents();

    auto time = glfwGetTime();
    auto dt = time - last_time;
    last_time = time;
    rotate += dt;
  } while (window.getKey(GLFW_KEY_ESCAPE) != GLFW_PRESS &&
           !window.shouldClose());

  glDeleteVertexArrays(1, &va_id);

  return 0;
}