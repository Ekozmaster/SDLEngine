#ifndef MESH_H
#define MESH_H

#include<GL/glew.h>
#include<glm/glm.hpp>

class Mesh {
	size_t verticesCount;
	size_t trianglesCount;
	glm::vec3 *vertices;
	GLuint *triangles;
public:
	Mesh();
	void SetVertices(glm::vec3 *verts, size_t vertsCount);
	glm::vec3 *GetVertices();
	void SetTriangles(GLuint *tris, size_t trisCount);
	GLuint *GetTriangles();
	size_t VerticesCount();
	size_t TrianglesCount();
};

#endif
