#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

static std::string ParseShader(const std::string& in_filepath) {
    std::ifstream stream(in_filepath);

    /// Check if the file is opened successfully
    if (!stream.is_open()) {
        std::cerr << "[ERROR] [ParseShader] Could not open file: " << in_filepath << std::endl;
        return "";
    }

	/// Read the file
    std::ostringstream ss;
    ss << stream.rdbuf();

    return ss.str();
}


static GLuint CompileGLProgram(GLenum in_shader_type, const std::string& in_src) {
    GLuint id = glCreateShader(in_shader_type);
    const char* src = in_src.c_str();
    glShaderSource(id, 1, &src, nullptr);;
    glCompileShader(id);

    int ret;
    glGetShaderiv(id, GL_COMPILE_STATUS, &ret);
    if (ret == GL_FALSE) {
        int len;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &len);;
        char* msg = (char*)_malloca(len * sizeof(char));
        glGetShaderInfoLog(id, len, &len, msg);
        std::cout << "[ERROR] [CompileShader] Failed to compile "
                  << (in_shader_type == GL_VERTEX_SHADER ? "vertex" : "fragment")
                  << " shader!" << std::endl;
		std::cout << msg << std::endl;
		glDeleteShader(id);

		return 0;
    }

    return id;
}


static GLuint CreateGLProgram(const std::string& in_vertex_shader, const std::string& in_fragment_shader) {
    GLuint program = glCreateProgram();
    GLuint vertex_shader = CompileGLProgram(GL_VERTEX_SHADER, in_vertex_shader);
    GLuint fragment_shader = CompileGLProgram(GL_FRAGMENT_SHADER, in_fragment_shader);

    glAttachShader(program, vertex_shader);
    glAttachShader(program, fragment_shader);
    glLinkProgram(program);
    glValidateProgram(program);

    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);

    return program;
}

