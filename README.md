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
  
  #### Questions
###### 1. What is the theme of your museum?
> The theme that we chose is a roman theme based around the time frame of the beginning (1430s) to the zenith (1520s) of the renaissance.
###### 2. How many rooms will your museum have?
> Our museum should have between 3 and 4 rooms. The main room is planned to be a sort of Y shape. 
###### 3. Have you started looking for textures for your museum walls/floors? If so, what are your plans?
> We have found some textures online that will allow us to give the walls and floors a marble style to try to fit with the theme. 
  We plan to use a marble tiling for the flooring, and to distribute pillars and arches throughout the area, to make it feel more like a roman style museum.
###### 4. Will your museum have a ceiling? 
> Yes, the museum  will have a ceiling and we intend to make it more dome shaped, to try to make the building feel like it was designed to fit with the same era that our theme originates.
###### 5. You must have at least ONE “sculpture” in your museum.  What are you planning to use for your sculpture(s)?  NOTE: You DO NOT have to create your own blender model/sculpture, you are free to search the internet for a pre-made model. It is more important, for me, that you understand how these models are represented in the computer, and how they are manipulated in 3D space.
> We are going to use a 3D blender model that I (Franz) found on blendswap.org. It has a CC of zero, meaning we would not need to reference the creator if we use the model. The model we chose is the statue of David.
    
###### 6. You must have at least FOUR “paintings” in your museum.  What were you planning to use for your pictures? Have you already started looking for textures that can be applied as “pictures”? Will your pictures be hung on the wall? Will they be murals?  Do you have a completely different idea of how these paintings will be added to your museum?
> We have not decided on the paintings that we plan to use. There are several paintings that can be easily textured to a simple painting frame model, however we would like to look into some more unconventional methods of displaying them. The pictures will most likely be hung on the wall inside a framed model, however, we may have a painting on the ceiling, depending on how complex it will be to texture it to a dome shape without it looking strange. 
