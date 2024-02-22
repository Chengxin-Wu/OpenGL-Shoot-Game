#version 110

attribute vec3 position;
attribute vec2 texCoord;

varying vec3 vertexColor;
varying vec2 vertexTex;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    gl_Position = projection * view * model * vec4(position, 1.0);
    vertexTex = vec2(texCoord.x, 1.0 - texCoord.y);
}