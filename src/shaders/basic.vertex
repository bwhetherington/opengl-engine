#version 330 core

// Input vertex data, different for all executions of this shader.
layout(location = 0) in vec4 vertex;
layout(location = 1) in vec4 color;

out vec4 frag_color;

uniform mat4 mvp;

void main() {
  gl_Position.xyzw = mvp * vertex;
  frag_color = color;

  // gl_Position.x /= 2;
  // gl_Position.y /= 2;
  // // gl_Position.z
  // gl_Position.w = 1.0;
}