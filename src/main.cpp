#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <cv.h>
#include <highgui.h>

IplImage *repetitions(IplImage *source) {
  int width    = source->width;
  int height   = source->height;
  int depth    = source->depth;
  int channels = source->nChannels;
  int step     = source->widthStep;

  CvSize dimensions = cvSize(width, height);
  IplImage *destination = cvCreateImage(dimensions, depth, channels);

  uchar *input  = (uchar *)source->imageData;
  uchar *output = (uchar *)destination->imageData;

  int index, offset, h, w, c, i;
  uchar pixel, current;

  for (h = 0; h < height;   h++)
  for (w = 0; w < width;    w++)
  for (c = 0; c < channels; c++) {

    index = h * step + w * channels + c;
    pixel = input[index];

    for (i = 0; i < width; i++) {
      current = input[h * step + i * channels + c];
      if (current == pixel) {
        offset = abs(w - i);
        output[h * step + offset * channels + c] = 255;
      }
    }

  }

  return destination;
}

int main(int argc, char *argv[])
{
  IplImage* img = 0;
  int height,width,step,channels;
  uchar *data;
  int i,j,k;

  if(argc<2){
    printf("Usage: main <image-file-name>\n\7");
    exit(0);
  }

  // load an image
  img=cvLoadImage(argv[1]);
  if(!img){
    printf("Could not load image file: %s\n",argv[1]);
    exit(0);
  }

  IplImage *rep = repetitions(img);

  // create the windows
  cvNamedWindow("Original",    CV_WINDOW_AUTOSIZE);
  cvNamedWindow("Repetitions", CV_WINDOW_AUTOSIZE);

  // position
  cvMoveWindow("Original",    100, 100);
  cvMoveWindow("Repetitions", 700, 100);

  // show the images
  cvShowImage("Original",    img);
  cvShowImage("Repetitions", rep);

  // wait for a key
  cvWaitKey(0);

  // release the images
  cvReleaseImage(&img);
  cvReleaseImage(&rep);
  return 0;
}
