#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include "grid.h"
#include "rover.h"
using namespace std;

class RoverApplication
{
    private:
    Grid* grid;
    std::vector<Rover*> rovers;

    public:
    void ReadFromFile(std::string fname);
    void WriteToFile(std::string fname);
    void completeAllMotion();
    protected:
    ~RoverApplication()
    {
        delete grid;
    }
};