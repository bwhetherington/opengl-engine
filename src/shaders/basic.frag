#version 330 core

// Ouput data
out vec4 out_color;

in vec4 frag_color;

void main() {
	// Output color = red 
	out_color = frag_color;
}