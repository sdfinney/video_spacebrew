#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	string host = Spacebrew::SPACEBREW_CLOUD; // "localhost";
    string name = "video";
    string description = "please work";
    
   spacebrew.addPublish("button", Spacebrew::TYPE_BOOLEAN);
    spacebrew.addSubscribe("backgroundOn", Spacebrew::TYPE_BOOLEAN); //"boolean" ); // just typing "boolean" also works
    spacebrew.connect( host, name, description );
    
    //Spacebrew::addListener(this, spacebrew);
    
    ofBackground(255,255,255);
	frameByframe = false;
    

    
	angerman.loadMovie("movies/anger.mov");
	angerman.play();
}

//--------------------------------------------------------------
void testApp::update(){
    angerman.update();
}

//--------------------------------------------------------------
void testApp::draw(){
    
    angerman.draw(20,20);



}

//--------------------------------------------------------------
void testApp::onMessage( Spacebrew::Message & m ){
    if ( m.name == "backgroundOn" ){
        frameByframe = m.valueBoolean();
    }
}


//--------------------------------------------------------------
void testApp::keyPressed  (int key){
    switch(key){
        case 'f':
            frameByframe=true;
            angerman.setPaused(frameByframe);
            spacebrew.sendBoolean("button", true);



    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){


}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){


}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){


}


//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){


}

//--------------------------------------------------------------

