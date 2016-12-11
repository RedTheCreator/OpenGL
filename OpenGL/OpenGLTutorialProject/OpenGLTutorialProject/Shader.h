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
	//計二つのシェーダー
	static const unsigned int NUM_SHADERS = 2;
	enum
	{
		TRANSFORM_U,
		NUM_UNIFORM
	};
	//シェーダーの管理
	GLuint	m_program;
	//頂点シェーダーとフラグメントシェーダーを用意
	GLuint	m_shaders[NUM_SHADERS];
	GLuint	m_uniforms[NUM_UNIFORM];
};