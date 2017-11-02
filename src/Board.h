#pragma once

#include "ofMain.h"


class Board {

public:
    // Update the position, velocity and acceleration
    void update();
    
    // Will render the particle on the screen
    void draw();
    
    
    float boardWidth = 200;
    float boardHeight = 10;
    
    float xPosition;
    float yPosition;
    
    
    
};
