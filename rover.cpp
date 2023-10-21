#include "rover.h"
#include <stdio.h>
#include "grid.h"
RoverState::RoverState(State state_, Grid::Cell* gridLimitptr_):state(state_), gridLimitptr(gridLimitptr_)
{}
void RoverState::operator++()
{
    switch(this->state.heading)
    {
        case 'N':
            if(this->state.y<gridLimitptr->y)
                this->state.y ++;
            break;
        case 'E':
            if(this->state.x<gridLimitptr->x)
                this->state.x ++;
            break;
        case 'S':
            if(this->state.y>0)
                this->state.y --;
            break;
        case 'W':
            if(this->state.x>0)
                this->state.x --;
            break;
    }
}
Rover::Rover(int x_, int y_, char heading_, std::string commandString_, Grid* grid_)
   : x(x_), y(y_), heading(heading_), commandString(commandString_), rover(this), grid(grid_)
{
    currentCell = new Grid::Cell({x,y});
    this->grid->addToOccupiedCells(currentCell);
}
void Rover::move()
{
    RoverState roverState({this->currentCell->x, this->currentCell->y, this->heading}, this->grid->getLimits());
    ++roverState;
    Grid::Cell* temp = new Grid::Cell({roverState.state.x, roverState.state.y});
    if(!(grid->checkOccupied(temp)))
        {
            this->currentCell->x = temp->x;
            this->currentCell->y = temp->y;
        }
}
void Rover::turn(char rotate)
{
    std::vector<char>::iterator it = directions.begin();
    while(*it!= this->heading)
        it++;

    switch (rotate)
    {
    case 'L':
        if(it!=directions.begin())
            this->heading = *(--it);
        else
            this->heading = *(--directions.end());
        break;
    case 'R':
        if(it!=(--directions.end()))
            this->heading = *(++it);
        else
            this->heading = *directions.begin();
        break;
    }
}
void Rover::completeMotion()
{
    for(int i =0; i<commandString.length(); i++)
    {
        switch(commandString[i])
        {
            case 'L':
            case 'R':
                this->turn(commandString[i]);
                break;
            case 'M':
                this->move();
                break;
            default:
                throw("Unrecognized command "+commandString[i]);
        }
    }
}
void Rover::generateOutput()
{
    cout<<this->currentCell->x<<this->currentCell->y<<this->heading<<"\n";
}