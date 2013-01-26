#include <cv.h>
#include <highgui.h>

#include "offset.hpp"
#include "subtraction.hpp"

IplImage *solve(IplImage *magicEye) {
  return subtraction(magicEye, offset(magicEye));
}

int main(int argc, char **argv) {
  IplImage *magicEye = cvLoadImage("foo.jpg");
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
