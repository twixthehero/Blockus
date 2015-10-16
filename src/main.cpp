#include <GL\glew.h>
#include <GLFW\glfw3.h>

#include <iostream>

#include "color.h"
#include "shader.h"
#include "shadermanager.h"

using namespace std;

//CORNFLOWER BLUE
Color CB(101, 156, 239);

float points[] =
{
	0, 0.5f, 0,
	0.5f, -0.5f, 0,
	-0.5f, -0.5f, 0
};

float colors[] =
{
	1.0f, 0, 0,
	0, 1.0f, 0,
	0, 0, 1.0f
};

GLuint vao = 0;
GLuint vbo = 0;
GLuint vco = 0;

ShaderManager sm;

void init()
{
	glClearColor(0, 0, 0, 1);

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), points, GL_STATIC_DRAW);

	glGenBuffers(1, &vco);
	glBindBuffer(GL_ARRAY_BUFFER, vco);
	glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), colors, GL_STATIC_DRAW);

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	glBindBuffer(GL_ARRAY_BUFFER, vco);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, NULL);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	sm.init();
}

void update()
{

}

void render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glUseProgram(sm.getDefaultShader());
	glBindVertexArray(vao);

	glDrawArrays(GL_TRIANGLES, 0, 3);

	glFlush();
}

int main()
{
	if (!glfwInit())
		return -1;

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	glfwWindowHint(GLFW_SAMPLES, 4);

	GLFWwindow* window = glfwCreateWindow(1280, 720, "Blockus", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK)
	{
		glfwTerminate();
		return -1;
	}

	const GLubyte* renderer = glGetString(GL_RENDERER);
	const GLubyte* version = glGetString(GL_VERSION);
	cout << "Renderer: " << renderer << endl;
	cout << "Open GL Version: " << version << endl;

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	init();
	while (!glfwWindowShouldClose(window))
	{
		update();
		render();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();

	return 0;
}