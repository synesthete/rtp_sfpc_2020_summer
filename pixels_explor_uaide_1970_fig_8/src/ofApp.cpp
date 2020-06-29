#include "ofApp.h"

/*
 UAIDE: Proceedings of the 9th Annual Meeting, Miami Beach, Florida, 1970
 EXPLOR - A Generator of Images from Explicit Patterns, Local Operations and Randomness,
    K C Knowlton, Bell Telephone Laboratories
 http://www.content-animation.org.uk/htmls/uaide_1970.htm#Dp2p4
 
 C Figure 8. Probabilistic Squares and Rectangles
                          0
 1     CHV (1,1)DEL, SET, 4
                         42
 2     CHV (1,1) WIDTH, SET, 19
 3 HS  CHV (1,1) HEIGHT, SET, WIDTH
 4 CH  CHV (7,1) HEIGHT, ADD, DEL
 5     CHV (7,1) WIDTH, SUB, DEL, DEL, BX
 6     CHV (6,1) WIDTH, ADD, DEL
 7 BX  BXL (1,1) 05 ( 304, 207 WIDTH, HEIGHT, 21, 21, 14, 9) 1 (A...)
                 10
 8     GOTO (X, 7, 1) CH
 9     XLI (1,1) BX, XLIT 1 (0A,A0)
10     CHV (X, 5, 1) WIDTH, SUB 4, 4, HS
 
 */

//--------------------------------------------------------------
void ofApp::setup(){
    appname = ofFilePath::getBaseName(ofFilePath::getCurrentExePath());
    
    // set our canvas size based on EXPLOR tile of 340 x 240
    w = 680;
    h = 480;
    
    // Set "DEL" value on line 1
    DEL = 0; // Set initial CHV DEL = 0;
    // set width and height - lines 2 & 3
    rect_w = 19;
    rect_h = 19;
    
    grayPixels.allocate(w,h,OF_PIXELS_GRAY);

    texGray.allocate(grayPixels);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    ofSeedRandom(23);
    all_the_rects = 0;
    // set loop for making 5 squares at each location - line 10
    for (int k = 0; k < 5; k++) {
        // center 14 squares across
        for (int i = 193; i < 487; i+=22){
            // center 9 squares down
            for (int j = 145; j < 334; j+=22){
                // count for doing caluculations based on every 7th or 6th iteration - lines 4, 5, & 6
                all_the_rects += 1;
                // chance of drawing a rectangle at a give position and size - line 7 ( 05 or 10 )
                if ( ofRandom(5) < 4 ) {
                    rect_w = 19;
                    rect_h = 19;
                    // adjust height every 7th time - line 4
                    if ( all_the_rects % 7 == 0 ) {
                        rect_h = rect_h + DEL;
                    }
                    // this essentially made all the tall rectangle have no width. :(
                    /*
                        if ( all_the_rects % 7 == 0 ) {
                            rect_w = rect_w - DEL;
                        }
                     */
                    // adjust width every 6th time - line 6 ( note the skip in the previous line 5 )
                    if ( all_the_rects % 6 == 0 && all_the_rects % 7 != 0 ) {
                        rect_w = rect_w + DEL;
                    }
                    // make a rectangle
                    rect = ofRectangle(i, j, rect_w - (k * 4), rect_h - (k * 4));
                    // prep for drawing rectangle pixel by pixel
                    int xs = rect.x - ( rect.width / 2 );
                    int ys = rect.y - ( rect.height / 2 );
                    int width  = rect.width  + xs;
                    int height = rect.height + ys;
                        for(int y = ys; y < height; y++) {
                            for(int x = xs; x < width; x++) {
                                // alternate white and black rectangles as we iterate at the same position
                                if ( k % 2 == 0 ) {
                                    color = ofColor::white;
                                } else {
                                    color = ofColor::black;
                                }
                                grayPixels.setColor(x,y,color);
                            }
                        }
                }
            }
        }
    }
    texGray.loadData(grayPixels.getData(), w,h, GL_LUMINANCE);
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255,0,0);
    ofSetHexColor(0xffffff);
    
    texGray.draw(0,0,w,h);
}

//--------------------------------------------------------------
void ofApp::reset(int newDEL){
    // set a new value for "DEL" and clear the drawing. << CLEAR is NOT working as expected
    DEL = newDEL;
    grayPixels.clear();
    grayPixels.allocate(w,h,OF_PIXELS_GRAY);
    texGray.clear();
    texGray.allocate(grayPixels);
    all_the_rects = 0;
    rect_w = 19;
    rect_h = 19;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    switch (key) {
        case '1':
            reset(0);
        break;
        case '2':
            reset(4);
        break;
        case '3':
            reset(42);
        break;
        // make a screenshot of the app window when "p" key is released
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
