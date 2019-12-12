#include "object.h"

#include <fstream>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <iostream>
#include <sstream>
#include <string>

Mesh* loadObjectFile(const char* filename) {
  std::ifstream input(filename);
  std::string line;

  std::vector<glm::vec4> vertices;
  std::vector<glm::vec3> faces;

  while (std::getline(input, line)) {
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

          glm::vec4 vtx = glm::vec4(x, y, z, 1.0f);
          vertices.push_back(vtx);
        } else if (first_word == "f") {
          // Read face
          int a, b, c;
          reader >> a;
          reader >> b;
          reader >> c;

          glm::vec3 face(a, b, c);
          faces.push_back(face);
        }
      }
    }
  }

  // Construct list of vertices in order
  std::vector<glm::vec4> mesh_vertices = {};
  std::vector<glm::vec4> mesh_colors = {};

  for (auto face : faces) {
    auto x = vertices[face.x];
    auto y = vertices[face.y];
    auto z = vertices[face.z];
    mesh_vertices.push_back(x);
    mesh_vertices.push_back(y);
    mesh_vertices.push_back(z);
    mesh_colors.push_back(glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));
    mesh_colors.push_back(glm::vec4(0.0f, 1.0f, 0.0f, 1.0f));
    mesh_colors.push_back(glm::vec4(0.0f, 0.0f, 1.0f, 1.0f));
  }

  return new Mesh(mesh_vertices, mesh_colors);
}