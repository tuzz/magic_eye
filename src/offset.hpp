#include <math.h>
#include <cv.h>

#define MIN_FRACTION 16
#define MAX_FRACTION 4
#define LINES 16

int offset(IplImage *image);

int offsetDiff(int offset, IplImage *image);
int pixelDiff(uchar *a, uchar *b, int channels);
