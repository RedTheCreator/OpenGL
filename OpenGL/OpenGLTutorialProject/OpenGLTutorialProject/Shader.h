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
	//計二つのシェーダー
	static const unsigned int NUM_SHADERS = 2;
	//シェーダーの管理
	GLuint	m_program;
	//頂点シェーダーとフラグメントシェーダーを用意
	GLuint	m_shaders[NUM_SHADERS];
};