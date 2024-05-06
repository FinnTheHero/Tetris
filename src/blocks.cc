#include "blocks.h"

Position::Position(int row, int col)
{
    this -> row = row;
    this -> col = col;
}

Block::Block()
{
    cellSize = 40;
    rotationState = 0;
    rowOffset = 0;
    colOffset = 0;

    colors = getColors();
}

void Block::draw()
{
    std::vector<Position> tiles = getCellPosition();

    int startingX = (GetScreenWidth() - (10 * cellSize)) / 2;
    int startingY = (GetScreenHeight() - (20 * cellSize)) / 2;

    for (Position tile : tiles)
    {
        DrawRectangle (startingX + (tile.col * cellSize) + 2, startingY + (tile.row * cellSize) + 2, cellSize - 2, cellSize - 2, colors[id]);
    }
}

void Block::move(int rows, int cols)
{
    rowOffset += rows;
    colOffset += cols;
}

void Block::rotate()
{
    rotationState++;
    if (rotationState == (int) cells.size())
    {
        rotationState = 0;
    }
}

void Block::unRotate()
{
    rotationState--;
    if (rotationState == -1)
    {
        rotationState = cells.size() - 1;
    }
}

std::vector<Position> Block::getCellPosition ()
{
    std::vector<Position> tiles = cells[rotationState];

    std::vector<Position> positions;

    for (Position tile : tiles)
    {
        positions.push_back(Position(tile.row + rowOffset, tile.col + colOffset));
    }

    return positions;
}

LBlock::LBlock()
{
    id = 1;

    cells[0] = { Position(0, 2), Position(1, 0), Position(1, 1), Position(1, 2) };
    cells[1] = { Position(0, 1), Position(1, 1), Position(2, 1), Position(2, 2) };
    cells[2] = { Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 0) };
    cells[3] = { Position(0, 0), Position(0, 1), Position(1, 1), Position(2, 1) };

    move(0, 3);
}

JBlock::JBlock()
{
    id = 2;

    cells[0] = { Position(0, 0), Position(1, 0), Position(1, 1), Position(1, 2) };
    cells[1] = { Position(0, 1), Position(0, 2), Position(1, 1), Position(2, 1) };
    cells[2] = { Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 2) };
    cells[3] = { Position(0, 1), Position(1, 1), Position(2, 0), Position(2, 1) };

    move(0, 3);
}

IBlock::IBlock()
{
    id = 3;

    cells[0] = { Position(1, 0), Position(1, 1), Position(1, 2), Position(1, 3) };
    cells[1] = { Position(0, 2), Position(1, 2), Position(2, 2), Position(3, 2) };
    cells[2] = { Position(2, 0), Position(2, 1), Position(2, 2), Position(2, 3) };
    cells[3] = { Position(0, 1), Position(1, 1), Position(2, 1), Position(3, 1) };

    move(-1, 3);
}

OBlock::OBlock()
{
    id = 4;

    cells[0] = { Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1) };

    move(0, 4);
}

SBlock::SBlock()
{
    id = 5;

    cells[0] = { Position(0, 1), Position(0, 2), Position(1, 0), Position(1, 1) };
    cells[1] = { Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 2) };
    cells[2] = { Position(1, 1), Position(1, 2), Position(2, 0), Position(2, 1) };
    cells[3] = { Position(0, 0), Position(1, 0), Position(1, 1), Position(2, 1) };

    move(0, 3);
}

TBlock::TBlock()
{
    id = 6;

    cells[0] = { Position(0, 1), Position(1, 0), Position(1, 1), Position(1, 2) };
    cells[1] = { Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 1) };
    cells[2] = { Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 1) };
    cells[3] = { Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 1) };

    move(0, 3);
}

ZBlock::ZBlock()
{
    id = 7;

    cells[0] = { Position(0, 0), Position(0, 1), Position(1, 1), Position(1, 2) };
    cells[1] = { Position(0, 2), Position(1, 1), Position(1, 2), Position(2, 1) };
    cells[2] = { Position(1, 0), Position(1, 1), Position(2, 1), Position(2, 2) };
    cells[3] = { Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 0) };

    move(0, 3);
}
