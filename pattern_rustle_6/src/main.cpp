#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
	//ofSetupOpenGL(867,873,OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	//ofRunApp(new ofApp());
    
    ofGLFWWindowSettings settings;
    settings.setSize(867, 860);
    settings.decorated = false;
    ofCreateWindow(settings);
    ofRunApp(new ofApp);

}
