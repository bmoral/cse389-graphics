//#include "Object.h"
#include "MainComponent.h"
//#include "Window.h"
//#include "ShaderProgram.h"
//#include <glad/glad.h>

//#include <iostream>

int main()
{
	//Window Setting constants
	const unsigned int width = 800;
	const unsigned int height = 600;
	const char* TITLE = "Morales_Chavez_Museum";
	const char* ICON = "./misc/colosseum-icon.png";

	//Create window
	Window window(width, height,TITLE);
	window.setIcon(ICON);

	//Execute actual program
	MainComponent prog;
	prog.start();
	return 0;
}


//
//void framebuffer_size_callback(GLFWwindow* window, int width, int height);
//void processInput(GLFWwindow* window);
//
////settings
//const unsigned int SCR_WIDTH = 800;
//const unsigned int SCR_HEIGHT = 600;
//
////modelselection
//int modelSelection = 0;
//// create a vertex array object (VAO) ***
//GLuint vao[2];
////glGenVertexArrays(2, &vao);
//
///******************************************************************************
//
//	KEYBOARD SWITCH COMMANDS
//
//******************************************************************************/
//void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
//{
//    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
//        exit(EXIT_SUCCESS);
//    if (key == GLFW_KEY_SPACE && action == GLFW_PRESS) {
//        modelSelection = (modelSelection + 1) % 2; //mod num_models
//        glBindVertexArray(vao[modelSelection]);
//    }
//} // end key_callback()
//
//
//int main(){
//
//    // glfw: initialize and configure
//    // ------------------------------
//    glfwInit();
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
//    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//    // glfw window creation
//    // --------------------
//    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Chavez_Morales Load Objects", NULL, NULL);
//    if(window == NULL){
//        std::cout << "Failed to create GLFW window" << std::endl;
//        glfwTerminate();
//        return -1;
//    }
//    glfwMakeContextCurrent(window);
//    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//
//    // glad: load all OpenGL function pointers
//    // ---------------------------------------
//    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
//        std::cout << "Failed to initialize GLAD" << std::endl;
//        return -1;
//    }
//
//
//    // create a vertex array object (VAO) ***
//    //GLuint vao[2];
//    glGenVertexArrays(2, vao);
//
//    //set our shader program
//    GLuint shaderProgram = ShaderProgram();
//
//
//
//
//    // set up vertex data (and buffer(s)) and configure vertex attributes
//    // ------------------------------------------------------------------
//    //float vertices[] = {
//    //        -0.5f, -0.5f, 0.0f, // left
//    //        0.5f, -0.5f, 0.0f, // right
//    //        0.0f,  0.5f, 0.0f  // top
//    //};
//
//    //unsigned int VBO, VAO;
//    //glGenVertexArrays(1, &VAO);
//    //glGenBuffers(1, &VBO);
//    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
//    //glBindVertexArray(VAO);
//
//    //glBindBuffer(GL_ARRAY_BUFFER, VBO);
//    //glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//    //glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//    //glEnableVertexAttribArray(0);
//
//    // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
//    //glBindBuffer(GL_ARRAY_BUFFER, 0);
//
//    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
//    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
//    //glBindVertexArray(0);
//
//    // uncomment this call to draw in wireframe polygons.
//    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//
//    Object museumWalls[2] = {std::string("./misc/objects/monkey.obj"),
//    						 std::string("./misc/objects/monkey.obj")};
//
//    GLfloat Theta[3] = {0.0, 0.0, 0.0};
//    GLint theta;
//
//
//    // Link to out vao and prep to display ****
//    glUseProgram(shaderProgram);
//    for(int i = 0; i < 2; i++) {
//    	glBindVertexArray(vao[i]);
//    	museumWalls[i].load(shaderProgram);
//    }
//
//    glBindVertexArray(vao[0]);
//    theta = glGetUniformLocation(shaderProgram, "theta");
//
//    glEnable(GL_DEPTH_TEST);
//    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//    // render loop
//    // -----------
//    while(!glfwWindowShouldClose(window)){
//
//        // input
//        // -----
//        //processInput(window);
//
//        // render
//        // ------
//        //glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//
//        // draw our first triangle
//        //glUseProgram(shaderProgram);
//        //glBindVertexArray(museumVAO);
//        //museumWalls.draw();
//        //glBindVertexArray(0);
//        //glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
//        //glDrawArrays(GL_TRIANGLES, 0, 3);
//        // glBindVertexArray(0); // no need to unbind it every time
//
//        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
//        // -------------------------------------------------------------------------------
//        glfwSwapBuffers(window);
//        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//        glUniform3fv(theta, 1, Theta);
//        museumWalls[modelSelection].draw();
//
//        Theta[1] += 0.1;
//
//        if(Theta[1] > 360.0) {
//        	Theta[1] -= 360.0;
//        }
//
//        glfwPollEvents();
//    }
//
//    // optional: de-allocate all resources once they've outlived their purpose:
//    // ------------------------------------------------------------------------
//    //glDeleteVertexArrays(1, &VAO);
//    //glDeleteBuffers(1, &VBO);
//
//    // glfw: terminate, clearing all previously allocated GLFW resources
//    // -----------------------------------------------------------------
//    glfwTerminate();
//    return 0;
//}
//
//// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
//// ---------------------------------------------------------------------------------------------------------
//void processInput(GLFWwindow* window){
//    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
//        glfwSetWindowShouldClose(window, true);
//    }
//}
//
////glfw: whenever the window size changed (by OS or user resize) this callback function executes
//void framebuffer_size_callback(GLFWwindow* window, int width, int height){
//
//    // make sure the viewport matches the new window dimensions; note that width and
//    // height will be significantly larger than specified on retina displays.
//    glViewport(0,0,width, height);
//}
