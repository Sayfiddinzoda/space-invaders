#ifndef RENDER_H
#define RENDER_H
#include <iostream>
using namespace std;

#include <vector>
#include <string>


// Constants for screen dimensions
const int SCREEN_WIDTH = 80;
const int SCREEN_HEIGHT = 20;

// Struct for Player
struct Player {
    int x;
    int y;
};

// Struct for Enemy
struct Enemy {
    int x;
    int y;
    bool alive;
    int direction; // Direction of movement (-1 or 1)
};

// Struct for Bullet
struct Bullet {
    int x;
    int y;
    bool active;
};

// Function prototype for rendering function
void render(const Player& player, const std::vector<Enemy>& enemies, const std::vector<Bullet>& bullets);

#endif