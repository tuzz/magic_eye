#include "offset.hpp"

int offset(IplImage *image) {
  int width = image->width;

  int current, best, min = -1;

  for (int i = width / MIN_OFFSET_FRACTION; i < width / MAX_OFFSET_FRACTION; i++) {
    current = offsetDiff(i, image);

    if (current < min || min == -1) {
      min = current;
      best = i;
    }
  }

  return best;
}

int offsetDiff(int offset, IplImage *image) {
  int total = 0;

  int width    = image->width;
  int height   = image->height;
  int channels = image->nChannels;
  int step     = image->widthStep;

  uchar *data = (uchar *)image->imageData;

  int h, w, c, x1, x2;

  for (h = 0; h < height;   h++)
  for (w = 0; w < width / 2;    w++)
  for (c = 0; c < channels; c++) {
    x1 = data[h * step + w * channels + c];
    x2 = data[h * step + (w + offset) * channels + c];

    total += abs(x1 - x2);
  }

  return total;
}

int pixelDiff(uchar *a, uchar *b, int channels) {
  int total = 0;

  for (int i = 0; i < channels; i++) {
    total += abs(a[i] - b[i]);
  }

  return total;
}
