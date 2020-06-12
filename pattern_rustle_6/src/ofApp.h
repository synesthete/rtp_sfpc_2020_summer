#pragma once

//#include "ofxVectorGraphics.h"
#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        string appname;
        float offsetX;
        float offsetY;
        float x1;
        float y1;
        float x2;
        float y2;
        float x3;
        float y3;
        //ofxVectorGraphics output;
        //vector<ofPolyline> output;
        ofPath output;
        ofVboMesh tessellation;
};
