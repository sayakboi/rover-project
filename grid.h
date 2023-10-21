#pragma once
#include<iostream>
#include<string.h>
#include<vector>

using namespace std;
class Grid
{
    public:
    struct Cell
    {
        int x;
        int y;
    };
    Grid(Cell limits_);
    void addToOccupiedCells(Cell* cell);
    bool checkOccupied(Cell* cell);
    Cell* getLimits();
    bool isCellOutOfLimits(const Cell* c);
    private:
    std::vector<Cell*> occupiedCells;
    Cell limits;
    Cell* limitptr; 
};