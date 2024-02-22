#version 110

varying vec3 vertexColor;
varying vec2 vertexTex;

uniform sampler2D myTexture;

void main()
{
    gl_FragColor = texture2D(myTexture, vertexTex);
}