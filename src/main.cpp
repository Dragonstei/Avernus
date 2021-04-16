// OpenGL libraries
#define GLEW_STATIC
#include <GL/glew.h>
// Include GLFW
#include <GLFW/glfw3.h>

// Include standard libraries
#include <iostream>
#include <cmath>

// Include project headers
#include "settings.h"
#include "shader.h"
// #include "window.h"

<<<<<<< HEAD
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);
=======
#include "shapes.h"
#include "window.h"
>>>>>>> f49474cdc56175d030606655ca60f464aaece22b

// Settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

// OpenGL Shading Language (GLSL)
/*
    Shaders worden in een C-like language genaamd GLSL

    Shaders beginnen altijd met een versie nummer, gevolgd
    door een lijst van input/output variabelen, uniforms
    en z'n main functie
*/
// Vertex shader
const char *vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n" // Position has attribute position 0
    "layout (location = 1) in vec3 aColor;\n"
    "out vec3 ourColor;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos, 1.0);\n" // Giving a vec3 to vec4's constructor, homogenous coordinates 
    "   ourColor = aColor;\n"
    "}\0";

// Fragment shader
const char *fragmentShaderSource = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "in vec3 ourColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(ourColor, 1.0);\n"
    "}\0";

int main()
{

    glfwInit();

    // Create OpenGL context
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // OpenGL 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // We don't want the old OpenGL
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy

    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "OpenGL", nullptr, nullptr); // Windowed
    if (window == NULL) {
        printf("Failed to create GLFW window");
        glfwTerminate();
        return -1;
    }
    std::cout << "GLFW window created" << std::endl;

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        printf("Failed to initialize GLEW\n");
        return -1;
    }
    std::cout << "GLEW initialized" << std::endl;

    // OpenGL guarantees atleast 16 attributes available, some hardware may support more 
    int nrAttributes;
    glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttributes);
    std::cout << "Maximum nr of vertex attributes supported: " << nrAttributes << std::endl;

    glViewport(0, 0, SCR_WIDTH, SCR_HEIGHT);

// Setting up shaders
// --------------------------------------------------

    char infoLog[512];

    // Vertex shader compile
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    // Compiling the shader into code that can be executed by the GPU
    glCompileShader(vertexShader);
    // Checking if shader compiled
    GLint vertexStatus;
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &vertexStatus);
    std::cout << "Vertex Shader compiler Status: " << vertexStatus << std::endl;

    // Retrieving vertex shader compile log
    if(!vertexStatus) {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    // Fragment shader compile
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);

    glCompileShader(fragmentShader);

    GLint fragmentStatus;
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &fragmentStatus);
    std::cout << "Fragment Shader compiler Status: " << fragmentStatus << std::endl;
    if (!fragmentStatus)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

// --------------------------------------------------

    // Combining shaders into program
    GLuint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    // Linking the program
    glLinkProgram(shaderProgram);
    // Program status
    GLint programStatus;
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &programStatus);
    // Retrieving shader linking log
    if(!programStatus) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
    }
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

<<<<<<< HEAD
// --------------------------------------------------

    float vertices[] = {
        // positions            // colors
         0.5f, -0.5f, 0.0f,     1.0f, 0.0f, 0.0f, // bottom right
        -0.5f, -0.5f, 0.0f,     0.0f, 1.0f, 0.0f, // bottom left
         0.0f,  0.5f, 0.0f,     0.0f, 0.0f, 1.0f  // top
    };

/*     // Vertices for triangle
    float vertices[] = { // Vertices 1-3 (X, Y, Z=0.0)
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.0f,  0.5f, 0.0f
    }; */

/*     // Vertices for rectangle
    float vertices[] = {
         0.5f,  0.5f, 0.0f, // top right
         0.5f, -0.5f, 0.0f, // bottom right
        -0.5f, -0.5f, 0.0f, // bottom left
        -0.5f,  0.5f, 0.0f // top left
    }; */

/*     unsigned int indices[] = {
        0, 1, 3,
        1, 2, 3
    }; */

    // Vertex Buffer Object. Uploads the vertex data to the GPU
    // Vertex Array Object
    GLuint VBO, VAO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    // Bind VAO first, then bind and set vertex buffer(s), then configure vertex attribute(s)
    glBindVertexArray(VAO);
    
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    // Copy the vertices array in a vertex buffer
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
   /*  // Copy the index array in an element buffer
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW); */

    // Vertex Attribute Pointers
    // Position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // Color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*) (3* sizeof(float)));
    glEnableVertexAttribArray(1);

    // Because glVertexAttribPointer called to the VBO, we can safely unbind it
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    // Unbind VAO so other VAO calls won't accidentily modify this
    glBindVertexArray(0);

    // Wireframe mode
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    // Render loop
    while(!glfwWindowShouldClose(window)) {
        // Input
        processInput(window);

        // Rendering commands
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Using the program
        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);

// Changing green value over time
/*         float timeValue = glfwGetTime();
        float greenValue = (sin(timeValue) / 2.0f) + 0.5f;
        int vertexColorLocation = glGetUniformLocation(shaderProgram, "ourColor");
        glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f); */

        glDrawArrays(GL_TRIANGLES, 0, 3);
        // glDrawElements(GL_TRIANGLES, sizeof(indices), GL_UNSIGNED_INT, 0);

        // Swap buffer and check IO events
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // De-allocate all resources once they've outlived their use
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    glDeleteProgram(shaderProgram);

    glfwTerminate();
    return 0;

    //Window w;
    //w.initWindow();
    //w.createWindow(1280, 720, "PropManipulator");
=======
/* General pipeline
while (windowOpen) {
    while (event = newEvent())
        handleEvent(event);

    updateScene();

    drawGraphics();
    presentGraphics();
}
*/

return 0;
>>>>>>> f49474cdc56175d030606655ca60f464aaece22b
}

void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) glfwSetWindowShouldClose(window, GL_TRUE);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}