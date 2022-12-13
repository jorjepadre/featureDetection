#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    faceFinder.setup("haarcascade_frontalface_default.xml");
    eyeFinder.setup("haarcascade_eye.xml");
    
    grab.setVerbose(true);
    grab.initGrabber(xVal, yVal);
}

//--------------------------------------------------------------
void ofApp::update(){
    grab.update();
    
    if (grab.isFrameNew()) {
        img.setFromPixels(grab.getPixels());
        faceFinder.findHaarObjects(img);
        
        for (int i = 0; i < faceFinder.blobs.size(); ++i) {
            ofRectangle cur = faceFinder.blobs[i].boundingRect;
            origin.x = cur.x;
            origin.y = cur.y;
            faceImg.cropFrom(img, cur.x, cur.y, cur.width, cur.height);
            eyeFinder.findHaarObjects(faceImg);
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    img.draw(0, 0);
    ofNoFill();
    for (int i = 0; i < eyeFinder.blobs.size(); ++i) {
        ofRectangle cur = eyeFinder.blobs[i].boundingRect;
        ofDrawRectangle(cur.x + origin.x, cur.y + origin.y, cur.width, cur.height);
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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
