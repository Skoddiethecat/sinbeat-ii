#include <stdio.h>
#include <math.h>
#include <stdint.h>

const int iSampleRate = 44100;
const int iCarrier = 17;

uint16_t sinco(int iCarrier, int iSampleRate, int iScale, unsigned long ulIndex){return (sin(iCarrier * (2 * M_PI) * ulIndex / iSampleRate) * ((iScale/2)+1)) + (iScale/2);}

unsigned long phaseindex6(unsigned long t){return sinco(iCarrier*64, iSampleRate, 5536, t>>13);}

unsigned long phaseindex5(unsigned long t){return sinco(iCarrier*32, iSampleRate, 15536, ((t<(10*1024*1024))?t>>11:phaseindex6(t)));}

unsigned long phaseindex4(unsigned long t){return sinco(iCarrier*16, iSampleRate, 25536, ((t<(8*1024*1024))?t>>7:phaseindex5(t)));}

unsigned long phaseindex3(unsigned long t){return sinco(iCarrier*8, iSampleRate, 35536, ((t<(6*1024*1024))?t>>5:phaseindex4(t)));}

unsigned long phaseindex2(unsigned long t){return sinco(iCarrier*4, iSampleRate, 45536, ((t<(4*1024*1024))?t>>3:phaseindex3(t)));}

unsigned long phaseindex(unsigned long t){return sinco(iCarrier*2, iSampleRate, 55536, ((t<(2*1024*1024))?t>>2:phaseindex2(t)));}

void main(){
    unsigned long t;
	
    uint16_t iOut = 0;
	
    for(t=0;;t++){
        iOut = sinco(iCarrier, iSampleRate, 65536, phaseindex(t));
		putchar(iOut & 0xff);
        putchar ((iOut >> 8) & 0xff);
    }
	
}