#include "Stag.h"
#include "opencv2/opencv.hpp"
#include <opencv2/imgcodecs.hpp>

int main() {
    cv::Mat image = cv::imread("1.png", cv::ImreadModes::IMREAD_GRAYSCALE);

    Stag stag(15, 7, true);

    stag.detectMarkers(image);
    stag.logResults("");
    return 0;
}
