#include"Mesh.h"

Mesh::Mesh(){
	verticesCount = 0;
	trianglesCount = 0;
	vertices = NULL;
	triangles = NULL;
}

void Mesh::SetVertices(glm::vec3 *verts, size_t vertsCount){
	if(vertices) delete[] vertices;
	vertices = new glm::vec3[vertsCount];// = glm::vec3[vertsCount];
	for(size_t i=0; i<vertsCount; i++){
		vertices[i] = verts[i];
	}
	verticesCount = vertsCount;
}

glm::vec3 *Mesh::GetVertices(){
	return vertices;
}

void Mesh::SetTriangles(GLuint *tris, size_t trisCount){
	if(triangles) delete[] triangles;
	triangles = new GLuint[trisCount];
	for(size_t i=0; i<trisCount; i++){
		triangles[i] = tris[i];
	}
	trianglesCount = trisCount;
}

GLuint *Mesh::GetTriangles(){
	return triangles;
}

size_t Mesh::VerticesCount(){
	return verticesCount;
}

size_t Mesh::TrianglesCount(){
	return trianglesCount;
}
