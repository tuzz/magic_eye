#include "subtraction.hpp"

IplImage *subtraction(IplImage *image, int offset) {
  int width    = image->width;
  int height   = image->height;
  int depth    = image->depth;
  int step     = image->widthStep;
  int channels = image->nChannels;

  CvSize dimensions = cvSize(width, height);
  IplImage *ret = cvCreateImage(dimensions, depth, channels);

  uchar *input = (uchar *)image->imageData;
  uchar *output = (uchar *)ret->imageData;

  int h, w, c;
  uchar x1, x2;

  for (h = 0; h < height; h++)
  for (w = 0; w + offset < width; w++)
  for (c = 0; c < channels; c++) {
    x1 = input[h * step + w * channels + c];
    x2 = input[h * step + (w + offset) * channels + c];

    output[h * step + (w + offset / 2) * channels + c] = abs(x1 - x2);
  }

  return ret;
}
