# cse389-graphics
**Wed 1/24/2017:** 
  OpenGL is working and can open sample `main.cpp`(window) without apparent issues using `g++` compiler.
  
  To install required libraries:
  ```
  sudo apt-get install mesa-utils mesa-common-dev libgl1-mesa-dev libgl-dev libglfw3-dev lib-glfw3 libglm-dev libglew-dev

  GLAD is needed get it here: http://glad.dav1d.de/
     install by choosing:
         gl version 4.5, profile: core
     download and extract:
         include into /usr/include/
         src/glad.c into project folder
  ```
  
  To compile using `g++`:
  ```
  g++ glad.o -c -ldl
  g++ main.cpp -lglfw -lGLEW -lGL -ldl
  ```
