#pragma once
#ifndef SHADER_LOADER_H
#define SHADER_LOADER_H

#include <GL/glew.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <unordered_map>

class Shader {
public:
    GLuint ID; // Идентификатор шейдерной программы

    Shader(const char* vertexPath, const char* fragmentPath);
    void use();

    // Универсальные методы для передачи uniform-переменных
    void setUniform(const std::string& name, float v1, float v2, float v3, float v4);
    void setUniform(const std::string& name, int value);
    void setUniform(const std::string& name, float value);

private:
    std::unordered_map<std::string, GLint> uniformCache;
    GLint getUniformLocation(const std::string& name);
    std::string loadShaderSource(const char* path);
    GLuint compileShader(GLenum type, const std::string& source);
};

#endif