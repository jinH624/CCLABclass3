#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    void seed1(float dotSize, float angle, float x, float y);
    void seed2(float dotSize, float angle, float x, float y);
    
    float dotSize, angleOffsetA, angleOffsetB;
    
    float cose;
    float sine;
    float time;
    float amplitude;
    float period;
    
    float centerX;
    float centerY;
    
    
    //scale effect
    float diameter;
    
    //ease effect
    
    float pointX;
    float pointY;
    
    float targetX;
    float targetY;
    
    float easing;
    
    //attractor //
    float a,b,c,d;
    float x0, y0, x1, y1;
		
};
