#ifndef STAG_H
#define STAG_H

#include "EDInterface.h"
#include "QuadDetector.h"
#include "Drawer.h"
#include "Marker.h"
#include "Decoder.h"
#include "PoseRefiner.h"

class Stag
{

	int errorCorrection;
	EDInterface edInterface;
	QuadDetector quadDetector;
	Drawer drawer;
	Decoder decoder;
	PoseRefiner poseRefiner;

	vector<cv::Mat> codeLocs;
	vector<cv::Mat> blackLocs;
	vector<cv::Mat> whiteLocs;

	cv::Mat image;

	// take readings from 48 code locations, 12 black border locations, and 12 white border locations
	// thresholds and converts to binary code
	Codeword readCode(const Quad &q);
	void fillCodeLocations();
	cv::Mat createMatFromPolarCoords(double radius, double radians, double circleRadius);

public:
    vector<Marker> markers;
    vector<Quad> falseCandidates;

	/**
	 * Initializes STag
	 * @param libraryHD The library HD that is used. Possible values are [11,&nbsp;13,&nbsp;15,&nbsp;17,&nbsp;19,&nbsp;21,&nbsp;23].
	 * @param errorCorrection The amount of error correction that is going to be used.
	 *  Value needs to be in range 0&nbsp;\<=&nbsp;errorCorrection&nbsp;\<=&nbsp;(HD-1)/2.\n
	 *  If set to -1, the max possible value for the given library HD
	 *  is used.
	 */
	Stag(int libraryHD, int errorCorrection = -1);
	/**
	 * Detects markers in given image.
	 * @param inImage OpenCV Matrix of input image.
	 */
	void detectMarkers(cv::Mat inImage);
	/**
	 * Logs results to path (creates images for every detection step).
	 * @param path Path where the images are going to be created. Directory must exist, otherwise images cannot be saved.
	 */
	void logResults(string path = "");
};


#endif