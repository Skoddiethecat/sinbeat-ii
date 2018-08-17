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
	return sinco(53, iSampleRate, i, (t%127)|(((t|t%44100)>>32)^((t%251)^(t%509)|(t%1021)|(t%2213)/16)));}

void main(){
    unsigned long t;
	
	int iCarrier = 11;
    uint16_t iOut = 0;
	
    for(t=0;;t++){
        iOut = sinco(iCarrier, iSampleRate, 65534, phaseindex(t));
		putchar(iOut & 0xff);
        putchar ((iOut >> 8) & 0xff);
    }
	
}