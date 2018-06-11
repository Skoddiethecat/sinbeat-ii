#include <stdio.h>
#include <math.h>
#include <stdint.h>

const int iSampleRate = 44100;

uint16_t sinco(int iCarrier, int iSampleRate, int iScale, unsigned long ulIndex){return (sin(iCarrier * (2 * M_PI) * ulIndex / iSampleRate) * ((iScale/2)+1)) + (iScale/2);}

unsigned long phaseindex(unsigned long t){return sinco(25, iSampleRate, 46000,((441&t>>10))|((t>>63)|(((9-(1^4&(t>>11)))|(t&t%((t%1024==0)?1023:1024))-256|(t&(t-16)>>23)))))|(((t>(16*1024*1024))?(t>>5):(t>>3))/2);}

void main(){
    unsigned long t;
	
	int iCarrier = 50;
    uint16_t iOut = 0;
	
    for(t=0;;t++){
        iOut = sinco(iCarrier, iSampleRate, 65536, phaseindex(t));
		putchar(iOut & 0xff);
        putchar ((iOut >> 8) & 0xff);
    }
	
}