#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //ofSetBackgroundColor(211, 112, 85);
    ofSetBackgroundColor(214, 113, 85);
    //ofBackgroundHex(0xFA8072);
    appname = ofFilePath::getBaseName(ofFilePath::getCurrentExePath());
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    /*
     1024 * 720
     top margin 165
     left margin 250
     right margin 250
     bottom margin 200
     width 520
     height 355
     squares 50
     col 9
     row 6
     
     */
    if ( exportSVG ) {
        ofBeginSaveScreenAsSVG(appname+"_"+ofGetTimestampString()+".svg");
    }
    //ofSeedRandom(0);
    ofSeedRandom(mouseY);
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 6; j++) {
                float x = ofMap(i, 0, 9, 274, 796);
                float y = ofMap(j, 0, 6, 190, 545);
                makeShape(x, y);
            }
        }
        for (int i = 0; i < 7; i++) {
            for (int j = 0; j < 6; j++) {
                float x = ofMap(i, 0, 7, 333, 737) + ofRandom(-10,10);
                float y = ofMap(j, 0, 6, 190, 545) + ofRandom(-10,10);
                makeShape(x, y);
            }
        }
        for (int k = 0; k < 2; k++) {
            for (int i = 0; i < 5; i++) {
               for (int j = 0; j < 6; j++) {
                   float x = ofMap(i, 0, 5, 392, 678) + ofRandom(-10,10);
                   float y = ofMap(j, 0, 6, 190, 545) + ofRandom(-10,10);
                   makeShape(x, y);
               }
            }
        }
        for (int k = 0; k < 2; k++) {
            for (int i = 0; i < 4; i++) {
               for (int j = 0; j < 6; j++) {
                   float x = ofMap(i, 0, 4, 451, 678) + ofRandom(-10,10);
                   float y = ofMap(j, 0, 6, 190, 545) + ofRandom(-10,10);
                   makeShape(x, y);
               }
            }
        }
        for (int k = 0; k < 2; k++) {
            for (int i = 0; i < 2; i++) {
               for (int j = 0; j < 6; j++) {
                   float x = ofMap(i, 0, 2, 508, 619) + ofRandom(-5,5);
                   float y = ofMap(j, 0, 6, 190, 545) + ofRandom(-5,5);
                   makeShape(x, y);
               }
            }
        }
        for (int k = 0; k < 6; k++) {
           for (int j = 0; j < 6; j++) {
               float x = 565 + ofRandom(-10,10);
               float y = ofMap(j, 0, 6, 190, 545) + ofRandom(-5,5);
               makeShape(x, y);
            }
        }
    if ( exportSVG ) {
        ofEndSaveScreenAsSVG();
        exportSVG = false;
    }
}

//--------------------------------------------------------------
void ofApp::makeShape(float x, float y){
    //ofEnableAlphaBlending();    // turn on alpha blending
    ofSetColor(255,255,255,127);
    ofNoFill();
    ofPushMatrix();
    ofBeginShape();
    ofVertex(x - ofRandom(20,30), y - ofRandom(20,30));
    ofVertex(x + ofRandom(20,30), y - ofRandom(20,30));
    ofVertex(x + ofRandom(20,30), y + ofRandom(20,30));
    ofVertex(x - ofRandom(20,30), y + ofRandom(20,30));
    ofEndShape(true);
    ofPopMatrix();
    //ofDisableAlphaBlending();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    switch (key) {
    case 's':
            exportSVG = true;
        break;
    case 'p':
            ofImage image;
            image.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
            
            image.save(appname+"_"+ofGetTimestampString()+".png");
        break;
    }
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
