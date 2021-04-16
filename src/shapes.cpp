#include "shapes.h"

Shapes::Shapes(){

}

Shapes::~Shapes(){
    
}

void Shapes::getVertices(){
    float vertices[6] = {
           0.0f,  0.5f,
           0.5f, -0.5f,
          -0.5f, -0.5f  
        };



    GLuint vbo;
    glGenBuffers(1, &vbo);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW)

}