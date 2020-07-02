#pragma once

#include "ofMain.h"
#include "ofxSvg.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void draw();
		void keyReleased(int key);
		
        string appname;
        ofxSVG logo;
        float offsetX;
        float offsetY;
        float drawWidth;
        float margin;
    
        // large output
        ofFbo largeOffscreenImage;
        int w, h;
};
