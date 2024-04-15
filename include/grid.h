#pragma once

// Standard libraries
#include <vector>

// Raylib
#include "raylib.h"

class Grid
{
public:
    Grid();
    ~Grid();

    int grid[20][10];

    void init();
    void draw();

    std::vector<Color> getColors();

private:
    int numRows, numCols, cellSize;

    std::vector<Color> colors;
};