//Video Analysis Techniques for Surveillance (VATS)
//class description
/**
 * \class BasicBlob
 * \brief Class to describe a basic blob
 *
 * 
 */

#ifndef BASICBLOB_H_INCLUDE
#define BASICBLOB_H_INCLUDE

#include "opencv2/opencv.hpp"
using namespace cv; //avoid using 'cv' to declare OpenCV functions and variables (cv::Mat or Mat)


// Maximun number of char in the blob's format
const int MAX_FORMAT = 1024;

/// Type of labels for blobs
typedef enum {	
	UNKNOWN=0, 
	PERSON=1, 
	GROUP=2, 
	CAR=3, 
	OBJECT=4
} CLASS;

struct cvBlob {
	int     ID;  /* blob ID        */
	int   x, y;  /* blob position  */
	int   w, h;  /* blob sizes     */	
	CLASS label; /* type of blob   */
	char format[MAX_FORMAT];
};

inline cvBlob initBlob(int id, int x, int y, int w, int h)
{
	cvBlob B = { id,x,y,w,h,UNKNOWN};
	return B;
}
#endif
