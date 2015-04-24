//
//  testScene.cpp
//  FireArrowEngine
//
//  Created by Simon Nilsson on 25/03/15.
//  Copyright (c) 2015 Axenu. All rights reserved.
//

#include "testScene.h"
//
//std::string cftoc(CFStringRef r) {
//    const CFIndex kCStringSize = 128;
//    char temporaryCString[kCStringSize];
//    bzero(temporaryCString,kCStringSize);
//    CFStringGetCString(r, temporaryCString, kCStringSize, kCFStringEncodingUTF8);
//    std::string *bar = new std::string(temporaryCString);
//    return *bar;
//}
//
//void myCallBack(CFNotificationCenterRef center, void *observer, CFStringRef name, const void *object, CFDictionaryRef userInfo) {
//    std::string album = cftoc((CFStringRef)CFDictionaryGetValue(userInfo, CFSTR("Album")));
//    std::string artist = cftoc((CFStringRef)CFDictionaryGetValue(userInfo, CFSTR("Artist")));
//    std::string track = cftoc((CFStringRef)CFDictionaryGetValue(userInfo, CFSTR("Name")));
////    std::string durationS = cftoc((CFStringRef)CFDictionaryGetValue(userInfo, CFSTR("Duration")));
////    std::string currentTimeS = cftoc((CFStringRef)CFDictionaryGetValue(userInfo, CFSTR("Playback Position")));
//    std::string trackID = cftoc((CFStringRef)CFDictionaryGetValue(userInfo, CFSTR("Track ID")));
//    trackID.erase(0, 14);
//    std::cout << trackID << std::endl;
//}

void testScene::init() {
//    FAMaterial *m = new FAMaterial();
//    m->setColor(glm::vec4(1,0,0,1));
//    m->setGlobalLight();
//    m->init();
//    CFNotificationCenterRef distCenter;
//    CFStringRef evtName = CFSTR("com.spotify.client.PlaybackStateChanged");
//    distCenter = CFNotificationCenterGetDistributedCenter();
//    CFNotificationCenterAddObserver(distCenter, NULL, &myCallBack, evtName, NULL, CFNotificationSuspensionBehaviorDeliverImmediately);
//    CFRunLoopRun();
//    
//    albumArt = new FATexturedPlane2D();
//    albumArt->setShader(shaders->getShader("TexturedPlane2D"));
//    albumArt->setScale(1);
//    albumArt->update(0);
//    albumArt->setTexture(FATexture::createTexture("/Users/Axenu/Documents/Geektool/Spotify/DefaultArtwork/DefaultArtwork.tiff"));
//    addHUDElement(albumArt);
}

//void testScene::render() {
//    
//}

void testScene::renderShadow() {
    
}

void testScene::update(float dt) {
    
}

void testScene::buttonPressed(int index) {
    
}

void testScene::getKeyInput(int key, int action) {
    
}

void testScene::mouseKeyInput(int button, int action) {
    
}

void testScene::cursorPosition(double x, double y) {
    
}