#include "window.h"

Window::Window(const char* title, int width, int height){
  w_Title = title;
  w_Width = width;
  w_Height = height;

  GLFWwindow* window;
  window = glfwCreateWindow(w_Width, w_Height, w_Title, NULL, NULL);

}

Window::~Window(){

}