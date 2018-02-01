# cse389-graphics
**Wed 1/24/2018:** 
  OpenGL is working and can open sample `main.cpp`(window) without apparent issues using `g++` compiler.
  
  To install required libraries:
  ```
  sudo apt-get install mesa-utils mesa-common-dev libgl1-mesa-dev libgl-dev libglfw3-dev lib-glfw3 libglm-dev libglew-dev
  ```
  
  To compile using `g++`:
  ```
  g++ main.cpp -lglfw -lGLEW -lGL
  ```

  **Wed 2/1/2018:**
  Follow instructions [here] (https://www.cs.nmt.edu/~amyk/Graphics/Environment/) for Glitter.  
  To fix the ```glad/glad.h`` not found error go to [http://glad.dav1d.de/] choose language C/C++, Specification: OpenGL, API: 4.5 (or whichever you need), and Profile: Core. After that hit generate and download the glad.zip file, insert the glad and KHR folders to your ```/usr/include/``` directory, and the glad.c file in to your project. In the linker add library ```dl```.
  
  