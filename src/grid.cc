#include "grid.h"

Grid::Grid()
{
    numRows = 20;
    numCols = 10;
    cellSize = 40;
}

Grid::~Grid() {}

void Grid::init()
{
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            grid[i][j] = 0;
        }
    }
}

void Grid::draw()
{
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            DrawRectangle((j * cellSize) + 1, (i * cellSize) + 1, cellSize - 1, cellSize - 1, GREEN);   
        }
    }
}