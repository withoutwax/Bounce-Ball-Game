#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    sound.load("ball.wav");
    sound.setMultiPlay(true);
    
    p.position.x = ofGetWidth()/2;
    p.position.y = ofGetHeight()/2;
    
    p.velocity.x = 7;
    p.velocity.y = 7;
    
    p.acceleration.y = 1;
    
    

}

//--------------------------------------------------------------
void ofApp::update(){
    if (life > 0) {
        
        b.update();
        p.update();
        
    } else {
        
    }
    
    
    // Check the right wall.
    if (p.position.x + p.radius > ofGetWidth()) {
        
        p.velocity.x = p.velocity.x * -1;
        p.position.x = ofGetWidth() - p.radius;
        sound.play();
    }
    // Check the left wall.
    else if (p.position.x - p.radius < 0) {
        
        p.velocity.x = p.velocity.x * -1;
        p.position.x = 0 + p.radius;
        sound.play();
    
    }
    
    // Check the paddle(board).
 
    else if ((b.xPosition < p.position.x && p.position.x < (b.xPosition + b.boardWidth)) && (p.position.y + p.radius > b.yPosition)) {
        p.velocity.y = p.velocity.y * -1;
        p.position.y = b.yPosition - p.radius;
        
        score++;
        sound.play();
    } else if (p.position.y - p.radius > ofGetHeight()) {
        //RESTART
        p.position.x = ofGetWidth()/2;
        p.position.y = 50;
        p.velocity.x = 7;
        p.velocity.y = 7;
        
        p.acceleration.y = 1;
        
        if (life > 0) {
           life--;
        } else {
            score = highScore;
        }
        
    }


}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    if (life > 0) {
        
        p.draw();
        b.draw();
        ofDrawBitmapString("Score", 100, 100);
        ofDrawBitmapString(score, 150, 100);
        
        ofDrawBitmapString("Life", 100, 120);
        ofDrawBitmapString(life, 150, 120);
    } else {
        
        gameOver();
    }

}




void ofApp::gameOver(){
    
    ofDrawBitmapString("GAMEOVER", ofGetWidth()/2, ofGetHeight()/2);
    ofDrawBitmapString("SCORE", ofGetWidth()/2, (ofGetHeight()/2)+30);
    ofDrawBitmapString(score, (ofGetWidth()/2)+50, (ofGetHeight()/2)+30);
    
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
