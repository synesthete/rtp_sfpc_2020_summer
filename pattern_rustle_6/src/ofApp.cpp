#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(238, 240, 239);
    ofSetColor(48, 48, 50);
    
    // get name of app for naming screenshots
    appname = ofFilePath::getBaseName(ofFilePath::getCurrentExePath());
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSeedRandom(mouseX);
    // set margin on left and top
    ofTranslate(17, 5, 0);
    // first iteration gets no vertical offset
    offsetY = 0;
    // iterate through all the rows
    for ( int i = 0; i < 15; i++ ) {
        // reset horizontal offset for each row
        offsetX = 0;
        // every instance after the first in the row gets vertical offset
        if ( i > 0 ) {
            offsetY += 55;
        }
        // interate across each row
        for ( int j = 0; j < 14; j++ )  {

            // negative horizontal offset for fist triangle on odd rows.
            if ( i % 2 != 0 && j == 0) {
                offsetX = -31;
            } else if ( j > 0 ) {
                // for odd rows first offset is 1/2 size
                if ( i % 2 != 0 && j == 1) {
                    offsetX = 31;
                } else {
                offsetX += 63;
                }
            }
            // don't draw last triangle for even rows
            if ( !(i % 2 == 0 && j == 13) ) {
                // move to our offset position, then scale and draw triangle
                ofPushMatrix();
                    ofTranslate(offsetX, offsetY, 0);
                    // Define a circle with center and thee points on the circumference to create a triangle
                    ofPoint center (37,37);
                    ofPoint a = center + 37 * ofPoint(cos(PI/2), sin(PI / 2));
                    ofPoint b = center + 37 * ofPoint(cos(PI/2 + TWO_PI/3.0), sin(PI / 2+ TWO_PI/3.0));
                    ofPoint c = center + 37 * ofPoint(cos(PI/2+ 2*TWO_PI/3.0), sin(PI / 2+ 2*TWO_PI/3.0));
                    ofPath p;
                    p.clear();
                    p.moveTo(a);
                    // first triangle on odd rows is cut in half
                    if ( i % 2 != 0 && j == 0 ) {
                        ofPoint d  ((b.x + (( c.x - b.x) / 2)), b.y);
                        p.lineTo(d);
                    } else {
                        p.lineTo(b);
                    }
                    // for any triangles not on the first, last or rightmost rows and column
                    if ( ( ofRandom(1.0) < 0.20) && (i > 0 && i < 14) && ( j < 13 ) ) {
                        // draw concave arc between the second and third points
                        ofPoint mid = (a+c)/2.0;
                        ofPoint newPt = mid + (mid-b);
                        float distance = (b-a).length();
                        p.setCircleResolution(360);
                        p.arc(newPt, distance,distance, 180 + 60, 180, false);
                    // for any triangles not on the first, last or rightmost rows and column
                    } else if ( ( ( ofRandom(1.0) > 0.2 && ofRandom(1.0) < 0.4) ) && (i > 0 && i < 14) && ( j < 13 ) ) {
                        // draw convex arc between the second and third points
                        float distance = (b-a).length();
                        p.setCircleResolution(360);
                        p.arc(b, distance,distance, 0,60);
                    }
                    // last triangle on odd rows is cut in half
                    if ( j == 13 ) {
                        ofPoint e  ((b.x + (( c.x - b.x) / 2)), b.y);
                        p.lineTo(e);
                    } else {
                        p.lineTo(c);
                    }
                    p.close();
                    p.setFillColor(0x303032);
                    p.setFilled(true);
                    p.draw();
                
                ofPopMatrix();
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    // make a screenshot of the app window when "p" key is released
    switch (key) {
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
