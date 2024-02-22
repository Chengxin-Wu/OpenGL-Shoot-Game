//
// Created by Chengxin Wu on 8/31/23.
//

#ifndef GAMEENGINE_SHADERSOURCE_H
#define GAMEENGINE_SHADERSOURCE_H

#include <glew.h>

//static  const GLchar* vertex_shader_source = "#version 120\n"
//                                     "attribute vec3 position;\n"
//                                     "void main()\n"
//                                     "{\n"
//                                     "gl_Position = vec4(position.x, position.y, position.z, 1.0);\n"
//                                     "}\0";
//static const GLchar* fragment_shader_source = "#version 120\n"
//                                       "void main()\n"
//                                       "{\n"
//                                       "   gl_FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
//                                       "}\n";

static const GLchar* vertex_shader_source =
        "#version 110\n"
        "attribute vec3 position;\n"
        "attribute vec3 color;\n"
        "varying vec3 vertexColor;\n"
        "void main()\n"
        "{\n"
        "    gl_Position = vec4(position, 1.0);\n"
        "    vertexColor = color;\n"
        "}\n";

static const char* fragment_shader_source =
        "#version 110\n"
        "varying vec3 vertexColor;\n"
        "void main()\n"
        "{\n"
        "    gl_FragColor = vec4(vertexColor, 1.0);\n"
        "}\n";

#endif //GAMEENGINE_SHADERSOURCE_H
