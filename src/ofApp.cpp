#include "ofApp.h"




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
    //this is currently hard coded, future refactor will introduce a way to manually assign the drawspace size
    //window size locking
    for(unsigned int i = 1; i < 20; i++ ){
        
        //if window is less than 320(big pixel width)*i
        if(windowWidth < 320*i){
            
            //protection against setting the window space to nothing
            if (i > 1){
                
                //allocate the display image at the correct size
                displayImage.allocate(320*(i-1), 180*(i-1), OF_IMAGE_COLOR);
                
                //lock the screen width and height to the size of the displayImage
                windowWidth = 320*(i-1);
                break;
            }
            else{
                
                //smallest possible 1:1 ration with the pixel Array
                displayImage.allocate(320, 180, OF_IMAGE_COLOR);
                windowWidth = 320;
                break;
            }
        }
        
    }
    //locking the window to a 16:9 width:height ratio, this will need to be refactored later
    //to accommodate for non 16:9 resolutions
    ofSetWindowShape(windowWidth, (windowWidth/16)*9);
    
    //defining pixel sizes
    //REFACTOR later
    pixelWidth = displayImage.getWidth()/320;
    pixelHeight = pixelWidth;
}


//--------------------------------------------------------------
void ofApp::setup(){
    //setting up the arrays
    pixelArray = new std::array<unsigned int, 57600>;
    previousPixelArray = new std::array<unsigned int, 57600>;
    //setting the framerate, useful for TESTing
    ofSetFrameRate(60);
    //protection against the application launching in an unsupported resolution
    resizeScaling();
    
    //zeroing the pixel array (ready for the user to use)
    clearDisplay();
    
    setupColors();
    
    counter = 0;
    otherCounter = 1;
    
    //zero the display (removing visual glitches)
    for(int i = 0; i < pixelArray->size(); i++){
            ofColor thisColor;
            thisColor = colors[(*pixelArray)[i]];
            for(int j = 0; j < pixelWidth; j++){
                for (int k = 0; k < pixelHeight; k++){
                    displayImage.setColor((i%320*(pixelWidth))+j, ((i/320)*pixelHeight)+k, thisColor);
                }
                
            }
        }
    
    //initialising new drawer state
    newDrawerState = 'q';
    //initialising a speed value for new Drawers and life value
    speed = 1;
    life = 100;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    resizeScaling();
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(colors[0]);
    
    //"draws" each of the Drawers in drawers
    for_each(drawers.begin(), drawers.end(), [](Drawer* d){d->draw();});
    
    //much more efficient method of drawing
    //draws only the changes to an image, then displays the image at a 1:1 pixel ratio.
    for(int i = 0; i < pixelArray->size(); i++){
        if ((*pixelArray)[i] != (*previousPixelArray)[i]){
            ofColor thisColor;
            thisColor = colors[(*pixelArray)[i]];
            for(int j = 0; j < pixelWidth; j++){
                for (int k = 0; k < pixelHeight; k++){
                    displayImage.setColor((i%320*(pixelWidth))+j, ((i/320)*pixelHeight)+k, thisColor);
                }
        
            }
        }
        
        
    }
    //update the image
    displayImage.update();
    //draw the image
    displayImage.draw(0, 0);
    
}

void ofApp::mapMouse(){
    //getting mouse position and constraining values to within window
    if (mouseX > 0){
        if (mouseX < windowWidth){
            constrainedMouse[0] = mouseX;
        }
        else{
            constrainedMouse[0] = windowWidth-1;
        }
    }
    else{
        constrainedMouse[0] = 0;
    }
    
    if (mouseY > 0){
        if (mouseY < windowHeight){
            constrainedMouse[1] = mouseY;
        }
        else{
            constrainedMouse[1] = windowHeight-1;
        }
    }
    else{
        constrainedMouse[1] = 0;
    }
    
    for (int i = 0; i < mappedMouse.size(); i++){
        mappedMouse[i] = constrainedMouse[i]/pixelWidth;
    }
    mappedMouseDirect = (mappedMouse[1]*320)+mappedMouse[0];
    
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    //if a key is released
    switch(key){
        case 'q' : newDrawerState = 'q';
            break;
        case 'a' : newDrawerState = 'a';
            break;
        case 'w' : speed++;
            break;
        case 's' : speed--;
            break;
        case 'e' : life++;
            break;
            //protecting against < 2 life
        case 'd' : if (life < 2){life = 1;} else {life--;};
            break;
        
    }
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    mapMouse();
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    switch (newDrawerState){
        case 'a' : drawers.push_back(new Drawer(mappedMouseDirect, pixelArray, speed, life));
            break;
        case 'q' : drawers.push_back(new DrawerModeQ(mappedMouseDirect, pixelArray, speed, life));            break;
    }
    cout << newDrawerState;
}

void ofApp::clearDisplay(){
    for (unsigned int i : *pixelArray){
        i = 0;
    }
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



