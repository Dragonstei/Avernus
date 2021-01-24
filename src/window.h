#ifndef WINDOW_H
#define WINDOW_H

// Include GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// Include GLFW
#include <GLFW/glfw3.h>

// Includge GLM
#include <glm/glm.hpp>
using namespace glm;

/*
struct windowSettings{
    int width = 0;
    int height = 0;
    const char* title;
};
*/
class Window{
    private:
        int _width, _height;
    public:
        int w_Width, w_Height;
        const char* w_Title;

        Window(int width, int height, const char* title);
        ~Window();

        typedef struct GLFWwindow GLFWwindow;
        void createWindow(int w_Width, int w_Height, const char* w_Title);
    
};
#endif