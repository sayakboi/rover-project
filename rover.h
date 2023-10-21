#include <iostream>
#include <string.h>
#include <vector>
#include "grid.h"

using namespace std;

class RoverState
{
    public: 
    struct State
    {
        int x;
        int y;
        char heading;
    };
    Grid::Cell* gridLimitptr;
    State state;
    RoverState(State state_, Grid::Cell* gridLimitptr_);
    void operator++();
};
class Rover
{
    public:
    int x;
    int y;
    std::vector<char> directions = {'N', 'E', 'S', 'W'} ;
    char heading;
    std::string commandString;
    Grid* grid;
    Grid::Cell* currentCell;
    Rover(int x, int y, char heading, std::string commandString, Grid* grid);
    void move();
    void turn(char rotate);
    void completeMotion();
    void generateOutput();

    Rover* rover;
};