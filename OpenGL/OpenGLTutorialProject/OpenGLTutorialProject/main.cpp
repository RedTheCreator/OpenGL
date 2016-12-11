#include <iostream>
#include <GL/glew.h>
#include "Display.h"
#include "Mesh.h"
#include "Shader.h"
#include "Texture.h"
#include "Transform.h"
#include "Camera.h"

#define WIDTH 800
#define HEIGHT 600

int main(int argc, char** argv)
{
	Display display(800, 600, "Hello World");
	//ŽOŠp‚ð•`‚­
	Vertex vertices[] = {
		Vertex(glm::vec3(-0.5, -0.5, 0), glm::vec2(0,0)),		//¶‰º
		Vertex(glm::vec3(0, 0.5, 0), glm::vec2(0.5,1.0)),		//ã
		Vertex(glm::vec3(0.5, -0.5, 0), glm::vec2(1.0,0)) };	//‰E‰º

	unsigned int indices[] = { 0, 1, 2 };
	Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]), indices, sizeof(indices) / sizeof(indices[0]));
	Mesh mesh2("./res/monkey3.obj");

	//ŽlŠp‚ð•`‚­
	//  Vertex vertices[] = {
	//	Vertex(glm::vec3(-0.5,-0.5,0)),
	//	Vertex(glm::vec3(-0.5, 0.5, 0)),
	//	Vertex(glm::vec3(0.5, 0.5, 0)),
	//	Vertex(glm::vec3(0.5, -0.5, 0))
	//};

	//Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]));*/


	Shader shader("./res/basicShader");

	Texture texture("./res/bricks.jpg");

	Camera	camera(glm::vec3(0, 0, -4), 70, (float)WIDTH / (float)HEIGHT, 0.01, 1000.0f);

	Transform transform;

	float counter = 0.0f;

	while (!display.IsClosed())
	{
		display.Clear(0.0f, 0.15f, 0.3f, 1.0f);

		float sinCounter = sinf(counter);
		float cosCounter = cosf(counter);
		transform.GetPos()->x = sinCounter;
		//transform.GetPos()->z = sinCounter;
		transform.GetRot()->x = counter * 10;
		//transform.GetRot()->y = counter * 10;

		//transform.GetRot()->z = counter * 1;
		//transform.SetScale(glm::vec3(cosCounter, cosCounter, cosCounter));

		shader.Bind();
		texture.Bind();

		shader.Update(transform, camera);
		mesh2.DrawTriangle();

		//mesh.DrawQuad();

		display.Update();

		counter += 0.0005f;
	}

	return 0;
}