//Video Analysis Techniques for Surveillance (VATS)

#include "blobfuns.hpp"

/**
 *	Blob classificaion between the five available classes in 'BasicBlob.h' (see CLASS typedef). All the input arguments must be 
 *  initialized when using this function.
 *
 * \param frame Input image
 * \param fgmask Foreground/Background segmentation mask (1-channel binary image) 
 * \param bloblist List with found blobs
 *
 * \return Operation code (negative if not succesfull operation) 
 */
int classifyBlobs(Mat frame, Mat fgmask, std::vector<cvBlob> &bloblist)	
{
	//check input conditions and return -1 if any is not satisfied
	//...		

	//required variables for classification
	//...
	
	//classify each blob of the list
	for(int i = 0; i < bloblist.size(); i++) 
	{
		cvBlob blob = bloblist[i]; //get i-th blob
		//...
	}
	
	//destroy all resources
	//...
	
	//return OK code
	return 1;
}


/**
 *	Draws blobs (and its classes) with different color rectangles on the image 'frame'. All the input arguments must be 
 *  initialized when using this function.
 *
 * \param frame Input image 
 * \param bloblist List with found blobs
 *
 * \return Image containing the draw blobs. If no blobs have to be painted 
 *  or arguments are wrong, the function returns a copy of the original "frame". 
 */
Mat paintBlobClasses(Mat frame, std::vector<cvBlob> &bloblist)
{
	Mat blobImage;
	//check input conditions and return NULL if any is not satisfied
	//...		

	//required variables to paint
	//...

	//paint each blob of the list
	for(int i = 0; i < bloblist.size(); i++) 
	{
		cvBlob blob = bloblist[i]; //get ith blob
		//...
	}

	//destroy all resources (if required)
	//...
	
	//return the image to show
	return blobImage;
}