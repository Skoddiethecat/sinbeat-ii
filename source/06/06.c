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
	return sinco(50, iSampleRate, i, ((t>>11)|(((-t&4410)*(255&t*(t&(t>>13)))>>11)+(127&t|(234&t>>7&t>>4)>>(3&t>>17))/2))/2);}

void main(){
    unsigned long t;
	
	int iCarrier = 25;
    uint16_t iOut = 0;
	
    for(t=0;;t++){
        iOut = sinco(iCarrier, iSampleRate, 65534, phaseindex(t));
		putchar(iOut & 0xff);
        putchar ((iOut >> 8) & 0xff);
    }
	
}