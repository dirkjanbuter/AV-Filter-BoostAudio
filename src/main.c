#include "main.h"

#define NUMFRAMES 1024

int _initonce = 1;

double max[NUMFRAMES];


int filtercreate(int fps)
{
  	int i;
  	for(i=0; i<NUMFRAMES; i++)
	{
		max[i] = 0.0;
	} 
}


int filtervideo(unsigned char *buffer, int w, int h, unsigned int color, char *text, int64_t framecount)
{
    return TRUE;
}

int filteraudio(float *frame, int64_t framecount, float elapsed)
{
	int i = 0;
	double maxmax = 0.0;
	double val = 0.0;

	max[framecount%NUMFRAMES] = 0;
	for(i=0; i < 2048; i++)
	{
		val = (double)frame[i];
		if( val < 0 ) 
			val = -val; /* ABS */
		if( val > max[framecount%NUMFRAMES] )
		{
			max[framecount%NUMFRAMES] = val;
		}
	}
	
	if(framecount <= NUMFRAMES)
	{
		maxmax = 1.0;
	}
	else
	{	
		for(i=0; i < NUMFRAMES && i < framecount; i++)
		{
			if( max[i] > maxmax )
			{
				maxmax = max[i];
			}
		}
	}
	
	if(maxmax < 0.01)
		maxmax = 0.2;
	if(maxmax > 0.1)
		maxmax = 0.1;


	for(i=0; i<2048; i++)
	{
		val = (double)frame[i];
		val = val * 1.0 / maxmax;
		frame[i] = (float)val;		
	}

	return TRUE;
}
