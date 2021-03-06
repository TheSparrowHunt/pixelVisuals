#pragma once

#include "ofMain.h"
#include "stdio.h"
#include "Drawer.hpp"
#include "DrawerModeQ.hpp"
#include "math.h"

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
        void randomPixels();
    
        std::array<unsigned int, 57600>* pixelArray;
        std::array<unsigned int, 57600>* previousPixelArray;
        int windowHeight, windowWidth, pixelWidth, pixelHeight, counter, otherCounter, mappedMouseDirect;
        ofColor colors [16];
        std::vector<Drawer*> drawers;
    
        std::array<signed int, 2> constrainedMouse, mappedMouse;
        ofImage displayImage;
        void setupColors();
        void mapMouse();
        void resizeScaling();
        void clearDisplay();
    
        char newDrawerState;
        int speed;
        unsigned int life;
};
