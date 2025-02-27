### CodeHS is only meant for small programs... Or is it?

This program is meant to push just how far you can go with CodeHS - a programming website that my school uses.

### Dev logs
[BJL156 On Youtube](https://www.youtube.com/@brayjl156)

### Current state (high resolution render)
![image](https://github.com/user-attachments/assets/f7021da2-2f59-4e39-ad36-a48524da4455)

### How to run
Clone the repo using the following command then change directories into it:
```
git clone https://github.com/BJL156/School-Graphics-Engine/
cd School-Graphics-Engine
```
Then just compile all of the files and running the program. You can either use VS2022 or here's an example using g++:
```
g++ *.cpp
```
Then run the program. Here is an example assuming you ran the g++ command above in Linux:
```
./a.out
```
Or in Windows:
```
.\a.exe
```

### FAQ
#### Why would I do this?
I get bored in school, so I like to mess around with some code. But my school's stinking chromebook doesn't let me run code directly on it for "security" reasons (likely story). This means that coding classes must use a website in order to compile and run code. This is where CodeHS comes in, and as revenge from not allowing me to run my code on the chromebook, I want to push CodeHS to its limits.

#### How am I displaying the graphics?
I am printing out a rectangle, and using ANSI escape codes, I change the background color of each space to whatever I want.

#### Why is all of the code in the root directory?
Currently, CodeHS doesn't allow me to have directories for the source code because, I CodeHS doesn't use my updated Makefile, and they just stick to their very basic one that doesn't accomendate for other directories.

### A (very) high level overview
Currently the program works by outputting a generated image to the console. It does this using ANSI escape codes, so by printing a rectangle of spaces I use these codes in order to change each space to whatever color I want. With the ability to have a rectangle where I can change tiny squares to whatever color I want, my plans can take into effect. So here is the basics on how I render:
1. define a triangle in NDC from a vector of type `Vec3`.
2. Setup a `UniformBuffer` with basic information. This data will be passed to both the fragment and vertex shader.
3. Call the vertex shader which transforms the triangle into 3D and other fun stuff like translation, scaling, and rotation.
4. Transform the triangle into screen space.
5. Use barycentric coords to figure out if a pixel is within the triangle.
6. If it is call the fragment shader to do some fancy color stuff.
7. Set the pixel to the new color generated by the fragment shader.
