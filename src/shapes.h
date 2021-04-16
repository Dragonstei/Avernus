#ifndef SHAPES_H
#define SHAPES_H

// Include GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// Include GLFW
#include <GLFW/glfw3.h>

// Includge GLM
#include <glm/glm.hpp>
using namespace glm;

class Shapes{
    private:
        float vertices[6];

    public:
        Shapes();
        ~Shapes();

        void getVertices();
    
};

#endif