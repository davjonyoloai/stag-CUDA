#include "src/Stag.h"
#include <opencv2/imgcodecs.hpp>
#include <vector>
using cv::Mat;

int main() {
    // load image
    // this is the first change for test github
    cv::Mat image = cv::imread("../example.jpg");

	// set HD library
	int libraryHD = 21;

    auto corners = std::vector<std::vector<cv::Point2f>>();
    auto ids = std::vector<int>();
	auto rejectedImgPoints = std::vector<std::vector<cv::Point2f>>(); // optional, helpful for debugging

    // detect markers
    stag::detectMarkers(image, libraryHD, corners, ids, rejectedImgPoints);

	// draw and save results
	stag::drawDetectedMarkers(image, corners, ids);
	cv::imwrite("example_result.jpg", image);

    return 0;
}