#include <stdio.h>
#include <math.h>
#include <stdint.h>

const int iSampleRate = 44100;

uint16_t sinco(int iCarrier, int iSampleRate, unsigned long ulIndex){return (sin(iCarrier * (2 * M_PI) * ulIndex / iSampleRate) * 32767) + 32768;}

unsigned long phaseindex(unsigned long t){return sinco(((t%22==0)?200:100), iSampleRate, ((t/4)>>7)&((t&t>>9)/2)&(t*2<<4))|((t>(4*512*512))?t>>7:0);}

void main(){
    unsigned long t;
	
	int iCarrier = 50;
    uint16_t iOut = 0;
	
    for(t=0;; t++){
        iOut = sinco(iCarrier, iSampleRate, phaseindex(t));
		putchar(iOut & 0xff);
        putchar ((iOut >> 8) & 0xff);
    }
	
}