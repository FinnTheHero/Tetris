#pragma once

// Standard libraries
#include <iostream>
#include <vector>
#include <string>

// Raylib
#include "raylib.h"

// Game libraries
#include "grid.h"

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
        void loop();
        void deInit();
};