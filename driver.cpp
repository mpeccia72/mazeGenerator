// Michael Peccia, CS 269 Week 9 EC
// file description: driver file

#include <iostream>
#include "Maze.h"
#include <fstream>
#include <string>

using namespace std;

// pulls data from "data.txt" to generate a maze
void createMazeFromFile();

int main()
{
    
    // generates a maze from text file
    createMazeFromFile();
    
}

void createMazeFromFile() {
    
    // creates input file object and opens a file called "data.txt"
    ifstream input;
    input.open("data.txt");
    
    // if file fails to open, error is caught
    if(input.fail()) {
        cout << "Failed to open 'data.txt'";
        exit(0);
    }
    
    
    string line1, line2;
    getline(input, line1);
    getline(input, line2);
        
    // the two important variables
    int dimensions, seed;
        
    // extract dimension from text file
    dimensions = stoi(line1.substr(line1.find(":") + 1));
    
    // extract dimension from text file
    seed = stoi(line2.substr(line2.find(":") + 1));
    
    cout << "Congratulations, you have generated a " << dimensions << " X " << dimensions << " maze with the seed " << seed << endl;
    
    // closes file
    input.close();
    
    Maze myMaze(seed, dimensions);
    myMaze.createMaze();
    myMaze.visualizeMaze();
    
}