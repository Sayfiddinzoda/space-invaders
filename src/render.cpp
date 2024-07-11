#include "render.h"
#include <iostream>

void render(const Player& player, const std::vector<Enemy>& enemies, const std::vector<Bullet>& bullets) {
    // Clear the screen
    system("clear"); // For Unix-like systems, use "cls" for Windows

    // Create a 2D array to represent the screen
    char screen[SCREEN_HEIGHT][SCREEN_WIDTH];

    // Initialize screen with blank spaces
    for (int i = 0; i < SCREEN_HEIGHT; ++i) {
        for (int j = 0; j < SCREEN_WIDTH; ++j) {
            screen[i][j] = ' ';
        }
    }

    // Place the player on the screen
    screen[player.y][player.x] = 'P';

    // Place enemies on the screen
    for (const auto& enemy : enemies) {
        if (enemy.alive) {
            screen[enemy.y][enemy.x] = 'E';
        }
    }

    // Place bullets on the screen
    for (const auto& bullet : bullets) {
        if (bullet.active) {
            screen[bullet.y][bullet.x] = '*';
        }
    }

    // Print the screen
    for (int i = 0; i < SCREEN_HEIGHT; ++i) {
        for (int j = 0; j < SCREEN_WIDTH; ++j) {
            std::cout << screen[i][j];
        }
        std::cout << std::endl;
    }
}
