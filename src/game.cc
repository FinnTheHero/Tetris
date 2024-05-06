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

    lastUpdatedTime = 0;

    grid = Grid();

    blocks = getAllBlocks();

    currentBlock = getRandomBlock();
    nextBlock = getRandomBlock();
}

void Game::loop()
{
    while (!WindowShouldClose())
    {
        if (timePassed(0.75))
        {
            moveDown();
        }

        handleInput();

        BeginDrawing();
            ClearBackground(BLACK);
            // DrawText("Tetris", 100, 100, 20, WHITE);

            grid.draw();
            currentBlock.draw();
            DrawFPS(10, 10);
        EndDrawing();
    }
}

void Game::deInit()
{
    CloseWindow();
}


Block Game::getRandomBlock()
{
    // If there are no blocks left, refill the list
    if (blocks.empty())
    {
        blocks = getAllBlocks();
    }
    srand(time(NULL));

    int randomIndex = rand() % blocks.size();

    // Choose random block
    Block block = blocks[randomIndex];

    // Remove block from list
    blocks.erase(blocks.begin() + randomIndex);

    return block;
}

std::vector<Block> Game::getAllBlocks()
{
    return {
        LBlock(),
        JBlock(),
        IBlock(),
        OBlock(),
        SBlock()
    };
}

void Game::moveLeft()
{
    currentBlock.move(0, -1);
    if (isBlockOutside())
    {
        currentBlock.move(0, 1);
    }
}

void Game::moveRight()
{
    currentBlock.move(0, 1);
    if (isBlockOutside())
    {
        currentBlock.move(0, -1);
    }
}

void Game::moveDown()
{
    currentBlock.move(1, 0);
    if (isBlockOutside())
    {
        currentBlock.move(-1, 0);
    }
}

void Game::handleInput()
{
    int key = GetKeyPressed();

    switch(key)
    {
    case KEY_LEFT:
        moveLeft();
        break;
    case KEY_RIGHT:
        moveRight();
        break;
    case KEY_DOWN:
        moveDown();
        break;
    case KEY_UP:
        rotateBlock();
        break;
    }
}

bool Game::isBlockOutside()
{
    std::vector<Position> tiles = currentBlock.getCellPosition();

    for (Position tile : tiles)
    {
        if(grid.isCellOutside(tile.row, tile.col))
        {
            return true;
        }
    }
    
    return false;
}

void Game::rotateBlock()
{
    currentBlock.rotate();
    if (isBlockOutside())
    {
        currentBlock.unRotate();
    }
}

bool Game::timePassed(double interval)
{
    double currentTime = GetTime();

    if (currentTime - lastUpdatedTime >= interval)
    {
        lastUpdatedTime = currentTime;
        return true;
    }
    return false;
}
