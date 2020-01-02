#version 330 core

// Input vertex data, different for all executions of this shader.
layout(location = 0) in vec4 vertex;
layout(location = 1) in vec4 color;
layout(location = 2) in vec2 uv;
layout(location = 3) in vec4 normal;

out vec4 frag_color;

uniform mat4 mvp;

void main() {
  gl_Position.xyzw = mvp * vertex;
  frag_color = color;
}