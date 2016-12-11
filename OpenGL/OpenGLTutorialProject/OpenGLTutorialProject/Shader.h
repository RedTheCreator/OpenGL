#pragma once

#include "GL/glew.h"
#include <string>
#include "Transform.h"
#include "Camera.h"

class Shader
{
public:
	Shader(const std::string& fileName);
	void Bind();
	void Update(const Transform& transform, const Camera& camera);
	~Shader();
private:
	//�v��̃V�F�[�_�[
	static const unsigned int NUM_SHADERS = 2;
	enum
	{
		TRANSFORM_U,
		NUM_UNIFORM
	};
	//�V�F�[�_�[�̊Ǘ�
	GLuint	m_program;
	//���_�V�F�[�_�[�ƃt���O�����g�V�F�[�_�[��p��
	GLuint	m_shaders[NUM_SHADERS];
	GLuint	m_uniforms[NUM_UNIFORM];
};