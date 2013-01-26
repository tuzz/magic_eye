#include <cv.h>
#include <highgui.h>

#include "offset.hpp"
#include "subtraction.hpp"

IplImage *solve(IplImage *magicEye) {
  return subtraction(magicEye, offset(magicEye));
}

int main(int argc, char **argv) {
  if (argc < 2){
    printf("Usage: magic_eye <file-name>\n\n");
    exit(0);
  }

  IplImage *magicEye = cvLoadImage(argv[1]);
  if (!magicEye){
    printf("Could not load magic eye: %s\n", argv[1]);
    exit(0);
  }

  IplImage *solution = solve(magicEye);

  cvNamedWindow("Magic Eye", CV_WINDOW_AUTOSIZE);
  cvNamedWindow("Solution",  CV_WINDOW_AUTOSIZE);

  cvMoveWindow("Magic Eye", 100, 100);
  cvMoveWindow("Solution",  magicEye->width + 200, 100);

  cvShowImage("Magic Eye", magicEye);
  cvShowImage("Solution",  solution);

  cvWaitKey(0);

  return 0;
}
