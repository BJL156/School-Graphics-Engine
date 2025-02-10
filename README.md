### CodeHS is only meant for small programs... Or is it?

This program is meant to push just how far you can go with CodeHS - a programming website that my school uses.

### How to run
Clone the repo using the following command:
```
git clone https://github.com/BJL156/School-Graphics-Engine/
```
Then it's as simple as compling all of the files and running the program.

### Why would I do this
I get bored in school, and in order to test my graphics programming knowledge, it's good to try and make a software renderer with no help from external libraries or APIs like OpenGL or Vulkan.


### A (very) high level overview
Currently the program works by output a generated image to the console by printing a rectangle of spaces where I use ANSI escape codes in order to highlight the space to whatever color I want. Then in order to make a triangle I just check if the current pixel that I'm looping through, is within the triangle. If it is, call a pseudo fragment shader in order to color the pixel.
