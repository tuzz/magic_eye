#include <math.h>
#include <cv.h>

#define MIN_OFFSET_FRACTION 16
#define MAX_OFFSET_FRACTION 4

int offset(IplImage *image);

int offsetDiff(int offset, IplImage *image);
int pixelDiff(uchar *a, uchar *b, int channels);
