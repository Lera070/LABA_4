#version 460 core
out vec4 FragColor;

uniform vec4 ourColour;

void main() {
    FragColor = ourColour;
}