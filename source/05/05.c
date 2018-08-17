#include <stdio.h>
#include <math.h>
#include <stdint.h>

const int iSampleRate = 44100;

uint16_t sinco(int iCarrier, int iSampleRate, int iScale, unsigned long ulIndex){return (sin(iCarrier * (2 * M_PI) * ulIndex / iSampleRate) * ((iScale/2)+1)) + (iScale/2);}

unsigned long phaseindex4drums(unsigned long t){
	int iDrums;
	if (t<(2*1024*1024)){iDrums = 1;}
	else if (t<(4*1024*1024)){iDrums = 7;}
	else if (t<(6*1024*1024)){iDrums = 5;}
	else if (t<(8*1024*1024)){iDrums = 9;}
	else if (t<(10*1024*1024)){iDrums = 11;}
	else if (t<(12*1024*1024)){iDrums = 3;}
	else if (t<(14*1024*1024)){iDrums = 2;}
	else {iDrums = 10;}
	
	
	
	return t>>iDrums;
}

unsigned long phaseindex(unsigned long t){return sinco(50, iSampleRate, 65532, phaseindex4drums(t)|(t>>(4-(1^5&(t>>13))))|(10584+(t%3528)?((t*11)%4096):t/2)/1);}

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