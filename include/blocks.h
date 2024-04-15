#pragma once

// Standard libraries
#include <vector>
#include <map>

// Game libraries
#include "position.h"
#include "colors.h"

class Block
{
public:
    Block();

    int id;

    std::map<int, std::vector<Position>> cells;

    void draw();

private:
    int cellSize, rotationState;

    std::vector<Color> colors;
};


class LBlock : public Block
{
public:
    LBlock();
};