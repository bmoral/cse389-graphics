/*
 * MainComponent.cpp
 *
 *  Created on: Apr 13, 2018
 *      Author: bmorales
 */

#include "MainComponent.h"
#include "shader.h"
#include "model.h"

/**
 * Initialize and instance of the engine to be not running
 */
MainComponent::MainComponent() {
	isRunning = false;
}

/**
 * Sest up and start the engine to drive the 3D world
 */
void MainComponent::start()
{
	//if running turn ignore and do nothing
	if(isRunning)
		return;

	//execute code to initialize and start program

	// glad: load all OpenGL function pointers
	if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
		std::cout << "Failed to initialize GLAD" << std::endl;
		return;
	}

	//Configure global opengl state
	glEnable(GL_DEPTH_TEST);

	//Run 3d rendering
	run();
}

/**
 * Stop running the engine driving the 3D world
 */
void MainComponent::stop()
{
	if(!isRunning)
		return;
	//Change state of running program
	isRunning = false;
}

/**
 * Run the engine
 */
void MainComponent::run()
{
	//change state to running
	isRunning = true;

	//get screen dimensions
	int width, height;
	glfwGetWindowSize(Window::getWindow(), &width, &height);

	glClearColor(0.05f, 0.05f, 0.05f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//build and compile shader
	Shader shader("./src/model_loading.vs", "./src/model_loading.fs");

	//load models
	Model model("./misc/objects/Pikachu.obj");

	// Timing
	float lastFrame = 0.0f;

	//input
	camera = Camera(glm::vec3(0.0f, 0.0f, 3.0f));

	//render loop
	while(isRunning) {
		//Frame time logic
		float currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		//input processor
		processInput(Window::getWindow());

		//Close and clean up if close is requested
		if(Window::shouldClose())
			stop();

		//enable shader
		shader.use();


		glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)width / (float)height, 0.1f, 100.0f);
	    glm::mat4 view = camera.GetViewMatrix();
	    shader.setMat4("projection", projection);
	    shader.setMat4("view", view);


		glm::mat4 m;
		m = glm::translate(m, glm::vec3(0.0f, -1.75f, 0.0f)); // translate it down so it's at the center of the scene
		m = glm::scale(m, glm::vec3(0.2f, 0.2f, 0.2f));	// it's a bit too big for our scene, so scale it down
		shader.setMat4("model", m);
		model.Draw(shader);

		render();
	}

	//Clean-Up when render loop exits
	cleanUp();
}

/**
 * Elements to render
 */
void MainComponent::render()
{

	Window::render();
}

/**
 * Clean up before exiting
 */
void MainComponent::cleanUp()
{
	Window::windowClean();
}

/**
 * Process User input
 */
void MainComponent::processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        camera.ProcessKeyboard(FORWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        camera.ProcessKeyboard(BACKWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        camera.ProcessKeyboard(LEFT, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
    	camera.ProcessKeyboard(RIGHT, deltaTime);
}
