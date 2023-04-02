// Michael Peccia, CS 269 Week 9 EC
// file description: maze header file

#include "Square.h"
#include <iostream>
#include <cstdlib>
#include <stack>
#include <vector>

using namespace std;

class Maze {
    
    // constructor data
    int dimension;
    int seed;
    
    // 2d array of type Square
    Square** userMaze;
    
    
    // helper functions
    void createDynamicArray();
    void createMazeBorder();
    void linkAllSquares();
    void generatePaths();
    
    public:
        
        // constructor
        Maze(int, int);
        
        void createMaze();
        void visualizeMaze();
        
};