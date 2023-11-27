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

    Stag(int libraryHD = 15, int errorCorrection = 7);
	void detectMarkers(cv::Mat inImage);
	void logResults(string path = "");
};


#endif