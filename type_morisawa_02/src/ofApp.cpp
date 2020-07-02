#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    // large output code from Zach -
    // https://github.com/ofZach/RTP_SFPC_FALL19/tree/master/largeTextureExample
    //
    // assume our target is 8.5x11 -- we can caluate the w/h of the largest
    // texture at that aspect ratio
    
    int value;
    glGetIntegerv(GL_MAX_TEXTURE_SIZE, &value);   //Returns 1 value
    float total = 297 + 210;
    w = (210 / total) * (value-1);
    h = (297 / total) * (value-1);
    largeOffscreenImage.allocate(w, h, GL_RGBA);
    
    // John Maeda - Morisawa 10 (1996) - https://maedastudio.com/morisawa-10-2016/
    // No. 2 - https://i0.wp.com/maedastudio.com/wp-content/uploads/2017/01/mori2.jpg?ssl=1
    // "モリサワ"
    // https://www.morisawa.co.jp
    // logo morisawa svg 180 x 40
    // Cleaned up from https://www.morisawa.co.jp/img/common/corporate_logo_black.svg
    logo.load("corporate_logo_black.svg");
    margin = w * 0.02857142857;
    drawWidth = w - margin;
    cout << drawWidth;
    ofEnableAntiAliasing();
    ofEnableSmoothing();
    // get name of app for naming screenshots
    appname = ofFilePath::getBaseName(ofFilePath::getCurrentExePath());
    
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    largeOffscreenImage.begin();
    
    ofBackground(242);
    // set margin on left and top
    ofTranslate(margin / 2, margin / 2, 0);
    // first iteration gets no additional horizontal offset
    offsetY = 0;
    // iterate through all the rows
    for ( int i = 0; i < 340; i++ ) {
        // no vertical offset for initial row
        offsetX = 0;
        // every instance after the first in the row gets vertical offset
        if ( i > 0 ) {
            offsetY += 40 * ( drawWidth/(180*i));
        }
        // only draw rows up to the bottom margin
        if ( offsetY < h - margin) {
            // each row gets an addition instance of the logo
            for ( int j = 0; j < ( i + 1 ); j++ )  {
                // no offset for the first logo instance in the row
                if ( j > 0 ) {
                    offsetX = j * (drawWidth/(i+1));
                }
                // move to our offset position, then scale and draw the logo
                ofPushMatrix();
                    ofTranslate(offsetX, offsetY, 0);
                    ofScale(drawWidth/(180*(i+1)));
                    logo.draw();
                ofPopMatrix();
            }
        }
    }
    
    largeOffscreenImage.end();
    
    ofRectangle bounds(0,0, ofGetWidth(), ofGetHeight());
    ofRectangle target(0,0,w,h);
    target.scaleTo(bounds);
    
    largeOffscreenImage.draw(target);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    // make a screenshot of the app window when "p" key is released
    switch (key) {
//        case 'p':
//                ofImage image;
//                image.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
//                
//                image.save(appname+"_"+ofGetTimestampString()+".jpg");
//        break;
        case 'p':
             ofPixels p;
             largeOffscreenImage.readToPixels(p);
             ofSaveImage(p, appname+"_"+ofGetTimestampString() + ".png");
        break;
    }
}
