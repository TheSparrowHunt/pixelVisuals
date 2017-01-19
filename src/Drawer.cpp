//
//  Drawer.cpp
//  shortTest
//
//  Created by Jake Sparrow-Hunter on 02/12/2016.
//
//

#include "Drawer.hpp"


Drawer::Drawer(int _position, std::array<unsigned int,57600>* _drawspace, int _speed, int _life){
    position = _position;
    drawspace = _drawspace;
    speed = _speed;
    life = _life;
    state = 1;
}

void Drawer::draw(){
    (*drawspace)[position] = ((*drawspace)[position]+1)%15;
    position = positive_modulo(position+speed, 57600);
    lifeCheck();
}

//method for checking life of Drawer and switching states
void Drawer::lifeCheck(){
    if (life <= 0){
        state = 0;
    }
    else{
        life--;
    }
}

//probably should be contained in another class, that can be #included, but I'm not building my own
//weird maths library right now
//implemented with a variation on the following stackoverflow answer
//http://stackoverflow.com/questions/14997165/fastest-way-to-get-a-positive-modulo-in-c-c
unsigned int Drawer::positive_modulo(int i, int n){
    return (unsigned int)(i % n + n) % n;
}