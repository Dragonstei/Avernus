#ifndef WINDOW_H
#define WINDOW_H

// Include standard libraries
#include <iostream>

// Include standard headers
#include <stdio.h>
#include <stdlib.h>

// Include GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// Include GLFW
#include <GLFW/glfw3.h>

// Includge GLM
#include <glm/glm.hpp>
using namespace glm;

class Window{
    private:
        int w_Width, w_Height;
        const char* w_Title;

        GLFWwindow* window;
    public:
        Window();
        ~Window();

        int initWindow();
        int createWindow(int w_Width, int w_Height, const char* w_Title);
};

#endif