#include "ofApp.h"
#include "stdio.h"

//setting up the pixel array at the maximum for unsigned short
std::array<unsigned int, 57600> pixelArray;
ofImage displayImage;

int windowHeight, windowWidth, pixelWidth, pixelHeight, counter;

ofColor colors [15];

void ofApp::setupColors(){
    //setting up colors
    
    colors[0].r = 0    ;  colors[0].g = 0   ;  colors[0].b = 0   ; //black
    colors[1].r = 29   ;  colors[1].g = 43  ;  colors[1].b = 83  ; //dark-blue
    colors[2].r = 127  ;  colors[2].g = 37  ;  colors[2].b = 83  ; //dark-purple
    colors[3].r = 0    ;  colors[3].g = 135 ;  colors[3].b = 81  ; //dark-green
    colors[4].r = 171  ;  colors[4].g = 82  ;  colors[4].b = 54  ; //brown
    colors[5].r = 95   ;  colors[5].g = 87  ;  colors[5].b = 79  ; //dark-grey
    colors[6].r = 194  ;  colors[6].g = 195 ;  colors[6].b = 199 ; //light-grey
    colors[7].r = 255  ;  colors[7].g = 241 ;  colors[7].b = 232 ; //white
    colors[8].r = 255  ;  colors[8].g = 0   ;  colors[8].b = 7   ; //red
    colors[9].r = 255  ;  colors[9].g = 163 ;  colors[9].b = 0   ; //orange
    colors[10].r = 255 ; colors[10].g = 236 ; colors[10].b = 39  ; //yellow
    colors[11].r = 0   ; colors[11].g = 228 ; colors[11].b = 54  ; //green
    colors[12].r = 41  ; colors[12].g = 173 ; colors[12].b = 255 ; //blue
    colors[13].r = 131 ; colors[13].g = 118 ; colors[13].b = 156 ; //indigo
    colors[14].r = 255 ; colors[14].g = 119 ; colors[14].b = 168 ; //pink
    colors[15].r = 255 ; colors[15].g = 204 ; colors[15].b = 170 ; //peach
}

void ofApp::resizeScaling(){
    //getting height and width
    windowHeight = ofGetWindowHeight();
    windowWidth = ofGetWindowWidth();
    displayImage.allocate(windowWidth, windowHeight, OF_IMAGE_COLOR);
    
    //defining pixel sizes
    pixelWidth = windowWidth/320;
    pixelHeight = pixelWidth;
}


//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetFrameRate(60);
    
    resizeScaling();
    
    
    
    
    //filling the pixel array with random chars (for now)
    for (auto i : pixelArray){
        i = 0;
    }
    
    setupColors();
    
    counter = 0;
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    resizeScaling();
    
    pixelArray[counter/2] = 15;
    cout << counter;
    counter = (counter+1)%(2*pixelArray.size());
    
    pixelArray[((counter)/2-1)%pixelArray.size()] = 0;
    
    for(int i = 0; i < pixelArray.size(); i++){
        ofColor thisColor;
        
        thisColor = colors[pixelArray[i]];
        for(int j = 0; j < pixelWidth; j++){
            for (int k = 0; k < pixelHeight; k++){
                displayImage.setColor((i%320*(pixelWidth))+j, ((i/320)*pixelHeight)+k, thisColor);
            }
        
        }
        
        
    }
    displayImage.update();
    
    displayImage.draw(0, 0);
    
    
    
//    for (unsigned int i = 0; i < pixelArray.size(); i++){
//        pixelArray[i] = (char)(rand()%16);
//    }
    //cout << ofGetFrameRate() << endl;
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

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



