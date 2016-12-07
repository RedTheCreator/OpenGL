#include "Mesh.h"

Mesh::Mesh(Vertex* vertices, unsigned int numVertices)
{
	//�`���_��
	m_drawCount = numVertices;

	//���_�z��̐����ƃo�C���h
	glGenVertexArrays(1, &m_vertexArrayObject);	//���ʂƖ��O
	glBindVertexArray(m_vertexArrayObject);		//���O
	//���_�o�b�t�@�̐����ƃo�C���h
	glGenBuffers(NUM_BUFFERS, m_vertexArrayBuffers);
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[POSITION_VB]);
	glBufferData(GL_ARRAY_BUFFER, numVertices*sizeof(vertices[0]), vertices, GL_STATIC_DRAW);

	//�V�F�[�_�[�ɕK�v�ȑ������N������
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	//���_�z�������������
	glBindVertexArray(0);
}

Mesh::~Mesh()
{
	//���_�z����폜
	glDeleteVertexArrays(1, &m_vertexArrayObject);	//���ʂƖ��O
}

void Mesh::DrawTriangle()
{
	//���_�z����o�C���h
	glBindVertexArray(m_vertexArrayObject);

	glDrawArrays(GL_TRIANGLES, 0, m_drawCount);
	//���_�z���������
	glBindVertexArray(0);

}

void Mesh::DrawQuad()
{
	//���_�z����o�C���h
	glBindVertexArray(m_vertexArrayObject);

	glDrawArrays(GL_QUADS, 0, m_drawCount);
	//���_�z���������
	glBindVertexArray(0);

}