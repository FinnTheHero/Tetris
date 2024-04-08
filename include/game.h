#pragma once

// Raylib
#include "raylib.h"

// Game libraries

// Standard libraries
#include <iostream>
#include <vector>
#include <string>

enum GameMode
{
    MENU,
    GAME,
    GAME_OVER
};

class Game
{
    public:
        Game();
        ~Game();
        void init();
        void update();
        void draw();
        void deInit();
};