#pragma once

// Standard libraries
#include <vector>
#include <iostream>

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

    bool isCellOutside(int row, int col);

private:
    int numRows, numCols, cellSize;

    std::vector<Color> colors;
};