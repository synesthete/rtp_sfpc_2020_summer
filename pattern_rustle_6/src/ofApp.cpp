#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(238, 240, 239);
    ofSetColor(48, 48, 50);
    // get name of app for naming screenshots
    appname = ofFilePath::getBaseName(ofFilePath::getCurrentExePath());
    //output.setMode(ofPath::POLYLINES);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
//    x1 = 0;
//    y1 = 0;
//    x2 = 63;
//    y2 = 0;
//    x3 = 31;
//    y3 = 55;
//    output.clear();
//    output.newSubPath();
//        output.moveTo(x1,y1);
//        output.lineTo(x2,y2);
//        output.setCurveResolution(1000);
//        output.moveTo(x2,y2);
//        output.curveTo(x2 - 22,y2 + 21);
//        output.curveTo(x3,y3);
//        output.moveTo(x3,y3);
////        output.lineTo(x3,y3);
//        output.lineTo(x1,y1);
//    output.close();
//    output.setFillColor(0x00000);
//    output.setFilled(true);
//    tessellation = output.getTessellation();
//    tessellation.drawWireframe();
    
    ofSeedRandom(23);
    // set margin on left and top
    ofTranslate(24, 24, 0);
    // first iteration gets no additional horizontal offset
    offsetY = 0;
    // iterate through all the rows
    for ( int i = 0; i < 14; i++ ) {
        // no vertical offset for initial row
        offsetX = 0;
        // every instance after the first in the row gets vertical offset
        if ( i > 0 ) {
            offsetY += 55;
        }
        // each row gets an addition instance of the logo
        for ( int j = 0; j < 14; j++ )  {
            // full triangle points
            x1 = 0;
            y1 = 0;
            x2 = 63;
            y2 = 0;
            x3 = 31;
            y3 = 55;
            // for odd rows draw sliced triangles at start and end
            if ( i % 2 != 0) {
                // start of row
                if ( j == 0 ) {
                    x1 = 0;
                    y1 = 0;
                    x2 = 31;
                    y2 = 0;
                    x3 = 0;
                    y3 = 55;
                }
                // end of row
                if ( j == 13 ) {
                    x1 = 0;
                    y1 = 0;
                    x2 = 31;
                    y2 = 0;
                    x3 = 31;
                    y3 = 55;
                }
            }
            // after the first triangle, add offset
            if ( j > 0 ) {
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
//                        output.clear();
//                        output.newSubPath();
//                            output.moveTo(x1,y1);
//                            output.lineTo(x2,y2);
//                            output.lineTo(x3,y3);
//                            output.lineTo(x1,y1);
//                        output.close();
//                        output.setFillColor(0x00000);
//                        output.setFilled(true);
//                        output.draw();
                
                output.clear();
                output.newSubPath();
                    output.moveTo(x1,y1);
                    output.lineTo(x2,y2);
                    if ( (ofRandom(1.0) < 0.15) && (i > 0 && i < 13) && ( j < 13 )) {
                        //if ( j < 13 ) {
                            output.moveTo(x1,y1);
                            output.setCircleResolution(1000);
                            if ( i % 2 != 0 && j == 0) {
                                x1 = -31;
                            }
                            output.arc(x1,y1,63,63,0,60);
                            //output.arc(50,94,63,63,180,60);
                            x1 = 0;
                        //}
                    } else {
                        output.lineTo(x3,y3);
                    }
                    output.lineTo(x1,y1);
                output.close();
                output.setFillColor(0x00000);
                output.setFilled(true);
                output.draw();
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
            
            image.save(appname+"_"+ofGetTimestampString()+".jpg");
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
