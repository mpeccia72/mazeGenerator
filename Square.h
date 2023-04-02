// Michael Peccia, CS 269 Week 9 EC
// file description: square header file

class Square {
    
    // nodes that point to up, down, left, and right squares respectively
    Square* U;
    Square* D;
    Square* L;
    Square* R;
    
    // borders of the square, all borders are set to true by default to allow the maze generation to carve away paths
    bool upBorder = true;
    bool downBorder = true;
    bool leftBorder = true;
    bool rightBorder = true;
    
    // shows if square has been used in maze generation process so squares won't be re-used, un-used (false) by default
    bool mapped = false;
    
    public:
        
        // accesesor
        Square* getUp();
        Square* getDown();
        Square* getLeft();
        Square* getRight();\
        
        bool hasUpBorder();
        bool hasDownBorder();
        bool hasLeftBorder();
        bool hasRightBorder();
        
        bool isMapped();
        
        // mutator
        void setUp(Square*);
        void setDown(Square*);
        void setLeft(Square*);
        void setRight(Square*);
        
        void setUpBorder(bool);
        void setDownBorder(bool);
        void setLeftBorder(bool);
        void setRightBorder(bool);
        
        void setMap(bool);
    
};