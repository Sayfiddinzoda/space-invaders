#include "render.h"
#include <iostream>
#include <vector>
#include <cstdlib> // For rand() function
#include <ctime>   // For srand() function
#include <unistd.h> // For usleep() function

#ifdef _WIN32
#include <conio.h> // For Windows kbhit() and getch()
#else
#include <termios.h>
#include <fcntl.h>
#endif

using namespace std;

const int ENEMY_COUNT = 5;
const int ENEMY_SPEED = 1; // Speed at which enemies move across the screen

// Cross-platform kbhit() function
#ifdef _WIN32
int kbhit() {
    return _kbhit();
}
#else
int kbhit() {
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if(ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
}
#endif

int main() {
    // Initialize player
    Player player;
    player.x = SCREEN_WIDTH / 2;
    player.y = SCREEN_HEIGHT - 1;

    // Initialize enemies
    std::vector<Enemy> enemies(ENEMY_COUNT);
    for (int i = 0; i < ENEMY_COUNT; ++i) {
        enemies[i].x = rand() % SCREEN_WIDTH;
        enemies[i].y = rand() % 5; // Place enemies near the top
        enemies[i].alive = true;
        enemies[i].direction = 1; // Start moving right initially
    }

    // Initialize bullets
    std::vector<Bullet> bullets;

    bool game_over = false;
    while (!game_over) {
        // Render the game
        render(player, enemies, bullets);

        // Handle player input (simplified for CLI)
        if (kbhit()) {
            char input = getchar();
            switch (input) {
                case 'a':
                    player.x = std::max(0, player.x - 1); // Ensure player stays within screen bounds
                    break;
                case 'd':
                    player.x = std::min(SCREEN_WIDTH - 1, player.x + 1); // Ensure player stays within screen bounds
                    break;
                case ' ':
                    // Fire bullet
                    bullets.push_back({player.x, player.y - 1, true});
                    break;
                case 'q':
                    game_over = true;
                    break;
            }
        }

        // Update bullets
        for (auto& bullet : bullets) {
            bullet.y--;
            if (bullet.y < 0) {
                bullet.active = false; // Deactivate bullets that go off-screen
            }
        }

        // Update enemies (more complex movement)
        for (auto& enemy : enemies) {
            if (enemy.alive) {
                enemy.x += enemy.direction * ENEMY_SPEED;

                // Reverse direction and move down if enemy reaches screen edge
                if (enemy.x >= SCREEN_WIDTH - 1 || enemy.x <= 0) {
                    enemy.direction *= -1; // Reverse direction
                    enemy.y++; // Move down
                }

                // Check if enemy reaches bottom of the screen
                if (enemy.y >= SCREEN_HEIGHT - 1) {
                    game_over = true; // Game over if enemy reaches bottom
                }
            }
        }

        // Check for collisions (simplified collision detection)
        for (auto& bullet : bullets) {
            if (bullet.active) {
                for (auto& enemy : enemies) {
                    if (enemy.alive && bullet.x == enemy.x && bullet.y == enemy.y) {
                        bullet.active = false;
                        enemy.alive = false;
                    }
                }
            }
        }

        // Check if all enemies are defeated
        bool all_enemies_defeated = true;
        for (const auto& enemy : enemies) {
            if (enemy.alive) {
                all_enemies_defeated = false;
                break;
            }
        }

        if (all_enemies_defeated) {
            game_over = true;
        }

        // Delay to control game speed (simplified)
        usleep(100000); // Sleep for 100ms
    }

    std::cout << "You defeated all enemies! Game Over!" << std::endl;
    return 0;
}