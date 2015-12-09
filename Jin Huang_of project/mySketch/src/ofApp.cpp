#include "ofApp.h"

#include "Particle.hpp"

Particle *particles, *what;
bool saving = false;


float mag(ofPoint in){
    float retf = sqrt(in.x * in.x + in.y * in.y);
    return retf;
}

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(600);
    ofEnableSmoothing();
    ofEnableAlphaBlending();
    
    particles = new Particle[100];
    for(int i = 0; i < 100; i++){
        particles[i] = Particle(ofPoint(100, ofGetHeight()-100));
    }
    
    what = new Particle[1000];
    for(int i = 0; i < 1000; i++){
        what[i] = Particle(ofPoint(ofGetWidth(), 100));
    }
    
    ofSetBackgroundAuto(true);
    period = 50;
    
    //ease effect setup//
    easing = 0.01;
    pointX = 0;
    pointY = 0;
    targetX = ofGetWidth();
    targetY = ofGetHeight();
}

//--------------------------------------------------------------
void ofApp::update(){
    
    time = ofGetElapsedTimef();
    cose = cos(time) * amplitude;
    sine = sin(time) * amplitude;
    
    centerX = ofGetWidth()/2;
    centerY = ofGetHeight()/2;
    
    diameter = ofMap(sine, -amplitude, amplitude, 10, 200); //map sine to the value of (10-200);
    
    
    //ease
    pointX += (targetX - pointX) * easing;
    pointY += (targetY - pointY) * easing;
    
   }

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0, 0, 0);
    ofSetColor(66, 131, 252);
//    ofSetColor(255, 255, 255);
    for(int i = 0; i < 100; i++){
        particles[i].update();
        particles[i].draw();
    }
    
    ofSetColor(241, 152, 178);
//    ofSetColor(255, 255, 255);
    for(int i = 0; i < 1000; i++){
        what[i].update();
        what[i].draw();
    }
    
    for(int i = 0; i < 1000; i++){
        if (particles[i].loc == what[i].loc){
            
        }
        
    }
    
    //attracter//
//    ofBackground(15,15,15);
    int n = 10000;
    int i;
    //
    //    a = 1.641;
    //    b= 1.902;
    //    c= 0.316;
    //    d= 1.525;
    //
    //    a = 0 + sin(ofGetElapsedTimef());
    //    b = -2.3;
    //    c=2.4;
    //    d= -2.15;
    
    ofSetColor(255);
    
    
    a = -1.7 + sin(ofGetElapsedTimef());
    b = 1.3+sin(ofGetElapsedTimef());
    c = -2.0+cos(ofGetElapsedTimef());
    d = -1.2+cos(ofGetElapsedTimef());
    
    
    x0=y0= x1=y1= 0;
    
    ofTranslate(ofGetWidth()/2,ofGetHeight()/2);
    
    ofScale(800,800,800);
    
    
    for (int i =0; i<n; i++){
        
        x1 = sin(a *y0) - cos(b * x0);
        y1 = sin(c * x0) - cos(d*y0);
        
        ofLine(x1,y1,x1+0.001,y1+0.001);
        
        x0 = x1;
        y0 = y1;
    }
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
