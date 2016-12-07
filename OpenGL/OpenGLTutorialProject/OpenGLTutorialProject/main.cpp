#include <iostream>
#include <GL/glew.h>
#include "Display.h"
#include "Mesh.h"
#include "Shader.h"

int main(int argc, char** argv)
{
	Display display(800, 600, "Hello World");
	//OŠp‚ğ•`‚­
	Vertex vertices[] = {
		Vertex(glm::vec3(-0.5, -0.5, 0)),		//¶‰º
		Vertex(glm::vec3(0, 0.5, 0)),		//ã
		Vertex(glm::vec3(0.5, -0.5, 0)) };	//‰E‰º

	Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]));

	//lŠp‚ğ•`‚­
	//  Vertex vertices[] = {
	//	Vertex(glm::vec3(-0.5,-0.5,0)),
	//	Vertex(glm::vec3(-0.5, 0.5, 0)),
	//	Vertex(glm::vec3(0.5, 0.5, 0)),
	//	Vertex(glm::vec3(0.5, -0.5, 0))
	//};

	//Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]));*/


	Shader shader("./res/basicShader");


		while (!display.IsClosed())
		{
			display.Clear(0.0f, 0.15f, 0.3f, 1.0f);
			
			mesh.DrawTriangle();
			shader.Bind();
			//mesh.DrawQuad();

			display.Update();
		}

	return 0;
}