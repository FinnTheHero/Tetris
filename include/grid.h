#pragma once

class Grid
{
public:
    Grid(int width, int height);
    ~Grid();
    void set(int x, int y, int value);
    int get(int x, int y);
    void print();
};