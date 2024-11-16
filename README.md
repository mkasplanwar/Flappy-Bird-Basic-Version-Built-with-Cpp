# Flappy Bird - Basic Version Built with C++

This is a simple, console-based version of the classic **Flappy Bird** game implemented using **C++**. The objective of the game is to control a bird that must avoid pipes by navigating through gaps in the pipes.

## Features
- Console-based gameplay with basic ASCII graphics.
- Dynamic pipe generation with random gaps.
- Score system that increases as the bird successfully passes through pipes.
- Simple user controls to flap the bird and keep it in the air.

## Technologies Used
- **C++**: The primary programming language used to develop the game logic.
- **Windows API** (`<windows.h>`): Utilized to control cursor positioning and create graphical output in the console window.

## Game Controls
- Press any key to make the bird flap upwards.
- The goal is to avoid pipes that come at the bird in varying positions.

## How to Run
1. Clone or download this repository.
2. Open the `flappy_bird.cpp` file in your C++ compiler (such as Visual Studio or Code::Blocks).
3. Compile and run the program.
4. Play the game directly in your console/terminal window.

## Code Overview
- **Window Setup**: Uses Windows-specific functions such as `gotoxy()` to control the cursor in the console.
- **Game Loop**: Continuously updates the bird's position, checks for key presses, and monitors for collisions with pipes or the ground.
- **Pipe and Bird Rendering**: ASCII-based representation of the bird and pipes.
- **Collision Detection**: The game ends if the bird collides with a pipe or the ground.

## Screenshot
Here is a screenshot of the game in action:
![image](https://github.com/user-attachments/assets/b0a45e6f-6a65-4a10-a31e-55c1db05273a)
![image](https://github.com/user-attachments/assets/5b066ac3-ba0e-4498-8178-1083502f2b3f)
![image](https://github.com/user-attachments/assets/e86cf470-050e-408b-85dd-8a6590f3cc2a)
![image](https://github.com/user-attachments/assets/8119deb7-c628-4d34-87ff-093c6d7720e3)



*Note: Replace the `screenshot.png` with your actual screenshot file name.*

## Disclaimer
This code is free to use, modify, and distribute. Feel free to replicate, adjust, or expand upon it as you see fit. However, please make sure to give proper credit if you distribute or share your modified versions of this project.

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for more details.

---
