//
//  eyeFinder.hpp
//  featureDetection
//
//  Created by Zhanaidar on 13/12/2022.
//

#ifndef eyeFinder_hpp
#define eyeFinder_hpp

#include <stdio.h>

#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"

class eyeFinder : public ofBaseApp {
public:
    void setup();
    void update();
    void draw();
    
    ofxCvHaarFinder faceFinder, eyeFinder;
    ofVideoGrabber grab;
    
    ofImage img, faceImg;
    ofVec2f origin;
    
    int xVal = 640, yVal = 480;
};


#endif /* eyeFinder_hpp */
