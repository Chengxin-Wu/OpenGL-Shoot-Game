//
// Created by Chengxin Wu on 9/11/23.
//

#ifndef CLIONGAME_RECTANGLEDATA_H
#define CLIONGAME_RECTANGLEDATA_H

#include <glew.h>
//static GLfloat vertices[] = {
//        0.5f,  0.5f, 0.0f,   // 右上
//        0.5f, -0.5f, 0.0f,   // 右下
//        -0.5f, -0.5f, 0.0f,    // 左下
//        -0.5f,  0.5f, 0.0f    // 左上
//};

static GLfloat vertices[] = {
        -0.5f, -0.5f, -0.5f,
        0.5f, -0.5f, -0.5f,
        0.5f,  0.5f, -0.5f,
        0.5f,  0.5f, -0.5f,
        -0.5f,  0.5f, -0.5f,
        -0.5f, -0.5f, -0.5f,

        -0.5f, -0.5f,  0.5f,
        0.5f, -0.5f,  0.5f,
        0.5f,  0.5f,  0.5f,
        0.5f,  0.5f,  0.5f,
        -0.5f,  0.5f,  0.5f,
        -0.5f, -0.5f,  0.5f,

        -0.5f,  0.5f,  0.5f,
        -0.5f,  0.5f, -0.5f,
        -0.5f, -0.5f, -0.5f,
        -0.5f, -0.5f, -0.5f,
        -0.5f, -0.5f,  0.5f,
        -0.5f,  0.5f,  0.5f,

        0.5f,  0.5f,  0.5f,
        0.5f,  0.5f, -0.5f,
        0.5f, -0.5f, -0.5f,
        0.5f, -0.5f, -0.5f,
        0.5f, -0.5f,  0.5f,
        0.5f,  0.5f,  0.5f,

        -0.5f, -0.5f, -0.5f,
        0.5f, -0.5f, -0.5f,
        0.5f, -0.5f,  0.5f,
        0.5f, -0.5f,  0.5f,
        -0.5f, -0.5f,  0.5f,
        -0.5f, -0.5f, -0.5f,

        -0.5f,  0.5f, -0.5f,
        0.5f,  0.5f, -0.5f,
        0.5f,  0.5f,  0.5f,
        0.5f,  0.5f,  0.5f,
        -0.5f,  0.5f,  0.5f,
        -0.5f,  0.5f, -0.5f
};

//static GLfloat vertices_color[] = {
//        1.0f, 0.0f, 0.0f,    // 右上
//        0.0f, 1.0f, 0.0f,    // 右下
//        0.0f, 0.0f, 1.0f, // 左下
//        1.0f, 1.0f,0.0f // 左上
//};

//static GLfloat vertices_tex[] = {
//        1.0f, 1.0f,
//        1.0f, 0.0f,
//        0.0f, 0.0f,
//        0.0f, 1.0f
//};

static GLfloat vertices_tex[] = {

        0.0f, 0.0f,
        1.0f, 0.0f,
        1.0f, 1.0f,
        1.0f, 1.0f,
        0.0f, 1.0f,
        0.0f, 0.0f,

        0.0f, 0.0f,
        1.0f, 0.0f,
        1.0f, 1.0f,
        1.0f, 1.0f,
        0.0f, 1.0f,
        0.0f, 0.0f,

        1.0f, 0.0f,
        1.0f, 1.0f,
        0.0f, 1.0f,
        0.0f, 1.0f,
        0.0f, 0.0f,
        1.0f, 0.0f,

        1.0f, 0.0f,
        1.0f, 1.0f,
        0.0f, 1.0f,
        0.0f, 1.0f,
        0.0f, 0.0f,
        1.0f, 0.0f,

        0.0f, 1.0f,
        1.0f, 1.0f,
        1.0f, 0.0f,
        1.0f, 0.0f,
        0.0f, 0.0f,
        0.0f, 1.0f,

        0.0f, 1.0f,
        1.0f, 1.0f,
        1.0f, 0.0f,
        1.0f, 0.0f,
        0.0f, 0.0f,
        0.0f, 1.0f
};

static GLfloat vertices_color[] ={};

//static GLuint indices[] = {
//        0, 1, 3,
//        1, 2, 3
//};

static GLfloat vertices_normal[] = {

          0.0f,  0.0f, -1.0f,
          0.0f,  0.0f, -1.0f,
          0.0f,  0.0f, -1.0f,
          0.0f,  0.0f, -1.0f,
          0.0f,  0.0f, -1.0f,
          0.0f,  0.0f, -1.0f,


          0.0f,  0.0f,  1.0f,
          0.0f,  0.0f,  1.0f,
          0.0f,  0.0f,  1.0f,
          0.0f,  0.0f,  1.0f,
          0.0f,  0.0f,  1.0f,
          0.0f,  0.0f,  1.0f,


         -1.0f,  0.0f,  0.0f,
         -1.0f,  0.0f,  0.0f,
         -1.0f,  0.0f,  0.0f,
         -1.0f,  0.0f,  0.0f,
         -1.0f,  0.0f,  0.0f,
         -1.0f,  0.0f,  0.0f,


         1.0f,  0.0f,  0.0f,
         1.0f,  0.0f,  0.0f,
         1.0f,  0.0f,  0.0f,
         1.0f,  0.0f,  0.0f,
         1.0f,  0.0f,  0.0f,
         1.0f,  0.0f,  0.0f,


          0.0f, -1.0f,  0.0f,
          0.0f, -1.0f,  0.0f,
          0.0f, -1.0f,  0.0f,
          0.0f, -1.0f,  0.0f,
          0.0f, -1.0f,  0.0f,
          0.0f, -1.0f,  0.0f,

          0.0f,  1.0f,  0.0f,
          0.0f,  1.0f,  0.0f,
          0.0f,  1.0f,  0.0f,
          0.0f,  1.0f,  0.0f,
          0.0f,  1.0f,  0.0f,
          0.0f,  1.0f,  0.0f
};

#endif //CLIONGAME_RECTANGLEDATA_H
