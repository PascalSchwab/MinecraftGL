#include "../lib/glad/glad.h"
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "opengl.h"
#include "logger.h"

GLBuffer *initIntGLBuffer(int bufferType, unsigned int data[], unsigned int dataSize, int drawType)
{
    GLBuffer *glBuffer = malloc(sizeof(GLBuffer));
    glBuffer->id = 0;
    glBuffer->bufferType = bufferType;
    glBuffer->drawType = drawType;
    glGenBuffers(1, &glBuffer->id);
    glBindBuffer(bufferType, glBuffer->id);
    glBufferData(bufferType, dataSize, data, drawType);
    glBindBuffer(bufferType, 0);
    logInfo("Int-GLBuffer %d was initialized", glBuffer->id);
    return glBuffer;
}

GLBuffer *initFloatGLBuffer(int bufferType, float data[], unsigned int dataSize, int drawType)
{
    GLBuffer *glBuffer = malloc(sizeof(GLBuffer));
    glBuffer->id = 0;
    glBuffer->bufferType = bufferType;
    glBuffer->drawType = drawType;
    glGenBuffers(1, &glBuffer->id);
    glBindBuffer(bufferType, glBuffer->id);
    glBufferData(bufferType, dataSize, data, drawType);
    glBindBuffer(bufferType, 0);
    logInfo("Float-GLBuffer %d was initialized", glBuffer->id);
    return glBuffer;
}

void addAttributeGLBuffer(const GLBuffer *glBuffer, int index, int count)
{
    glBindBuffer(glBuffer->bufferType, glBuffer->id);
    glVertexAttribPointer(index, count, GL_FLOAT, GL_FALSE, count * sizeof(float), (void *)0);
    glEnableVertexAttribArray(index);
    glBindBuffer(glBuffer->bufferType, 0);
}

VAO *initVAO()
{
    VAO *vao = malloc(sizeof(VAO));
    vao->id = 0;
    glGenVertexArrays(1, &vao->id);
    logInfo("VAO %d was initialized", vao->id);
    return vao;
}

void disposeGLBuffer(GLBuffer *glBuffer)
{
    glDeleteBuffers(1, &glBuffer->id);
    logInfo("GLBuffer %d was disposed", &glBuffer->id);
    free(glBuffer);
}

void disposeVAO(VAO *vao)
{
    glDeleteVertexArrays(1, &vao->id);
    logInfo("VAO %d was disposed", &vao->id);
    free(vao);
}