#include "blocks.h"
#include "position.h"

Block::Block()
{
    cellSize = 40;
    rotationState = 1;
    colors = getColors();
}

void Block::draw()
{
    std::vector<Position> tiles = cells[rotationState];

    int startingX = (GetScreenWidth() - (10 * cellSize)) / 2;
    int startingY = (GetScreenHeight() - (20 * cellSize)) / 2;

    for (Position tile : tiles)
    {
        DrawRectangle(startingX + (tile.col * cellSize) + 2, startingY + (tile.row * cellSize) + 2, cellSize - 2, cellSize - 2, colors[id]);
    }
}

LBlock::LBlock()
{
    id = 1;

    cells[0] = { Position(0, 2), Position(1, 0), Position(1, 1), Position(1, 2) };
    cells[1] = { Position(0, 1), Position(1, 1), Position(2, 1), Position(2, 2) };
    cells[2] = { Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 0) };
    cells[3] = { Position(0, 0), Position(0, 1), Position(1, 1), Position(2, 1) };
}