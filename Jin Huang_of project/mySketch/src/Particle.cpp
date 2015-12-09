//
//  Particle.cpp
//  mySketch
//
//  Created by cc on 11/27/15.
//
//

#include "Particle.hpp"


float mag(ofPoint in){
    float retf = sqrt(in.x * in.x + in.y * in.y);
    return retf;
}


Particle::Particle(ofPoint l){
    counter = 0;
    float randmin = -PI;
    float randmax = 0;
    
    float r = ofRandom(0, TWO_PI);
    float x = 5*cos(r);
    float y = 5*sin(r);
    acc = ofPoint(x / 50, y / 50);
    
    float q = ofRandom(0, 1);
    r = ofRandom(randmin, randmax);
    x = 5*cos(r) * q;
    y = 5*sin(r) * q;
    vel = ofPoint(x, y);
    loc = l;
    hist = new ofPoint[100];
}

void Particle::update(){
    vel += acc;
    loc += vel;
    if(ofGetFrameNum() % 10 == 0 && counter < 100){
        hist[counter].x = loc.x;
        hist[counter].y = loc.y;
        counter++;
    }
}

void Particle::draw(){
    ofFill();
//    ofSetColor(66, 131, 252, 100);
//    drawArrowHead(vel, loc, 10);
    ofNoFill();
//    ofSetColor(66, 131, 252, 100);
    ofBeginShape();
    for(int i = 0; i < counter; i++){
        ofVertex(hist[i].x, hist[i].y);
    }
    if(counter > 0) ofVertex(loc.x, loc.y);
    ofEndShape(false);
}

//void Particle::drawArrowHead(ofPoint v, ofPoint loc, float scale){
//    ofPushMatrix();
//    float arrowsize = 5.0f;
//    ofTranslate(loc.x, loc.y, 0);
//    float rotate = atan2(v.y, v.x);
//    ofRotate(ofRadToDeg(rotate), 0, 0, 1);
//    
//    float len = mag(v) * scale;
//    arrowsize = ofMap(len, 0.f, 10.f, 0.f, 1.f, false) * arrowsize;
//    
//    ofLine(0, 0, len-arrowsize, 0);
//    
//    ofBeginShape();
//    ofVertex(len, 0);
//    ofVertex(len-arrowsize, arrowsize/2);
//    ofVertex(len-arrowsize, -arrowsize/2);
//    ofEndShape(true);
//    
//    ofPopMatrix();
//}

