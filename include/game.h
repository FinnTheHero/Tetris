#pragma once

// Standard libraries
#include <iostream>
#include <vector>
#include <string>
#include <random>

// Raylib
#include "raylib.h"

// Game libraries
#include "grid.h"
#include "blocks.h"

enum GameMode
{
    MENU,
    GAME,
    GAME_OVER
};

class Game
{
public:

    Grid grid;

    Game();
    ~Game();
    void init();
    void loop();
    void deInit();

    Block getRandomBlock();

    std::vector<Block> getAllBlocks();

    void moveLeft();
    void moveRight();
    void moveDown();

    void handleInput();

private:
    bool isBlockOutside();
    std::vector<Block> blocks;
    Block currentBlock;
    Block nextBlock;
};