#include <stdio.h>
#include <math.h>
#include <stdint.h>

const int iSampleRate = 44100;

uint16_t sinco(int iCarrier, int iSampleRate, int iScale, unsigned long ulIndex){return (sin(iCarrier * (2 * M_PI) * ulIndex / iSampleRate) * ((iScale/2)+1)) + (iScale/2);}

unsigned long phaseindex(unsigned long t){return sinco(42, iSampleRate, 55000, (t>>21)+1|(t&t>>16))|(((t>>4&t%11025)*16)>>2)^sinco(((t%11025==0)?(84):(164)), iSampleRate, 65536, ((t%2==1)?((t/2)&(31&(t/2)>>9)*17):(65536/8))/16)-1;}

void main(){
    unsigned long t;
	
	int iCarrier = 21;
    uint16_t iOut = 0;
	
    for(t=0;;t++){
        iOut = sinco(iCarrier, iSampleRate, 65536, (phaseindex(t)));
		putchar(iOut & 0xff);
        putchar ((iOut >> 8) & 0xff);
    }
	
}