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

Mesh* createCube() {
  std::vector<glm::vec4> vertices = {glm::vec4(-1.0f, -1.0f, -1.0f, 1.0f),
                                     glm::vec4(-1.0f, -1.0f, 1.0f, 1.0f),
                                     glm::vec4(-1.0f, 1.0f, 1.0f, 1.0f),
                                     glm::vec4(1.0f, 1.0f, -1.0f, 1.0f),
                                     glm::vec4(-1.0f, -1.0f, -1.0f, 1.0f),
                                     glm::vec4(-1.0f, 1.0f, -1.0f, 1.0f),
                                     glm::vec4(1.0f, -1.0f, 1.0f, 1.0f),
                                     glm::vec4(-1.0f, -1.0f, -1.0f, 1.0f),
                                     glm::vec4(1.0f, -1.0f, -1.0f, 1.0f),
                                     glm::vec4(1.0f, 1.0f, -1.0f, 1.0f),
                                     glm::vec4(1.0f, -1.0f, -1.0f, 1.0f),
                                     glm::vec4(-1.0f, -1.0f, -1.0f, 1.0f),
                                     glm::vec4(-1.0f, -1.0f, -1.0f, 1.0f),
                                     glm::vec4(-1.0f, 1.0f, 1.0f, 1.0f),
                                     glm::vec4(-1.0f, 1.0f, -1.0f, 1.0f),
                                     glm::vec4(1.0f, -1.0f, 1.0f, 1.0f),
                                     glm::vec4(-1.0f, -1.0f, 1.0f, 1.0f),
                                     glm::vec4(-1.0f, -1.0f, -1.0f, 1.0f),
                                     glm::vec4(-1.0f, 1.0f, 1.0f, 1.0f),
                                     glm::vec4(-1.0f, -1.0f, 1.0f, 1.0f),
                                     glm::vec4(1.0f, -1.0f, 1.0f, 1.0f),
                                     glm::vec4(1.0f, 1.0f, 1.0f, 1.0f),
                                     glm::vec4(1.0f, -1.0f, -1.0f, 1.0f),
                                     glm::vec4(1.0f, 1.0f, -1.0f, 1.0f),
                                     glm::vec4(1.0f, -1.0f, -1.0f, 1.0f),
                                     glm::vec4(1.0f, 1.0f, 1.0f, 1.0f),
                                     glm::vec4(1.0f, -1.0f, 1.0f, 1.0f),
                                     glm::vec4(1.0f, 1.0f, 1.0f, 1.0f),
                                     glm::vec4(1.0f, 1.0f, -1.0f, 1.0f),
                                     glm::vec4(-1.0f, 1.0f, -1.0f, 1.0f),
                                     glm::vec4(1.0f, 1.0f, 1.0f, 1.0f),
                                     glm::vec4(-1.0f, 1.0f, -1.0f, 1.0f),
                                     glm::vec4(-1.0f, 1.0f, 1.0f, 1.0f),
                                     glm::vec4(1.0f, 1.0f, 1.0f, 1.0f),
                                     glm::vec4(-1.0f, 1.0f, 1.0f, 1.0f),
                                     glm::vec4(1.0f, -1.0f, 1.0f, 1.0f)};
  std::vector<glm::vec4> colors = {glm::vec4(0.583f, 0.771f, 0.014f, 1.0f),
                                   glm::vec4(0.609f, 0.115f, 0.436f, 1.0f),
                                   glm::vec4(0.327f, 0.483f, 0.844f, 1.0f),
                                   glm::vec4(0.822f, 0.569f, 0.201f, 1.0f),
                                   glm::vec4(0.435f, 0.602f, 0.223f, 1.0f),
                                   glm::vec4(0.310f, 0.747f, 0.185f, 1.0f),
                                   glm::vec4(0.597f, 0.770f, 0.761f, 1.0f),
                                   glm::vec4(0.559f, 0.436f, 0.730f, 1.0f),
                                   glm::vec4(0.359f, 0.583f, 0.152f, 1.0f),
                                   glm::vec4(0.483f, 0.596f, 0.789f, 1.0f),
                                   glm::vec4(0.559f, 0.861f, 0.639f, 1.0f),
                                   glm::vec4(0.195f, 0.548f, 0.859f, 1.0f),
                                   glm::vec4(0.014f, 0.184f, 0.576f, 1.0f),
                                   glm::vec4(0.771f, 0.328f, 0.970f, 1.0f),
                                   glm::vec4(0.406f, 0.615f, 0.116f, 1.0f),
                                   glm::vec4(0.676f, 0.977f, 0.133f, 1.0f),
                                   glm::vec4(0.971f, 0.572f, 0.833f, 1.0f),
                                   glm::vec4(0.140f, 0.616f, 0.489f, 1.0f),
                                   glm::vec4(0.997f, 0.513f, 0.064f, 1.0f),
                                   glm::vec4(0.945f, 0.719f, 0.592f, 1.0f),
                                   glm::vec4(0.543f, 0.021f, 0.978f, 1.0f),
                                   glm::vec4(0.279f, 0.317f, 0.505f, 1.0f),
                                   glm::vec4(0.167f, 0.620f, 0.077f, 1.0f),
                                   glm::vec4(0.347f, 0.857f, 0.137f, 1.0f),
                                   glm::vec4(0.055f, 0.953f, 0.042f, 1.0f),
                                   glm::vec4(0.714f, 0.505f, 0.345f, 1.0f),
                                   glm::vec4(0.783f, 0.290f, 0.734f, 1.0f),
                                   glm::vec4(0.722f, 0.645f, 0.174f, 1.0f),
                                   glm::vec4(0.302f, 0.455f, 0.848f, 1.0f),
                                   glm::vec4(0.225f, 0.587f, 0.040f, 1.0f),
                                   glm::vec4(0.517f, 0.713f, 0.338f, 1.0f),
                                   glm::vec4(0.053f, 0.959f, 0.120f, 1.0f),
                                   glm::vec4(0.393f, 0.621f, 0.362f, 1.0f),
                                   glm::vec4(0.673f, 0.211f, 0.457f, 1.0f),
                                   glm::vec4(0.820f, 0.883f, 0.371f, 1.0f),
                                   glm::vec4(0.982f, 0.099f, 0.879f, 1.0f)};
  Mesh* mesh = new Mesh(vertices, colors);
  mesh->getTransform().setScale(0.5, 0.5, 0.5);
  return mesh;
}

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

  auto mesh = loadObjectFile("gourd.obj");

  std::vector<Mesh*> meshes = {};
  meshes.push_back(mesh);

  // for (int i = 0; i < 10; i++) {
  //   auto mesh = createCube();
  //   mesh->getTransform().setScale(0.5, 0.5, 0.5);
  //   meshes.push_back(mesh);
  // }

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
    rotate += dt / 5;
  } while (window.getKey(GLFW_KEY_ESCAPE) != GLFW_PRESS &&
           !window.shouldClose());

  glDeleteVertexArrays(1, &va_id);

  return 0;
}