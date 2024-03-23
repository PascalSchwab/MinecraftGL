#include "../lib/glad/glad.h"
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "mesh.h"

Mesh *initMesh(float vertices[], unsigned int verticeSize, unsigned int indices[], unsigned int indiceSize)
{
    Mesh *mesh = malloc(sizeof(Mesh));
    mesh->glBuffers[0] = NULL;
    mesh->glBuffers[1] = NULL;
    mesh->glBuffers[2] = NULL;
    mesh->vao = initVAO();

    glBindVertexArray(mesh->vao->id);

    mesh->glBuffers[0] = initIntGLBuffer(GL_ELEMENT_ARRAY_BUFFER, indices, indiceSize, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->glBuffers[0]->id);

    // Vertices
    mesh->glBuffers[1] = initFloatGLBuffer(GL_ARRAY_BUFFER, vertices, verticeSize, GL_DYNAMIC_DRAW);
    addAttributeGLBuffer(mesh->glBuffers[1], 0, 3);

    glBindVertexArray(0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    logInfo("Mesh was initialized");
    return mesh;
}

void disposeMesh(Mesh *mesh)
{
    disposeVAO(mesh->vao);
    for (int i = 0; i < sizeof(mesh->glBuffers) / sizeof(GLBuffer *) - 1; i++)
    { // Error
        disposeGLBuffer(mesh->glBuffers[i]);
    }
    logInfo("Mesh was disposed");
    free(mesh);
}