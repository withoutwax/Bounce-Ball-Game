#include "Board.h"



void Board::update() {
    xPosition = ofGetMouseX();
    yPosition = ofGetHeight() - 50;
    
}

void Board::draw() {
    
    
    ofDrawRectangle(xPosition, yPosition, boardWidth, boardHeight);
    
}
