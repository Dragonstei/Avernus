#include "window.h"

Window::Window(int width, int height, const char* title){
  w_Width = width;
  w_Height = height;
  w_Title = title;
  return;
}

Window::~Window(){

}

void Window::createWindow(int w_Width, int w_Height, const char* w_Title){
  GLFWwindow window = glfwCreateWindow(int w_Width, int w_Height, const char* w_Title, NULL, NULL); 
}