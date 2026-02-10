
# fract-ol

## 📖 About

"fract-ol" is a project at 42 Madrid that involves creating a fractal exploration program using computer graphics. This project introduces the MiniLibX graphics library, complex number mathematics, and teaches how to render beautiful mathematical fractals with interactive controls and optimization techniques.

The goal is to implement a program that can generate and display various types of fractals (Mandelbrot, Julia sets) with real-time navigation, zooming capabilities, and parameter manipulation for an immersive mathematical visualization experience.

## 🎯 Objectives

- Understanding and implementing complex number mathematics
- Learning computer graphics programming with MiniLibX
- Managing pixel manipulation and image rendering techniques
- Implementing interactive event handling (keyboard, mouse)
- Exploring optimization techniques for real-time rendering
- Understanding fractal mathematics and escape-time algorithms

## 📋 Function Overview

<details>
<summary><strong>fract-ol</strong></summary>

### Concepts

**Description:** Interactive fractal renderer supporting multiple fractal types  
**Usage:** `./fractol [fractal_type] [optional_parameters]`  
**Supported:** Mandelbrot set, Julia sets with customizable parameters  

```c
int main(int argc, char **argv);
```

### Use of graphics programming and complex numbers
The implementation of **fract-ol** requires handling graphics rendering and complex number calculations. For this, the MiniLibX library and mathematical operations are used:

The main functions and concepts are:

- **`mlx_init()`** ➜ Initializes the MiniLibX connection and prepares the graphics system.

```c
void *mlx_ptr = mlx_init();
```

- **`mlx_new_window()`** ➜ Creates a new window for displaying the fractal.

```c
void *win_ptr = mlx_new_window(mlx_ptr, width, height, "Fractol");
```

- **`mlx_new_image()`** / **`mlx_get_data_addr()`** ➜ Creates an image buffer for pixel manipulation.

```c
void *img_ptr = mlx_new_image(mlx_ptr, width, height);
char *data = mlx_get_data_addr(img_ptr, &bpp, &line_len, &endian);
```

- **Complex number operations** ➜ Mathematical calculations for fractal generation using complex arithmetic.

```c
z_real = z_real * z_real - z_imag * z_imag + c_real;
z_imag = 2 * z_real * z_imag + c_imag;
```

- **`mlx_hook()`** ➜ Sets up event handlers for keyboard and mouse interactions.

```c
mlx_hook(win_ptr, KeyPress, KeyPressMask, key_handler, &data);
```

These functions are essential for implementing **fract-ol**, as they enable graphics rendering, event handling, and mathematical visualization.

</details>

<details>
<summary><strong>Fractals & Interactions</strong></summary>

### Supported Fractals

- **Mandelbrot Set**: Classic fractal with fixed parameters
- **Julia Sets**: Parameterizable fractals with different constants

### Interactive Controls

- **Mouse wheel**: Zoom in and out at cursor position
- **Arrow keys / WASD**: Navigate through the fractal space
- **Number keys**: Switch between different fractal types
- **ESC / Window close**: Exit the program cleanly

### Visual Features

- **Color schemes**: Beautiful gradient coloring based on iteration count
- **Smooth rendering**: Anti-aliasing and smooth color transitions
- **Real-time updates**: Immediate response to user interactions
- **Window management**: Proper window handling and cleanup

</details>

## 🚀 Installation & Structure

<details>
<summary><strong>📥 Download & Compilation</strong></summary>
    
<br>

```bash
# Clone the repository
git clone https://github.com/ravazque/fract-ol.git
cd fract-ol

# Compile the program
make

# Clean object files
make clean

# Clean everything including executable
make fclean

# Recompile everything
make re

# Run the program with different fractals
./fractol mandelbrot
./fractol julia -0.7269 0.1889
./fractol julia 0.285 0.01
```

<br>

</details>

<details>
<summary><strong>📁 Project Structure</strong></summary>

<br>

```
fract-ol/
├──┬ include/
│  └── fractol.h                        # Header file with structures and prototypes
├──┬ linux-minilibx/                    # MiniLibX graphics library for Linux systems
│  └── *.c
├──┬ src/
│  ├──┬ aux_libft/                      # Custom libft implementation for fractol project
│  │  ├──┬ include/
│  │  │  └── libft.h
│  │  ├──┬ src/
│  │  │  └── *.c
│  │  └── Makefile
│  ├── events.c                         # Keyboard and mouse event handlers for navigation
│  ├── fractol.c                        # Main program and argument parsing for Mandelbrot/Julia
│  ├── init.c                           # MiniLibX initialization and fractal data setup
│  ├── math_utils.c                     # Complex number operations and coordinate mapping
│  ├── render.c                         # Fractal rendering, pixel manipulation and color mapping
│  └── string_utils.c                   # String parsing utilities for Julia parameters
├── Makefile                            # Compilation rules and library linking
└── README.md                           # Project documentation
```

<br>

</details>

## 💡 Key Learning Outcomes

The fract-ol project teaches computer graphics and mathematical visualization:

- **Graphics Programming**: Understanding pixel manipulation and image rendering techniques
- **Complex Mathematics**: Deep knowledge of complex numbers and iterative mathematical functions
- **Event-Driven Programming**: Learning to handle user interactions and real-time updates
- **Optimization Techniques**: Implementing efficient algorithms for smooth real-time rendering
- **Mathematical Visualization**: Understanding how abstract mathematics translates to visual art
- **Memory Management**: Proper handling of graphics resources and image buffers

## ⚙️ Technical Specifications

- **Language**: C (C90 standard)
- **Compiler**: cc with flags `-Wall -Wextra -Werror`
- **Graphics Library**: MiniLibX for window management and pixel manipulation
- **Mathematics**: Complex number arithmetic and escape-time algorithms
- **Platform**: UNIX-like systems (Linux, macOS)
- **Memory Management**: Efficient image buffer handling and resource cleanup
- **Input Handling**: Responsive keyboard and mouse event processing

---

> [!NOTE]
> This project serves as an introduction to computer graphics programming and demonstrates proficiency in mathematical visualization and interactive application development.