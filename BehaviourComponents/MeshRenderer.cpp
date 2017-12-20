#include"MeshRenderer.h"
#include"Transform.h"
#include<glm/gtc/matrix_transform.hpp>
#include"../BehaviourComponents/Camera.h"

MeshRenderer::MeshRenderer(){
	mesh = NULL;
	material = NULL;
	loaded = false;
}

MeshRenderer::~MeshRenderer(){

}

void MeshRenderer::SetMesh(Mesh* ms){
	mesh = ms;
	loaded = false;
}

Mesh *MeshRenderer::GetMesh(){
	return mesh;
}

void MeshRenderer::SetMaterial(Material* mat){
	material = mat;
	loaded = false;
}

Material *MeshRenderer::GetMaterial(){
	return material;
}

GLfloat *MeshRenderer::GetVerticesFloatsFromMesh(){
	GLfloat *result = new GLfloat[mesh->VerticesCount()*3];
	glm::vec3 *vertices = mesh->GetVertices();
	for(size_t i=0; i < mesh->VerticesCount(); i++){
		result[i*3] = vertices[i].x;
		result[i*3+1] = vertices[i].y;
		result[i*3+2] = vertices[i].z;
	}
	return result;
}

GLuint *MeshRenderer::GetTrianglesIntsFromMesh(){
	GLuint *result = new GLuint[mesh->TrianglesCount()];
	GLuint *triangles = mesh->GetTriangles();
	for(size_t i=0; i<mesh->TrianglesCount(); i++){
		result[i] = triangles[i];
	}
	return result;
}

void MeshRenderer::SetupMesh(){
	glGenBuffers(1, vbo);
	glGenVertexArrays(1, vao);
	glBindVertexArray(vao[0]);
	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);

	// TODO: deallocate GLfloat array returned by GetFloatsFromMesh()
	GLfloat *vertices = GetVerticesFloatsFromMesh();
	glBufferData(GL_ARRAY_BUFFER, mesh->VerticesCount() * sizeof(GLfloat) * 3, vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);

	glGenBuffers(1, vio);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vio[0]);
	GLuint *triangles = GetTrianglesIntsFromMesh();

	glBufferData(GL_ELEMENT_ARRAY_BUFFER, mesh->TrianglesCount() * sizeof(GLuint), triangles, GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void MeshRenderer::ClearMesh(){
	glDisableVertexAttribArray(0);
	glDeleteBuffers(1, vbo);
	glDeleteBuffers(1, vio);
	glDeleteVertexArrays(1, vao);
}

void MeshRenderer::SetupMaterial(){
	material->LoadShader("SimpleDiffuse");
}

void MeshRenderer::ClearMaterial(){
	material->OnQuit();
}

void MeshRenderer::LoadUp(){
	ClearMesh();
	ClearMaterial();
	if(mesh && material) {
		SetupMesh();
		SetupMaterial();
		loaded = true;
	} else if(mesh) {
		material = new Material();
		SetupMaterial();
		SetupMesh();
		loaded = true;
	} else {
		loaded = false;
	}
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void MeshRenderer::OnInit(){

}

void MeshRenderer::OnRender(){
	if(loaded){
		material->OnRenderBegin();
		glEnableClientState(GL_VERTEX_ARRAY);
		glBindVertexArray(vao[0]);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vio[0]);
		glEnableVertexAttribArray(0);

		glm::mat4 cameraMatrix = Camera::main->GetCameraMatrix();
		glm::mat4 modelViewMatrix = ((Transform*)(attachedGameObject->GetTransform()))->GetModelViewMatrix();
		material->SetMVPMatrix(cameraMatrix * modelViewMatrix);

		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, (void*)0);

		glDisableVertexAttribArray(0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
		glDisableClientState(GL_VERTEX_ARRAY);
		material->OnRenderEnd();
	} else LoadUp();
}

void MeshRenderer::OnQuit(){
	ClearMesh();
	ClearMaterial();
	delete(mesh);
	delete(material);
}

void MeshRenderer::Start(){

}

void MeshRenderer::Update(){

}

void MeshRenderer::OnDestroy(){

}
