#include "ofMain.h"
#include "sndfile.hh"

#ifndef waveHandler
#define waveHandler
#pragma once

class ofxWaveHandler {
	public :
		ofxWaveHandler(ofSoundStream* soundStream=NULL, int width=0, int height=0);
		~ofxWaveHandler() {free(recBuffer);};

		void addSamples(float* input, int numSamples);
		int clearBuffer();
		void drawWaveBuffer(float xPos=0, float yPos=0);
		void updateWaveBuffer(unsigned int startSmpl=0, int length=0);
		int getBufferLengthSmpls();
		float getBufferLengthSec();
		int loadBuffer(string fileName, unsigned int startSmpl=0);
		int saveBuffer(string fileName, int audioFormat= SF_FORMAT_WAV|SF_FORMAT_PCM_16, unsigned int startSmpl=0, unsigned int endSmpl=0);
		
			
	private:
		ofSoundStream*	soundStream;
		float*			recBuffer;
		int				recPointer;
		bool			isBlocked;
		
		ofFbo			waveForm;
		int				waveFormWidth;
		int				waveFormHeight;
};

#endif