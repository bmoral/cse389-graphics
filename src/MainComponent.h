/*
 * MainComponent.h
 *
 *  Created on: Apr 13, 2018
 *      Author: bmorales
 */

#ifndef MAINCOMPONENT_H_
#define MAINCOMPONENT_H_

#include "Window.h"
#include "camera.h"


class MainComponent {
public:
	MainComponent();
	void start();
	void stop();
private:
	void run();
	void render();
	void cleanUp();
	bool isRunning;
	static Camera camera;
	static float lastX;
	static float lastY;
	static bool fmouse;
	float deltaTime = 0.0f;
	float lastFrame = 0.0f;
	void processInput(GLFWwindow* window);
	static void mouse_callback(GLFWwindow* window, double xpos, double ypos);
};

#endif /* MAINCOMPONENT_H_ */
