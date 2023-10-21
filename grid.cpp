#include "grid.h"

Grid::Grid(Cell limits_): limits(limits_)
{
    limitptr = &limits;
}
void Grid::addToOccupiedCells(Cell* cell)
{
    this->occupiedCells.push_back(cell);
}
bool Grid::checkOccupied(Cell* cell)
{
    for(auto it : occupiedCells)
    {
        if(it->x == cell->x && it->y == cell->y)
            return true;
    }
    return false;
}
Grid::Cell* Grid::getLimits()
{
    return this->limitptr;
}
bool Grid::isCellOutOfLimits(const Cell* c)
{
    if(c->x < 0 || c->x > this->getLimits()->x || c->y < 0 || c->y > this->getLimits()->y)
        return true;
    return false;
}