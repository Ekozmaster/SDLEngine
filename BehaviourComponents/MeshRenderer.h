#ifndef MESHRENDERER_H
#define MESHRENDERER_H

#include"BehaviourComponent.h"
#include"../DataStructures/Mesh.h"
#include"../EngineBase/Material.h"
#include<GL/glew.h>

class MeshRenderer : public BehaviourComponent {
private:
	Mesh *mesh;
	Material *material;
	GLuint vao[1], vbo[1], vio[1];
	bool loaded;
	GLfloat *GetVerticesFloatsFromMesh();
	GLuint *GetTrianglesIntsFromMesh();
	void SetupMesh();
	void ClearMesh();
	void SetupMaterial();
	void ClearMaterial();
	void LoadUp();
public:
	MeshRenderer();
	~MeshRenderer();

	void SetMesh(Mesh *ms);
	Mesh *GetMesh();
	void SetMaterial(Material *ms);
	Material *GetMaterial();

	void OnInit();
	void OnRender();
	void OnQuit();
	void Start();
	void Update();
	void OnDestroy();
};

#endif
