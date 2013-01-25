#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <cv.h>
#include <highgui.h>

#include "offset.hpp"

int main(int argc, char **argv) {
  IplImage *image = cvLoadImage("foo.jpg");
  int o = offset(image);

  uchar *data = (uchar *)image->imageData;

  int width = image->width;
  int height = image->height;
  int step = image->widthStep;
  int channels = image->nChannels;

  for (int h = 0; h < height;   h++)
  for (int w = 0; w < width;    w++)
  for (int c = 0; c < channels; c++) {
    if (w != o) {
      continue;
    }

    data[h * step + w * channels + c] = 0;
  }

  cvNamedWindow("Window", CV_WINDOW_AUTOSIZE);
  cvShowImage("Window", image);
  cvWaitKey(0);
  return 0;
}
