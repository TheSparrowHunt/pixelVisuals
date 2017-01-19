//
//  Drawer.hpp
//  shortTest
//
//  Created by Jake Sparrow-Hunter on 02/12/2016.
//
//

#ifndef Drawer_hpp
#define Drawer_hpp

#include <stdio.h>
#include <array>
#include <iostream>

using namespace std;

class Drawer{
public:
    unsigned int position;
    std::array<unsigned int, 57600>* drawspace;
    int speed, life;
    int state;
    Drawer(int _position, std::array<unsigned int, 57600>* _drawSpace, int _speed, int _life);
    void draw();
    void lifeCheck();

    unsigned int positive_modulo(int i, int n);
};

#endif /* Drawer_hpp */
