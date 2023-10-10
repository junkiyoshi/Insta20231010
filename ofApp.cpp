#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(25);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetLineWidth(2);
	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();
	ofRotateX(90);
	ofRotateZ(ofGetFrameNum() * 0.72);

	auto radius = 300;

	for (int z = -240; z <= 240; z += 60) {

		for (auto deg = 0; deg < 360; deg += 6) {

			auto location = glm::vec3(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD), z);

			ofPushMatrix();
			ofTranslate(location);
			ofRotateZ(deg);

			auto rotate_deg = ofMap(ofNoise(glm::vec4(location.x * 0.0025, location.y * 0.0025, location.z, ofGetFrameNum() * 0.02)), 0, 1, -360, 360);
			ofRotateY(rotate_deg);

			ofFill();
			ofSetColor(0);
			ofDrawBox(30);

			ofNoFill();
			ofSetColor(255);
			ofDrawBox(30);

			ofPopMatrix();
		}
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {
	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}