# cse389-graphics
***
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

***

  **Wed 2/1/2018:**  
  ~~Follow instructions [here](https://www.cs.nmt.edu/~amyk/Graphics/Environment/) for Glitter.~~  
  To fix the ```glad/glad.h``` not found error go to <http://glad.dav1d.de/> use the following settings  
  * Language: C/C++
  * Specification: OpenGL
  * API: 4.5 (or whichever you need)
  * Profile: Core
  
  Hit generate and download the glad.zip file, insert the glad and KHR folders to your ```/usr/include/``` directory, and the glad.c file inside the ```src``` folder into your project. In the linker add library ```dl```.  
  To compile using g++:  
  ```
  g++ main.cpp glad.c -lglfw -ldl
  ```
  
  Install ```libassimp-dev, libbullet-dev``` we might need them for later.

  
  ***
  
  ## Weekly Scrotum 2018/2/2  
  
  ![alt text][triangle]
  
  ![alt text][triangle_wire]
  
  [triangle]: https://github.com/bmoral/cse389-graphics/blob/master/misc/triangle-2118.png
  [triangle_wire]: https://github.com/bmoral/cse389-graphics/blob/master/misc/triangle_wire-2118.png
  
  
