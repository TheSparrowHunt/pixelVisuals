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
using namespace std;

class Drawer{
public:
    unsigned int position;
    std::array<unsigned int, 57600>* drawspace;
    
    Drawer(int _position, std::array<unsigned int, 57600>* _drawSpace);
    void draw();
};

#endif /* Drawer_hpp */
