/*
 * MainComponent.h
 *
 *  Created on: Apr 13, 2018
 *      Author: bmorales
 */

#ifndef MAINCOMPONENT_H_
#define MAINCOMPONENT_H_

class MainComponent {
public:
	MainComponent();
	void start();
	void stop();
private:
	void run();
	void render();
	void cleanUp();

};

#endif /* MAINCOMPONENT_H_ */
