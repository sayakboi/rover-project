#include "roverio.h"
#include <sstream>
using std::stof;
using std::to_string;

void RoverApplication::ReadFromFile(std::string fpath)
{
    std::string line;
    std::ifstream filestream(fpath);
    if (filestream.is_open()) 
    {
        cout<<"Reading input File\n";
        std::getline(filestream, line);
        std::istringstream linestream(line);
        int x, y;
        linestream >> x >> y;
        try
        {
            if (x< 0 || y<0)
            {
                throw(std::runtime_error("Grid limits less than 0"));
            }
        }catch(std::exception e)
        {
            std::cerr << "An exception occurred: " << e.what() << std::endl;
            std::terminate();
        }
        grid = new Grid({x, y});
        while (std::getline(filestream, line)) 
        {
            std::istringstream linestream(line);
            int x, y;
            char head;
            linestream >> x >> y >> head;
            std::getline(filestream, line);
            try
            {
                Grid::Cell* c = new Grid::Cell({x,y});
                if (grid->isCellOutOfLimits(c))
                {
                    throw(std::runtime_error("Starting position of a Rover is outside  of grid limits"));
                }
                if (grid->checkOccupied(c))
                {
                    throw(std::runtime_error("Starting position of a Rover is colliding with another rover"));
                }
            }catch(std::exception e)
            {
                std::cerr << "An exception occurred: " << e.what() << std::endl;
                std::terminate();
            }
            auto rover = new Rover(x,y,head,line, grid);
            rovers.push_back(rover);
        }
    }
}

void RoverApplication::WriteToFile(std::string fname)
{
    std::ofstream outputFile(fname);
    if (outputFile.is_open()) 
    {
        for(auto it : rovers)
        {
            outputFile<<it->currentCell->x<<" "<<it->currentCell->y<<" "<<it->heading<<"\n";
        }
        outputFile.close();
        std::cout << "Data has been written to the file." << std::endl;
    }
    else
    {
        std::cerr << "Failed to open the file for writing." << std::endl;
    }

}

void RoverApplication::completeAllMotion()
{
    for(auto it : rovers)
    {
        it->completeMotion();
    }
}

int main(int args, char* argv[])
{
    std::string ipfpath, opfpath;
    if(args <= 2)
    {
    	std::cout<<"Please give input and output file path as arguments\n";
        return 0;
    }
    else
    {
        ipfpath = argv[1];
        opfpath = argv[2];
    }
    RoverApplication* roverApp = new RoverApplication();
    roverApp->ReadFromFile(ipfpath);
    roverApp->completeAllMotion();
    roverApp->WriteToFile(opfpath);
    return 0;
}
