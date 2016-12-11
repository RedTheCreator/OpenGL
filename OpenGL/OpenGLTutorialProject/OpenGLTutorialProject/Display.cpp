#include "Display.h"
#include "GL/glew.h"
#include <iostream>

//�f�B�X�v���C�N���X
Display::Display(int width, int height, const std::string& title)
{
	//�S�Ă�����������
	SDL_Init(SDL_INIT_EVERYTHING);

	//��ʂ�RGBA�T�C�Y�ݒ�
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	//�o�b�t�@���p�ӁA���ŕ\��
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	//C����łł��Ă���̂ŁAstring��C���ꉻ����AOpenGL�ŊJ��
	m_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);
	//�R���e�N�X�g�����
	m_glContext = SDL_GL_CreateContext(m_window);

	GLenum	status = glewInit();

	//�G���[�̓����o��
	if (status != GLEW_OK)
	{
		std::cerr << "Glew Init failure" << std::endl;
	}

	m_isClosed = false;

	glEnable(GL_DEPTH_TEST);
}

//�f�X�g���N�^
Display::~Display()
{
	//�R���e�N�X�g���폜
	SDL_GL_DeleteContext(m_glContext);
	//�E�B���h�E������
	SDL_DestroyWindow(m_window);
	//SDL���I��
	SDL_Quit();
}

//�X�V
void Display::Update()
{
	//�E�B���h�E�ƃo�b�t�@�̌���
	SDL_GL_SwapWindow(m_window);
	//�C�x���g�Ǘ�
	SDL_Event e;

	while (SDL_PollEvent(&e))
	{
		if (e.type == SDL_QUIT)
		{
			m_isClosed = true;
		}
	}
}

bool Display::IsClosed()
{
	return m_isClosed;
}

void Display::Clear(float r, float g, float b, float a)
{
	glClearColor(r, g, b, a);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

}