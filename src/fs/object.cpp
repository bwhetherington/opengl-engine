#include "object.h"

#include <fstream>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>

#include "../util/strutil.h"

void readIndex(const std::string& str, int* dst) {
  std::vector<std::string> indices = split(str, '/');

  // Vertex
  std::stringstream ss(indices[0]);
  int val;
  ss >> val;
  *dst = val;

  // Texture coords

  // Normal

  // std::cout << "readIndex " << val << std::endl;
}

Mesh* loadObjectFile(const char* filename) {
  std::ifstream input(filename);
  std::string line;

  std::vector<glm::vec3> vertices;
  std::vector<glm::vec2> uv_vertices;
  std::vector<glm::vec3> normal_vertices;
  std::vector<glm::vec3> faces;

  while (std::getline(input, line)) {
    // std::cout << line << std::endl;
    if (line.size() > 0) {
      // Check if this line is a comment
      if (line[0] != '#') {
        // Get first word
        auto index = line.find(' ');

        std::string first_word = line.substr(0, index);
        std::string rest = line.substr(index + 1);

        std::stringstream reader(rest);

        if (first_word == "v") {
          // Read vertex
          float x, y, z;
          reader >> x;
          reader >> y;
          reader >> z;

          glm::vec3 vtx = glm::vec3(x, y, z);
          vertices.push_back(vtx);
        } else if (first_word == "vt") {
          float x, y;
          reader >> x;
          reader >> y;
          glm::vec2 uv = glm::vec2(x, y);
          uv_vertices.push_back(uv);
        } else if (first_word == "vn") {
          float x, y, z;
          reader >> x;
          reader >> y;
          reader >> z;
          glm::vec3 normal = glm::vec3(x, y, z);
          normal_vertices.push_back(normal);
        } else if (first_word == "f") {
          // Split it into subwords
          int a, b, c;
          std::vector<std::string> words = splitWhitespace(rest);

          // std::cout << "line: " << words[0] << "," << words[1] << "," << words[2] << std::endl;;
          // std::cout << "line: " << rest << std::endl;

          readIndex(words[0], &a);
          readIndex(words[1], &b);
          readIndex(words[2], &c);

          // // Read face
          // int a, b, c;
          // reader >> a;
          // reader >> b;
          // reader >> c;

          glm::vec3 face(a, b, c);
          faces.push_back(face);
        }
      }
    }
  }

  // Construct list of vertices in order
  std::vector<glm::vec3> mesh_vertices = {};
  std::vector<glm::vec4> mesh_colors = {};

  for (auto face : faces) {
    auto a = vertices[face.x - 1];
    auto b = vertices[face.y - 1];
    auto c = vertices[face.z - 1];
    mesh_vertices.push_back(a);
    mesh_vertices.push_back(b);
    mesh_vertices.push_back(c);
    mesh_colors.push_back(glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));
    mesh_colors.push_back(glm::vec4(0.0f, 1.0f, 0.0f, 1.0f));
    mesh_colors.push_back(glm::vec4(0.0f, 0.0f, 1.0f, 1.0f));
  }

  return new Mesh(mesh_vertices, mesh_colors);
}