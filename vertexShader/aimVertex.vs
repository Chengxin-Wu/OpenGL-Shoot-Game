#version 110

attribute vec2 position;

uniform mat4 translate;

void main()
{
    gl_Position = vec4(position.x, position.y, 0.0, 1.0);
}