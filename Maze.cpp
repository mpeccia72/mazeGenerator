// Michael Peccia, CS 269 Week 9 EC
// file description: maze implementation file

#include "Maze.h"

// constructor that sets seed and dimension of maze
Maze::Maze(int inputSeed, int inputDimension) {
    
    dimension = inputDimension;
    seed = inputSeed;
    
}


// dynamically allocates memory to 2d array of Maze object
void Maze::createDynamicArray(){
    
    userMaze = new Square*[dimension];
    
    for(int i = 0; i < dimension; i++) {
        userMaze[i] = new Square[dimension];
    }
    
}


// helper function that creates a border around edges of the X by X maze by setting all the edge pointers to NULL
void Maze::createMazeBorder() {
    
    // the sides of squares touching edges have there pointers set to NULL
    for(int i = 0; i < dimension; i++) {
        
        // sets a border on the along left side of the maze
        userMaze[0][i].setLeft(NULL);
        
        // sets a border on the along top side of the maze
        userMaze[i][0].setUp(NULL);
        
        // sets a border on the along bottom side of the maze
        userMaze[dimension - 1][i].setDown(NULL);
        
        // sets a border on the along right side of the maze
        userMaze[i][dimension - 1].setRight(NULL);
        
    }
    
}

// helper function that links all the squares together appropiately using pointers
void Maze::linkAllSquares() {
    
    // nested for loop algorithm that connects all horizontal sides
    for(int row = 0; row < dimension; row++) {
        for(int column = 0; column < dimension - 1; column++) {
            
            // connects all horizontal sides of squares to each other
            userMaze[row][column].setRight(&userMaze[row][column + 1]);
            userMaze[row][column + 1].setLeft(&userMaze[row][column]);
            
        } 
        
    }
    
    // nested for loop algorithm that connects all vertical sides
    for(int row = 0; row < dimension - 1; row++) {
        for(int column = 0; column < dimension; column++) {
            
            // connects all vertical sides of squares to each other
            userMaze[row][column].setDown(&userMaze[row + 1][column]);
            userMaze[row + 1][column].setUp(&userMaze[row][column]);
            
        } 
        
    }
    
}


// this function is reponsible for the RNG and maze carving
void Maze::generatePaths() {
    
    // the square stack
    stack<Square*> squareStack;
    
    // seeding
    srand(seed);
    
    // 4 sides to start from
    int startingSide = (rand() % 4) + 1;
    
    // random number from 0 to dimension length
    int randomNum = rand() % dimension;
    
    // switch statement that will determine where to carve out the starting point from random variables above, winning square will be first item in stack
    switch(startingSide) {
        case 1: 
            squareStack.push(&userMaze[0][randomNum]);
            userMaze[0][randomNum].setMap(true);
            userMaze[0][randomNum].setUpBorder(false);
            break;
        case 2:
            squareStack.push(&userMaze[dimension - 1][randomNum]);
            userMaze[dimension - 1][randomNum].setMap(true);
            userMaze[dimension - 1][randomNum].setDownBorder(false);
            break;
        case 3: 
            squareStack.push(&userMaze[randomNum][dimension - 1]);
            userMaze[randomNum][dimension - 1].setMap(true);
            userMaze[randomNum][dimension - 1].setRightBorder(false);
            break;
        case 4: 
            squareStack.push(&userMaze[randomNum][0]);
            userMaze[randomNum][0].setMap(true);
            userMaze[randomNum][0].setLeftBorder(false);
            break;
    }
    
    // currArea keeps track of cumulative squares used and maxArea is the maximum amount of sauares
    int currArea = 1;
    int maxArea = dimension * dimension;
    
    // while loop that ends once every square has been filled
    while(currArea < maxArea) {
        
        // squares that make it into this list will be elgible for random selection
        vector<Square*> elgibleSquares;
        
        // checks if top qualifies for random selection list
        if(squareStack.top()->getUp() != NULL && squareStack.top()->getUp()->isMapped() == false) {
            elgibleSquares.push_back(squareStack.top()->getUp());
        }
        
        // checks if down qualifies for random selection list
        if(squareStack.top()->getDown() != NULL && squareStack.top()->getDown()->isMapped() == false) {
            elgibleSquares.push_back(squareStack.top()->getDown());
        }
    
        // checks if right qualifies for random selection list
        if(squareStack.top()->getRight() != NULL && squareStack.top()->getRight()->isMapped() == false) {
            elgibleSquares.push_back(squareStack.top()->getRight());
        }
        
        // checks if left qualifies for random selection list
        if(squareStack.top()->getLeft() != NULL && squareStack.top()->getLeft()->isMapped() == false) {
            elgibleSquares.push_back(squareStack.top()->getLeft());
        }
        
        // pops from stack if there are no available paths
        if(elgibleSquares.empty() == true) {
            squareStack.pop();
        }
        
        else {
            
            // seeding that changes every loop
            srand(seed + currArea);
            
            // randomizes index that will be used to determine path
            int index = rand() % elgibleSquares.size();
            
            
            // the following conditional statements determine the path the maze took 
            // the borders in the path will be destroyed and the new square will be pushed to stack
            if(squareStack.top()->getUp() == elgibleSquares[index]) {
                squareStack.top()->setUpBorder(false);
                squareStack.push(elgibleSquares[index]);
                squareStack.top()->setDownBorder(false);
            }
            
            else if(squareStack.top()->getDown() == elgibleSquares[index]) {
                squareStack.top()->setDownBorder(false);
                squareStack.push(elgibleSquares[index]);
                squareStack.top()->setUpBorder(false);
            }
            
            else if(squareStack.top()->getRight() == elgibleSquares[index]) {
                squareStack.top()->setRightBorder(false);
                squareStack.push(elgibleSquares[index]);
                squareStack.top()->setLeftBorder(false);
            }
            
            else {
                squareStack.top()->setLeftBorder(false);
                squareStack.push(elgibleSquares[index]);
                squareStack.top()->setRightBorder(false);
            }
            
            // new square will become mapped
            elgibleSquares[index]->setMap(true);
            
            // increment because a new square has been filled
            currArea++;
        
            
        }
        
        
    }
    
    // randomized ending point
    srand(seed + 69);
    
    // 4 sides to end on
    int endingSide = (rand() % 4) + 1;
    
    // random number from 0 to dimension length
    randomNum = rand() % dimension;
    
    switch(endingSide) {
        case 1: 
            squareStack.push(&userMaze[0][randomNum]);
            userMaze[0][randomNum].setMap(true);
            userMaze[0][randomNum].setUpBorder(false);
            break;
        case 2: // Excelleent
            squareStack.push(&userMaze[dimension - 1][randomNum]);
            userMaze[dimension - 1][randomNum].setMap(true);
            userMaze[dimension - 1][randomNum].setDownBorder(false);
            break;
        case 3: 
            squareStack.push(&userMaze[randomNum][dimension - 1]);
            userMaze[randomNum][dimension - 1].setMap(true);
            userMaze[randomNum][dimension - 1].setRightBorder(false);
            break;
        case 4: 
            squareStack.push(&userMaze[randomNum][0]);
            userMaze[randomNum][0].setMap(true);
            userMaze[randomNum][0].setLeftBorder(false);
            break;
    }
    
}

// randomly generates a maze with the users seed and dimension
void Maze::createMaze() {
    
    // allocates squares in 2d array
    createDynamicArray();

    // creates maze border
    createMazeBorder();
    
    // links all nodes to each other
    linkAllSquares();
    
    // creates maze paths
    generatePaths();

    
}

// prints the maze to console
void Maze::visualizeMaze() {
    
    cout << endl;
    
    for(int column = 0; column < dimension; column++) {
        
        if(userMaze[0][column].hasUpBorder()) {
            cout << " _";
        }
        
        else {
            cout << "  ";
        }
        
    }
    
    cout << endl;
    
    for(int row = 0; row < dimension; row++) {
        
        if(userMaze[row][0].hasLeftBorder()) {
            cout << "|";
        }
        
        else {
            cout << " ";
        }
        
        
        for(int column = 0; column < dimension; column++) {
            
           if(userMaze[row][column].hasDownBorder()) {
               cout << "_";
           }
           
           else {
               cout << " ";
           }
            
           if(userMaze[row][column].hasRightBorder()) {
               cout << "|";
           }
           
           else {
               cout << " ";
           }
            
            
        }
        
        cout << endl;
        
    }
    
}
    
