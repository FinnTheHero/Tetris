// Game libraries
#include "game.h"

Game::Game()
{
    init();
}

Game::~Game() {}

void Game::init()
{
    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_FULLSCREEN_MODE | FLAG_WINDOW_RESIZABLE);

    InitWindow(0, 0, "Tetris");

    HideCursor();

    SetExitKey(KEY_DELETE);
}

void Game::update() {}

void Game::draw()
{
    BeginDrawing();
        ClearBackground(BLACK);
        DrawText("Tetris", 100, 100, 20, WHITE);
        DrawFPS(10, 10);
    EndDrawing();
}

void Game::deInit()
{
    CloseWindow();
}