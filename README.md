<p align="center">
  <img src="https://github.com/user-attachments/assets/f7021da2-2f59-4e39-ad36-a48524da4455" alt="High Resolution Render" width="400">
</p>

# School Graphics Engine
[![Language](https://img.shields.io/badge/language-C++-blue.svg)](https://en.wikipedia.org/wiki/C%2B%2B)
[![Platform](https://img.shields.io/badge/platform-Windows%20%7C%20Linux%20%7C%20CodeHS-lightgrey.svg)](https://codehs.com/)
![Renderer](https://img.shields.io/badge/renderer-ANSI%20Terminal-orange.svg)

A custom software graphics engine built to push CodeHS—a restricted school programming platform—to its absolute limits. It renders 3D graphics directly inside the console using ANSI escape sequences and double-space pixel blocks.

This project is the original precursor that inspired [Mini Raster 3D](https://github.com/BJL156/Mini-Raster-3D).

## Build
Clone the repository and change into its directory:
```bash
git clone [https://github.com/BJL156/School-Graphics-Engine/](https://github.com/BJL156/School-Graphics-Engine/)
cd School-Graphics-Engine
```
Compile all of the files together:
```bash
g++ *.cpp -o graphics_engine.out
```
Run the compiled binary:
```
# Linux
./graphics_engine.out

# Windows
.\graphics_engine.out
```
