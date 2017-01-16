//
//  Drawer.cpp
//  shortTest
//
//  Created by Jake Sparrow-Hunter on 02/12/2016.
//
//

#include "Drawer.hpp"
unsigned int position;
std::array<unsigned int, 57600>* drawspace;

Drawer::Drawer(int _position, std::array<unsigned int,57600>* _drawspace){
    position = _position;
    drawspace = _drawspace;
    
}

void Drawer::draw(){
    (*drawspace)[position] = ((*drawspace)[position]+1)%15;
    position = (unsigned int)(position+2)%57600;
}
