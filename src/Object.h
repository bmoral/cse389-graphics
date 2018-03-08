/******************************************************************************
	Name: Amy Knowles
	File Name: Object.h
	Synopsis: This file contains variable and function declarations for the 
			  Object class.
******************************************************************************/

#pragma once
#ifndef MODEL_VIEW_OBJECT_H
#define MODEL_VIEW_OBJECT_H
#endif

#include "includes.h"

class Object
{
	public:
		Object();
		Object(std::string fileName);
		void load(GLuint &program);
		void draw();
		void getObjInfo(std::string fileName);
		~Object();

	private:
		unsigned long numVert;
		unsigned long numNorm;
		unsigned long numFaces;
		unsigned long numIndex;

		std::vector<glm::vec4> vertList;
		std::vector<glm::vec4> tempVertList;
		std::vector<glm::vec4> normList;
		std::vector<GLuint> vertexIndex;
		std::vector<GLuint> normalsIndex;
		glm::vec4 *vert, *color, *normal;
		GLuint *index;
		GLuint buffer, IndexBuffer;
	
		std::string title;
};

