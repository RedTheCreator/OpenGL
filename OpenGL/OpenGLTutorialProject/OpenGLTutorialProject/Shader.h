#pragma once

#include "GL/glew.h"
#include <string>

class Shader
{
public:
	Shader(const std::string& fileName);
	void Bind();
	~Shader();
private:
	//�v��̃V�F�[�_�[
	static const unsigned int NUM_SHADERS = 2;
	//�V�F�[�_�[�̊Ǘ�
	GLuint	m_program;
	//���_�V�F�[�_�[�ƃt���O�����g�V�F�[�_�[��p��
	GLuint	m_shaders[NUM_SHADERS];
};