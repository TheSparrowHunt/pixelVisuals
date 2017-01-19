#include "ofMain.h"
#include "ofApp.h"
#include "stdio.h"




//========================================================================
int main( ){
	ofSetupOpenGL(960,540,OF_WINDOW);			// <-------- setup the GL context
    cout << (-1)%2;
	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}
