//
// Created by Chengxin Wu on 8/31/23.
//

#ifndef GAMEENGINE_VERTEXDATA_H
#define GAMEENGINE_VERTEXDATA_H

#include <glew.h>
static GLfloat vertices[] = {
        -0.5f, -0.5f, 0.0f, // Left
        0.5f, -0.5f, 0.0f, // Right
        0.0f,  0.5f, 0.0f  // Top
};

static GLfloat vertices_color[] = {
        1.0f, 0.0f, 0.0f,   // 右下
        0.0f, 1.0f, 0.0f,   // 左下
        0.0f, 0.0f, 1.0f    // 顶部
};

static GLfloat vertices_tex[] = {
        0.0, 0.0,
        1.0, 0.0,
        0.5, 2.0
};

//static GLfloat vertices_tex[] = {
//        1.0f, 1.0f,
//        1.0f, 0.0f,
//        0.0f, 0.0f,
//        0.0f, 1.0f
//};

//static GLfloat vertices[] = {
//        // First triangle
//        -0.9f, -0.5f, 0.0f,  // Left
//        -0.0f, -0.5f, 0.0f,  // Right
//        -0.45f, 0.5f, 0.0f,  // Top
//        // Second triangle
//        0.0f, -0.5f, 0.0f,  // Left
//        0.9f, -0.5f, 0.0f,  // Right
//        0.45f, 0.5f, 0.0f   // Top
//};
#endif //GAMEENGINE_VERTEXDATA_H
