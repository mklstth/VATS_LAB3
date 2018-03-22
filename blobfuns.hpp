//Video Analysis Techniques for Surveillance (VATS)

#ifndef BLOBFUNS_H_INCLUDE
#define BLOBFUNS_H_INCLUDE

#include "basicblob.hpp"

//blob extraction functions (included in 'blobextract.cpp')
int extractBlobs(Mat fgmask, std::vector<cvBlob> &bloblist);
Mat paintBlobImage(Mat frame, std::vector<cvBlob> &bloblist);

//blob classification functions (included in 'blobclassify.cpp')
int classifyBlobs(Mat frame, Mat fgmask, std::vector<cvBlob> &bloblist);
Mat paintBlobClasses(Mat frame, std::vector<cvBlob> &bloblist);	

#endif