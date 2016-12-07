#include "Mesh.h"

Mesh::Mesh(Vertex* vertices, unsigned int numVertices)
{
	//描く点数
	m_drawCount = numVertices;

	//頂点配列の生成とバインド
	glGenVertexArrays(1, &m_vertexArrayObject);	//数量と名前
	glBindVertexArray(m_vertexArrayObject);		//名前
	//頂点バッファの生成とバインド
	glGenBuffers(NUM_BUFFERS, m_vertexArrayBuffers);
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[POSITION_VB]);
	glBufferData(GL_ARRAY_BUFFER, numVertices*sizeof(vertices[0]), vertices, GL_STATIC_DRAW);

	//シェーダーに必要な属性を起動する
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	//頂点配列を初期化する
	glBindVertexArray(0);
}

Mesh::~Mesh()
{
	//頂点配列を削除
	glDeleteVertexArrays(1, &m_vertexArrayObject);	//数量と名前
}

void Mesh::DrawTriangle()
{
	//頂点配列をバインド
	glBindVertexArray(m_vertexArrayObject);

	glDrawArrays(GL_TRIANGLES, 0, m_drawCount);
	//頂点配列を初期化
	glBindVertexArray(0);

}

void Mesh::DrawQuad()
{
	//頂点配列をバインド
	glBindVertexArray(m_vertexArrayObject);

	glDrawArrays(GL_QUADS, 0, m_drawCount);
	//頂点配列を初期化
	glBindVertexArray(0);

}