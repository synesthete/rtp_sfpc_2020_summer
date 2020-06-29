#include "ofApp.h"

/*
UAIDE: Proceedings of the 9th Annual Meeting, Miami Beach, Florida, 1970
EXPLOR - A Generator of Images from Explicit Patterns, Local Operations and Randomness,
   K C Knowlton, Bell Telephone Laboratories
http://www.content-animation.org.uk/htmls/uaide_1970.htm#Dp2p4

C Figure 7. Randomly Positioned Overlapping Contoured Squares.
1     WBT (1,1) (  ABC, 012, )
                  BC, 12, OA
2 ST  CHV (1,1) SIZE, SET, 30
3     CHV (1,1) XB, SET, 5, 344
4     CHV (1,1) YB, SET, 5, 244
5 BX  BXL    (1,1) 1 (XB, YB, SIZE, SIZE, 1, 1, 1, 1) 1 (CO1XXXXXXX2AB)
6     CHV (X, 15, 1) SIZE, SUB, 2, 2, BX
                60
7     GOTO (X, 120, 1) ST
               200

*/

//--------------------------------------------------------------
void ofApp::setup(){
    appname = ofFilePath::getBaseName(ofFilePath::getCurrentExePath());
    
    // set our canvas size based on EXPLOR tile of 340 x 240
    w = 680;
    h = 480;
    
    grayPixels.allocate(w,h,OF_PIXELS_GRAY);

    ofSeedRandom(23);
    // how many squares - line 7
    for ( int i = 0; i < 200; i++ ) {
        // set x position - line 3
        XB = ofRandom( 30, 650 );
        // set 7 position - line 4
        YB = ofRandom( 30, 450 );
        // loop through drawing sqaures at position - line 6
        for ( int j = 0; j < 15; j++ ) {
            // set up squares, making them smaller each time we loop through j
            rect = ofRectangle(XB, YB, 60 - ( 4 * j ), 60 - ( 4 * j ));
            // prep for drawing square pixel by pixel
            int xs = rect.x - ( rect.width / 2 );
            int ys = rect.y - ( rect.height / 2 );
            int width  = rect.width  + xs;
            int height = rect.height + ys;
                for(int y = ys; y < height; y++) {
                    for(int x = xs; x < width; x++) {
                        // alternate white and black rectangles as we iterate at the same position
                        if ( j % 2 == 0 ) {
                            color = ofColor::white;
                        } else {
                            color = ofColor::black;
                        }
                        // sqaure drawing has a color transform to change over existing pixels
                        // existing white changes to black and black to white
                        ofColor c = grayPixels.getColor(x,y);
                        if ( c.getBrightness() > 127 ) {
                            color = ofColor::black;
                        } else if ( c.getBrightness() < 127 ) {
                            color = ofColor::white;
                        }
                        grayPixels.setColor(x,y,color);
                    }
                }
        }
    }
        
    texGray.allocate(grayPixels);
}

//--------------------------------------------------------------
void ofApp::update(){
    texGray.loadData(grayPixels.getData(), w,h, GL_LUMINANCE);
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0,0,0);
    ofSetHexColor(0xffffff);
    
    texGray.draw(0,0,w,h);
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
