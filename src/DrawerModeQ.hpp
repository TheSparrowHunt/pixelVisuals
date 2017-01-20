//
//  DrawerModeQ.hpp
//  shortTest
//
//  Created by Jake on 19/01/2017.
//
//

#ifndef DrawerModeQ_hpp
#define DrawerModeQ_hpp

#include <stdio.h>
#include <Drawer.hpp>
#include <array>
using namespace std;
//derived class
class DrawerModeQ : public Drawer{
public:
    DrawerModeQ(int _position, std::array<unsigned int, 57600>* _drawSpace, int _speed, int _life) : Drawer(_position, _drawSpace, _speed, _life){
        
    }
    void draw();
    
};

#endif /* DrawerModeQ_hpp */
