//
//  Particle.hpp
//  mySketch
//
//  Created by cc on 11/27/15.
//
//

#ifndef Particle_hpp
#define Particle_hpp

#include <stdio.h>
#include "ofMain.h"

class Particle {
public:
    ofPoint loc, vel, acc;
    ofPoint *hist;
    int counter;
    Particle(){};
    Particle(ofPoint l);
    void update();
    void draw();
//    void drawArrowHead(ofPoint v, ofPoint loc, float scale);
};



#endif /* Particle_hpp */
