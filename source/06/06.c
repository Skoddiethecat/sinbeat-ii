#include <stdio.h>
#include <math.h>
#include <stdint.h>

const int iSampleRate = 44100;

uint16_t sinco(int iCarrier, int iSampleRate, int iScale, unsigned long ulIndex){return (sin(iCarrier * (2 * M_PI) * ulIndex / iSampleRate) * ((iScale/2)+1)) + (iScale/2);}

unsigned long phaseindex(unsigned long t){
	unsigned long i;
	i = 30000;
	(t%8820==0)?i = i + 1:0;
	(i = 60000)?i = 30000:0;
	return sinco(49, iSampleRate, i, (71&(t*t%4095)^(t%511)|(t&t%255)^(t&t%512)|(t^t%1023)|(t|t%2213)/16));}

void main(){
    unsigned long t;
	
	int iCarrier = 13;
    uint16_t iOut = 0;
	
    for(t=0;;t++){
        iOut = sinco(iCarrier, iSampleRate, 65534, phaseindex(t));
		putchar(iOut & 0xff);
        putchar ((iOut >> 8) & 0xff);
    }
	
}