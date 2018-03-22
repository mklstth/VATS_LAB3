/* Video Analysis Techniques for Surveillance (VATS)
 *
 *	Sample Opencv project for lab assignment 2 "Blob analysis"
 * 
 *  INSTRUCTIONS
 *  1) To compile this project, right click on the project name (right or left window) and "build"
 *  2) To run this project, please click on the 'green' play button
 *
 * Author: Juan C. SanMiguel (juancarlos.sanmiguel@uam.es)
 */

//system libraries C/C++
#include <stdio.h>
#include <iostream>
#include <sstream>

//opencv libraries
#include <opencv2/opencv.hpp>
#include <opencv2/video/background_segm.hpp>

//include for blob-related functions
#include "blobfuns.hpp" 

//namespaces
using namespace cv; //avoid using 'cv' to declare OpenCV functions and variables (cv::Mat or Mat)

//main function
int main(int argc, char ** argv) 
{
	Mat frame; // current Frame
	Mat fgmask; // foreground mask
	std::vector<cvBlob> bloblist; // list for blobs
	
	double t = 0; //variable for execution time	

	std::string inputvideo = "../videos/ETRI_od_A.avi"; //path for the videofile to process
	
	//alternatively, the videofile can be passed via arguments of the executable
	if (argc == 2){
		inputvideo = argv[1];
	}	
	
	VideoCapture cap;//reader to grab videoframes

	//MOG2 approach
	//Ptr<BackgroundSubtractor> pMOG2 = cv::createBackgroundSubtractorMOG2(); //uncomment this line for opencv 3.1
	Ptr<BackgroundSubtractor> pMOG2 = new BackgroundSubtractorMOG2(); //uncomment this line for opencv 2.4

	//open the videofile to check if it exists
	cap.open(inputvideo);
	if (!cap.isOpened()) {
		std::cout << "Could not open video file " << inputvideo << std::endl;
		return -1;
	}
	cap >> frame; //get first video frame

	//main loop
	for (;;) {

		//get frame & check if we achieved the end of the file (e.g. frame.data is empty)
		cap >> frame;
		if (!frame.data)
			break;
		
		//Time measurement
		t = (double)getTickCount();		

		// update the background model (compute fgmask)
		//pMOG2->apply(frame, fgmask); //uncomment this line for opencv 3.1
		pMOG2->operator()(frame, fgmask); //uncomment this line for opencv 2.4
				
		// Extract the blobs in fgmask
		extractBlobs(fgmask, bloblist);		
		std::cout << "Num blobs extracted=" << bloblist.size() << std::endl;

		// Clasify the blobs in fgmask
		classifyBlobs(frame, fgmask, bloblist);		
		
		//get the frame number and write it on the current frame
		std::stringstream ss;
		//ss << cap.get(cv::CAP_PROP_POS_FRAMES); //uncomment this line for opencv 3.1
		ss << cap.get(CV_CAP_PROP_POS_FRAMES); //uncomment this line for opencv 2.4

		putText(frame, ss.str().c_str(), cv::Point(15, 15),FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(0, 0, 255)); //text in red
		
		imshow("frame", frame);
		imshow("fgmask MOG2", fgmask);
		
		//Pain the blob results
		//imshow("blob extract", paintBlobImage(frame,bloblist));
		//imshow("blob classify", paintBlobClasses(frame,bloblist));

		//Time measurement
		t = (double)getTickCount() - t;
		printf("tdetection time = %gms\n", t*1000. / cv::getTickFrequency());

		//exit if ESC key is pressed
		if(waitKey(30) == 27) break;
	}

	//release all resource
	cap.release();
	destroyAllWindows();

	return 0;
}
