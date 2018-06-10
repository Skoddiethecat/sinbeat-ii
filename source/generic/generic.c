#include <stdio.h>
#include <math.h>
#include <stdint.h>

const int iSampleRate = 44100;

uint16_t sinco(int iCarrier, int iSampleRate, unsigned long ulIndex){return (sin(iCarrier * (2 * M_PI) * ulIndex / iSampleRate) * 32767) + 32768;}

unsigned long phaseindex(unsigned long t){return t;}

void main(){
    unsigned long t;
	
	int iCarrier = 440;
	int iMBytes = 16;
    uint16_t iOut = 0;
	
    for(t=0; t<iMBytes*512*512; t++){
        iOut = sinco(iCarrier, iSampleRate, phaseindex(t));
		putchar(iOut & 0xff);
        putchar ((iOut >> 8) & 0xff);
    }
	t = 0;
	
}