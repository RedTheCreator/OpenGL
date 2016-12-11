#include "Display.h"
#include "GL/glew.h"
#include <iostream>

//ディスプレイクラス
Display::Display(int width, int height, const std::string& title)
{
	//全てを初期化する
	SDL_Init(SDL_INIT_EVERYTHING);

	//画面のRGBAサイズ設定
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	//バッファを二つ用意、交代で表示
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	//C言語でできているので、stringをC言語化する、OpenGLで開く
	m_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);
	//コンテクストを作る
	m_glContext = SDL_GL_CreateContext(m_window);

	GLenum	status = glewInit();

	//エラーの投げ出し
	if (status != GLEW_OK)
	{
		std::cerr << "Glew Init failure" << std::endl;
	}

	m_isClosed = false;

	glEnable(GL_DEPTH_TEST);
}

//デストラクタ
Display::~Display()
{
	//コンテクストを削除
	SDL_GL_DeleteContext(m_glContext);
	//ウィンドウを消す
	SDL_DestroyWindow(m_window);
	//SDLを終了
	SDL_Quit();
}

//更新
void Display::Update()
{
	//ウィンドウとバッファの交換
	SDL_GL_SwapWindow(m_window);
	//イベント管理
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