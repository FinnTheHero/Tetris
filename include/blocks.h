#pragma once

// Standard libraries
#include <vector>
#include <map>

// Game libraries
#include "colors.h"


class Position
{
public:
    Position(int row, int col);
    int row, col;
};

class Block
{
public:
    Block();

    int id;

    void draw();
    void move(int rows, int cols);
    void rotate();
    void unRotate();
    std::vector<Position> getCellPosition();
    std::map<int, std::vector<Position>> cells;

private:
    int cellSize, rotationState, rowOffset, colOffset;

    std::vector<Color> colors;
};


class LBlock : public Block
{
public:
    LBlock();
};

class JBlock : public Block
{
public:
    JBlock();
};

class IBlock : public Block
{
public:
    IBlock();
};

class OBlock : public Block
{
public:
    OBlock();
};

class SBlock : public Block
{
public:
    SBlock();
};

class TBlock : public Block
{
public:
    TBlock();
};

class ZBlock : public Block
{
public:
    ZBlock();
};
