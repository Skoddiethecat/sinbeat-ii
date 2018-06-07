#include <stdio.h>
#include <math.h>
#include <stdint.h>

const int iSampleRate = 48000; //specify sample rate here

uint8_t sinco(int iCarrier, int iSampleRate, unsigned long ulIndex){return (sin(iCarrier * (2 * M_PI) * ulIndex / iSampleRate) * 127) + 128;}

unsigned long phaseindex1(unsigned long t){return t;}

void main(){
    unsigned long t;
	
	int iCarrier = 64;
	int iMBytes = 16;
	
    for(t=0; t<iMBytes*1024*1024; t++){
        putchar(sinco(iCarrier, iSampleRate, phaseindex1(t)));
    }
	t = 0;
	
}
