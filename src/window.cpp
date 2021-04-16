#include "shapes.h"
#include "window.h"

Window::Window(void){
  std::cout << "Window object is being created" << std::endl;
}

Window::~Window(void){
  std::cout << "Window object is being deleted" << std::endl;
}

int Window::initWindow(){
  // Initialise GLFW
  glewExperimental = GL_TRUE; // Needed for core profile
  if( !glfwInit() ) {
    fprintf( stderr, "Failed to initialize GLFW\n" );
    return -1;
  }

glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // Atleast OpenGL 3.2
glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // We don't want the old OpenGL

glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

return 0;
}

int Window::createWindow(int w_Width, int w_Height, const char* w_Title){

  GLFWwindow* window;
  window = glfwCreateWindow(w_Width, w_Height, w_Title, nullptr, nullptr); // First nullptr for windowed, glfwGetPrimaryMonitor() for fullscreen.

  if( window == NULL ) {
    fprintf( stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible.\n" );
    glfwTerminate();
    return -1;
  }

  glfwMakeContextCurrent(window); // Initialize GLEW
  glewExperimental = GL_TRUE; // Needed in core profile
  glewInit();
  if (glewInit() != GLEW_OK) {
    fprintf(stderr, "Failed to initialize GLEW\n");
    return -1;
  }

GLuint VertexArrayID;
glGenVertexArrays(1, &VertexArrayID);
glBindVertexArray(VertexArrayID);

static const GLfloat g_vertex_buffer_data[] = {
   -1.0f, -1.0f, 0.0f,
   1.0f, -1.0f, 0.0f,
   0.0f,  1.0f, 0.0f,
};

GLuint vertexBuffer;
glGenBuffers(1, &vertexBuffer);
glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

/*Shapes triangle;
triangle.getVertices();*/


// Ensure we can capture the escape key being pressed below
glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

//while(!glfwWindowShouldClose(window)){
do{
    // Clear the screen to prevent flickering.
    glClear( GL_COLOR_BUFFER_BIT );

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glVertexAttribPointer(
      0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
      3,                  // size
      GL_FLOAT,           // type
      GL_FALSE,           // normalized?
      0,                  // stride
      (void*)0            // array buffer offset
    );

    glDrawArrays(GL_TRIANGLES, 0, 3); // Starting from vertex 0; 3 vertices total -> 1 triangle
    glDisableVertexAttribArray(0);

    // Swap buffers
    glfwSwapBuffers(window);
    glfwPollEvents();

} 

// Check if the ESC key was pressed or the window was closed
while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
       glfwWindowShouldClose(window) == 0);

return 0;
}