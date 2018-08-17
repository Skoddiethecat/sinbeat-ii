#include <stdio.h>
#include <math.h>
#include <stdint.h>

const int iSampleRate = 44100;

uint16_t sinco(int iCarrier, int iSampleRate, int iScale, unsigned long ulIndex){return (sin(iCarrier * (2 * M_PI) * ulIndex / iSampleRate) * ((iScale/2)+1)) + (iScale/2);}

unsigned long ampindex(unsigned long t){return ((t>>1|(t>>(4-(1^5&(t>>13))))|(10584+(t%3528)?((t*11)%4096):t/2)/3)-7);}

unsigned long phaseindex(unsigned long t){return sinco(50, iSampleRate, 44100, t);}

void main(){
    unsigned long t;
	
	int iCarrier = 25;
    uint16_t iOut = 0;
	
    for(t=0;;t++){
        iOut = sinco(iCarrier, iSampleRate, ampindex(t), phaseindex(t));
		putchar(iOut & 0xff);
        putchar ((iOut >> 8) & 0xff);
    }
	
}