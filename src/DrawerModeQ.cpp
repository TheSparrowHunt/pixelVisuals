//
//  DrawerModeQ.cpp
//  shortTest
//
//  Created by Jake on 19/01/2017.
//
//

#include "DrawerModeQ.hpp"

void DrawerModeQ::draw(){
    (*drawspace)[position] = ((*drawspace)[position]+1)%15;
    position = positive_modulo(position, 57600);
    lifeCheck();
}