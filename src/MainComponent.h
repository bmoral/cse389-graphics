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
	float deltaTime = 0.0f;
	Camera camera;
	void processInput(GLFWwindow* window);
};

#endif /* MAINCOMPONENT_H_ */
