#include "grid.h"

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

std::vector<Color> Grid::getColors()
{
    Color darkGrey = { 26, 31, 40, 255 };
    Color green = { 47, 230, 23, 255 };
    Color red = { 232, 18, 18, 255 };
    Color orange = { 226, 116, 17, 255 };
    Color yellow = { 237, 234, 4, 255 };
    Color purple = { 166, 0, 247, 255 };
    Color cyan = { 21, 204, 209, 255 };
    Color blue = { 13, 64, 255, 255 };

    return { darkGrey, green, red, orange, yellow, purple, cyan, blue };
}