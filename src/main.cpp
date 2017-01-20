#include "ofMain.h"
#include "ofApp.h"
#include "stdio.h"
/*========================================================================
Use of this Programme:
use the Q and A keys to switch what type of "Drawer" you generate.
use the W and S keys to increase and decrease the speed of the "Drawers" you create
use the E and D keys to increase and decrease the life of the "Drawers" you create NOT FUNCTIONING CURRENTLY
Currently there are only two Drawer types, in future updates, this programme will
have mmany more drawer types, but significant parts of this programme will need to be refactored
for them to function correctly
Jake Sparrow-Hunter @ 20/01/2016
//========================================================================*/
int main( ){
	ofSetupOpenGL(960,540,OF_WINDOW);			// <-------- setup the GL context
	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}
