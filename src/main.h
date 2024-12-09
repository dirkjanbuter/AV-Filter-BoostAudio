#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>

#define TRUE  1
#define FALSE 0


extern int filtercreate(int fps);
extern void filterdestroy();
extern int filtervideo(unsigned char *buffer, int w, int h, unsigned int color, char *text, int64_t framecount);
extern int filteraudio(float *frame, int64_t framecount, float elapsed);
