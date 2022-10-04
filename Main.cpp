#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
// IDHU window size changing callback
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	std::cout <<"Great to be here" << width << height << std::endl;
	glViewport(0, 0, width, height);
}

// Idhu button press panna track panni vela paka
void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		std::cout << "You Pressed it man!!, You did it.!" << std::endl;
		glfwSetWindowShouldClose(window, true);
}

int main()
{
	// Initialize GLFW
	glfwInit();

	// Tell GLFW what version of OpenGL we are using 
	// In this case we are using OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	// Tell GLFW we are using the CORE profile
	// So that means we only have the modern functions
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	//Setting as current context
	glfwMakeContextCurrent(window);

	// Graphics card ku etha mari content change pannika
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	//View port set pannika iruka ellathatym oru 2d scene ku change pannika
	glViewport(0, 0, 800, 600);

	// Window size change panna reflect panna
	void framebuffer_size_callback(GLFWwindow * window, int width, int height);

	// idhu callback set panna
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	//RENDER pandra edam idhan
	// render loop
	while (!glfwWindowShouldClose(window))
	{
		// input
		processInput(window);

		// rendering commands here
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// check and call events and swap the buffers
		glfwPollEvents();
		glfwSwapBuffers(window);
	}
	glfwTerminate();
	return 0;

}