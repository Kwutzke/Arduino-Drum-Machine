//
// Created by Kilian Wutzke on 27.06.17.
//

#include <iostream>
#include "Sample.h"
#include <boost/thread.hpp>

Sample::Sample(const char* samplePath) : playArray(64, 0) {
    this->sampleFile = Mix_LoadWAV(samplePath);
    if (this->sampleFile == NULL) {
        fprintf(stderr, "Unable to load wave file: %s\n", samplePath);
    }
}

void Sample::playSample(int currentBeat) {
    if(this->playArray.at((unsigned long) currentBeat) == 1) {
        Mix_PlayChannel(-1, this->sampleFile, 0);
        cout << "play" << endl;
    }
}

void Sample::preFillKickDrumArray() {
    for (int i = 0; i < 64; ++i) {
        if(i%16 == 0)
            this->playArray.at((unsigned long) i) = 1;
    }
}

void Sample::preFillClapArray() {
    for (int i = 0; i < 64; ++i) {
        if(i%32 == 0)
            this->playArray.at((unsigned long) i + 16) = 1;
    }
}

void Sample::preFillHighHatArray() {
    for (int i = 0; i < 64; ++i) {
        if(i%16 == 0)
            if(i != 64)
                this->playArray.at((unsigned long) i+8) = 1;
    }
}


