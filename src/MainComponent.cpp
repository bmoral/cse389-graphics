/*
 * MainComponent.cpp
 *
 *  Created on: Apr 13, 2018
 *      Author: bmorales
 */

#include "MainComponent.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "shader.h"
#include "model.h"

//create static camera
Camera MainComponent::camera(glm::vec3(0.0f, -1.0f, 3.0f));
float MainComponent::lastX = Window::SCR_WIDTH / 2.0f;
float MainComponent::lastY = Window::SCR_HEIGHT / 2.0f;
bool MainComponent::fmouse = true;

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

	//set input mouse callback
	glfwSetCursorPosCallback(Window::getWindow(), mouse_callback);
	glfwSetScrollCallback(Window::getWindow(), scroll_callback);
	glfwSetInputMode(Window::getWindow(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	//build and compile shader
	Shader shader("./src/model_loading.vs", "./src/model_loading.fs");

	//load models
	Model model("./misc/objects/museum.obj");


	//render loop
	while(isRunning) {
		//Frame time logic
		float currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		//input processor (keyboard)
		processInput(Window::getWindow());

		//Close and clean up if close is requested
		if(Window::shouldClose())
			stop();

		// background color of screen
		glClearColor(0.1f, 0.1f, 0.5f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//enable shader
		shader.use();


		glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)Window::SCR_WIDTH / (float)Window::SCR_HEIGHT, 0.1f, 100.0f);
	    glm::mat4 view = camera.GetViewMatrix();
	    //view = camera.GetViewMatrix();
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

/**
 * Whenever mouse is moved, this is called
 */
void MainComponent::mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
	float xoffset = 0.0;
	float yoffset = 0.0;

	if (fmouse){
		lastX = xpos;
		lastY = ypos;
		fmouse = false;
	}

	xoffset = xpos - lastX;
	yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

	lastX = xpos;
	lastY = ypos;

	camera.ProcessMouseMovement(xoffset, yoffset);
}

/**
 * mouse scroll wheel callback, to process zoom
 */
void MainComponent::scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	camera.ProcessMouseScroll(yoffset);
}
