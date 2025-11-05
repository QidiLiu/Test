#ifndef OPENGLEXAMPLE_OPENGLEXAMPLE_H
#define OPENGLEXAMPLE_OPENGLEXAMPLE_H

#include <iostream>
#include <filesystem>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "include/OpenGLExampleUtil.hpp"

/// @brief The OpenGLExample class
class OpenGLExample {
public:

    /// @brief Constructor of OpenGLExample
    OpenGLExample();

    /// @brief Destructor of OpenGLExample
    ~OpenGLExample();

    int Run();

private:

	int ExampleFunc();
};


#endif // OPENGLEXAMPLE_OPENGLEXAMPLE_H
