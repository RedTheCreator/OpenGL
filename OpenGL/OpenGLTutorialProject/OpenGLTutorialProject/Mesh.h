#pragma once

#include <glm/glm.hpp>
#include <GL/glew.h>

//頂点クラス
class Vertex
{
public:
	Vertex(const glm::vec3& pos)
	{
		this->pos = pos;
	}

private:
	glm::vec3 pos;
};

//メッシュクラス
class Mesh
{
public:
	Mesh(Vertex* vertices, unsigned int numVertices);
	~Mesh();

	void DrawTriangle();
	void DrawQuad();
private:
	enum
	{
		POSITION_VB,
		NUM_BUFFERS
	};
	GLuint		m_vertexArrayObject;
	GLuint		m_vertexArrayBuffers[NUM_BUFFERS];
	unsigned int m_drawCount;
};