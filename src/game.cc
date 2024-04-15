// Game libraries
#include "game.h"

Game::Game()
{
    init();
    loop();
}

Game::~Game() {
    deInit();
}

void screenSettings()
{
    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_FULLSCREEN_MODE );

    InitWindow(0, 0, "Tetris");

    DisableCursor();

    SetExitKey(KEY_DELETE);
}

void Game::init()
{
    screenSettings();
}

void Game::loop()
{
    Grid grid;

    while (!WindowShouldClose())
    {
        

        BeginDrawing();
            ClearBackground(BLACK);
            // DrawText("Tetris", 100, 100, 20, WHITE);

            grid.draw();

            DrawFPS(10, 10);
        EndDrawing();
    }
}

void Game::deInit()
{
    CloseWindow();
}