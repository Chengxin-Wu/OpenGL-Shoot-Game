//
// Created by Chengxin Wu on 9/1/23.
//

#ifndef GAMEENGINE_SHADER_H
#define GAMEENGINE_SHADER_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <glew.h>

#include "ShaderSource.h"

using namespace std;

class Shader{
public:
    GLuint Program;
    Shader(const GLchar* vertexPath, const GLchar* fragmentPath)
    {
        string vertexCode;
        string fragmentCode;
        ifstream vShaderFile;
        ifstream fShaderFile;

        vShaderFile.exceptions(ifstream::badbit);
        fShaderFile.exceptions(ifstream::badbit);
        try
        {
            // Open file
            vShaderFile.open(vertexPath);
            fShaderFile.open(fragmentPath);
            stringstream vShaderStream, fShaderStream;
            vShaderStream << vShaderFile.rdbuf();
            fShaderStream << fShaderFile.rdbuf();
            vShaderFile.close();
            fShaderFile.close();

            // Convert Stream to String
            vertexCode = vShaderStream.str();
            fragmentCode = fShaderStream.str();
        }
        catch (ifstream::failure e)
        {
            cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
        }
        const GLchar* vShaderCode = vertexCode.c_str();
        const GLchar* fShaderCode = fragmentCode.c_str();

        GLuint vertex, fragment;
        GLint compil_status;
        GLchar infoLog[512];
        // Vertex Shader
        vertex = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertex, 1, &vShaderCode, NULL);
//        glShaderSource(vertex, 1, &vertex_shader_source, NULL);
        glCompileShader(vertex);
        glGetShaderiv(vertex, GL_COMPILE_STATUS, &compil_status);
        if (!compil_status){
            glGetShaderInfoLog(vertex, 512, NULL, infoLog);
            cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << endl;
        }

        fragment = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragment, 1, &fShaderCode, NULL);
//        glShaderSource(fragment, 1, &fragment_shader_source, NULL);
        glCompileShader(fragment);
        glGetShaderiv(fragment, GL_COMPILE_STATUS, &compil_status);
        if (!compil_status){
            glGetShaderInfoLog(fragment, 512, NULL, infoLog);
            cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << endl;
        }

        // Shader Program
        this->Program = glCreateProgram();
        glAttachShader(this->Program, vertex);
        glAttachShader(this->Program, fragment);
        glLinkProgram(this->Program);
        GLint link_status;
        glGetProgramiv(this->Program, GL_LINK_STATUS, &link_status);
        if (!link_status){
            glGetProgramInfoLog(this->Program, 512, NULL, infoLog);
            cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << endl;
        }
        glDeleteShader(vertex);
        glDeleteShader(fragment);
    }

    // Use current shader
    void use()
    {
        glUseProgram(this->Program);
    }
};

#endif //GAMEENGINE_SHADER_H
