/*
 * ShaderProgram.cpp
 *
 *  Created on: Mar 7, 2018
 *      Author: bmorales
 */

#include "ShaderProgram.h"

const char *vertexShaderSource = "#version 330\n"
        "in vec4 vPosition;\n"
        "in vec4 vColor;\n"
        "out vec4 color;\n"
        "uniform vec3 theta;\n"
        "void main()\n"
        "{\n"
        "   //Compute the sines and cosines of theta for each of\n"
        "   //the three axes in one computation.\n"
        "   vec3 angles = radians(theta);\n"
        "   vec3 c = cos(angles);\n"
        "   vec3 s = sin(angles);\n"
        "   //Remember: these matrices are column major.\n"
        "   mat4 rx = mat4(1.0, 0.0, 0.0, 0.0,\n"
        "                  0.0, c.x, s.x, 0.0,\n"
        "                  0.0, -s.x, c.x, 0.0,\n"
        "                  0.0, 0.0, 0.0, 1.0);\n"
        "   mat4 ry = mat4(c.y, 0.0, -s.y, 0.0,\n"
        "                  0.0, 1.0, 0.0, 0.0,\n"
        "                  s.y, 0.0, c.y, 0.0,\n"
        "                  0.0, 0.0, 0.0, 1.0);\n"
        "   mat4 rz = mat4(c.z, -s.z, 0.0, 0.0,\n"
        "                  s.z, c.z, 0.0, 0.0,\n"
        "                  0.0, 0.0, 1.0, 0.0,\n"
        "                  0.0, 0.0, 0.0, 1.0);\n"
        "   color = vColor;\n"
        "   gl_Position = rz * ry * rx * vPosition;\n"
        "}\0";

const char *fragmentShaderSource = "#version 330\n"
        "in vec4 color;\n"
        "out vec4 fColor;\n"
        "void main()\n"
        "{\n"
        "   fColor = color;\n"
        "}\n\0";


// build and compile our shader program
// ------------------------------------
GLuint ShaderProgram(void) {

	// vertex shader
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    // check for shader compile errors
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    // fragment shader
    int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    // check for shader compile errors
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    // link shaders
    GLuint shaderProgram = glCreateProgram();

    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    // check for linking errors
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }

    // Clean up
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return shaderProgram;

}


