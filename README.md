# Space Invaders
Space Invaders is a classic CLI game written in C++. It simulates the nostalgic gameplay where the player controls a spaceship to shoot down advancing aliens, preventing them from reaching the bottom of the screen.

## Features
- **Player Controls:** Move the spaceship left (`a` key) and right (`d` key), shoot bullets (`spacebar` key), and quit the game (`q` key).
- **Enemy AI:** Enemies move horizontally across the screen, reversing direction when reaching the screen edges. They descend towards the player as they move.
- **Collision Detection:** Bullets fired by the player can hit and destroy enemies. The game tracks hits and updates the score accordingly.
- **Game Over:** The game ends when all enemies are defeated or when an enemy reaches the bottom of the screen.

## How to Play
1. **Compile the Game:**
- Ensure you have `g++` installed.
- Navigate to the project directory and run `make` to compile the game.
2. **Run the Game:**

- After compilation, execute the game by running the executable file generated in the `build` directory.
3. **Game Controls:**
- Use `a` and `d` keys to move the player left and right.
- Press ` ` (spacebar) to fire bullets.
- Press `q` to quit the game.
4. **Gameplay:**
- Dodge enemy attacks while shooting them down.
- Prevent enemies from reaching the bottom of the screen to stay in the game.
5. **Winning:**
- You win by defeating all enemies before they reach the bottom of the screen.
- The game displays a victory message when all enemies are destroyed.
6. **Losing:**
- The game ends if any enemy reaches the bottom of the screen.
- It displays a game over message and your final score.