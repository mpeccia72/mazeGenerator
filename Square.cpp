// Michael Peccia, CS 269 Week 9 EC
// file description: square implementation file

#include "Square.h"


// returns up square
Square* Square::getUp() {
    return U;
}

// returns down square
Square* Square::getDown() {
    return D;
}

// returns left square
Square* Square::getLeft() {
    return L;
}

// returns right square
Square* Square::getRight() {
    return R;
}

    
// sets up square
void Square::setUp(Square* sqr) {
    U = sqr;
}

// sets down square
void Square::setDown(Square* sqr) {
    D = sqr;
}

// sets left square
void Square::setLeft(Square* sqr) {
    L = sqr;
}

// sets right square
void Square::setRight(Square* sqr) {
    R = sqr;
}



// returns up border status
bool Square::hasUpBorder() {
    return upBorder;
}

// returns down border status
bool Square::hasDownBorder() {
    return downBorder;
}

// returns left border status
bool Square::hasLeftBorder() {
    return leftBorder;
}

// returns right border status
bool Square::hasRightBorder() {
    return rightBorder;
}


// sets up border status
void Square::setUpBorder(bool input) {
    upBorder = input;
}

// sets down border status
void Square::setDownBorder(bool input) {
    downBorder = input;
}

// sets left border status
void Square::setLeftBorder(bool input) {
    leftBorder = input;
}

// sets right border status
void Square::setRightBorder(bool input) {
    rightBorder = input;
}



// returns map status
bool Square::isMapped() {
    return mapped;
}

// sets map status
void Square::setMap(bool input) {
    mapped = input;
}