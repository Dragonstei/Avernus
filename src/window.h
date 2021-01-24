#ifndef WINDOW_H
#define WINDOW_H

#endif

// Include GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// Include GLFW
#include <GLFW/glfw3.h>

// Includge GLM
#include <glm/glm.hpp>
using namespace glm;

class Window{
    public:
    Window(const char* title, int width, int height);
    ~Window();

    private:
    int w_Width, w_Height;
    const char* w_Title;
};