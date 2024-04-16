#include "grid.h"
#include "colors.h"

Grid::Grid()
{
    init();
}

Grid::~Grid() {}

void Grid::init()
{
    numRows = 20;
    numCols = 10;
    cellSize = 40;

    colors = getColors();

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
    int startingX = (GetScreenWidth() - (numCols * cellSize)) / 2;
    int startingY = (GetScreenHeight() - (numRows * cellSize)) / 2;

    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            int cellValue = grid[i][j];
            DrawRectangle(startingX + (j * cellSize) + 2, startingY + (i * cellSize) + 2, cellSize - 2, cellSize - 2, colors[cellValue]);   
        }
    }
}


bool Grid::isCellOutside(int row, int col)
{
    if (row >= 0 && row < numRows && col >= 0 && col < numCols)
    {
        return false;
    }
    
    return true;
}
