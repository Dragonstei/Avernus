// Include standard headers
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <GLFW/glfw3.h> 

// Include GLM
#include <glm/glm.hpp>

// GUI header files
#include "./gui/window.h"



int main() {
    // Initialise GLFW
    glewExperimental = true; // Needed for core profile
    if( !glfwInit()) {
        std::cout << "Failed to initialize GLFW\n";
        return -1;
    }

    std::cout << "Hello, World!";
    std::cin.get();

    return 0;
}
