#pragma once

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

private:
    int numRows, numCols, cellSize;
};