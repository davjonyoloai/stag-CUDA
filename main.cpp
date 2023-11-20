#include "src/Stag.h"
#include <opencv2/imgcodecs.hpp>
#include<vector>
using cv::Mat;

std::tuple<std::vector<std::vector<std::vector<double>>>, std::vector<int>> detectMarkers(Mat inImage, int libraryHD, int errorCorrection);
std::vector<int> getIds(Stag *stag);

int main() {
    // load image
    cv::Mat image = cv::imread("../testimage.jpg", cv::ImreadModes::IMREAD_GRAYSCALE);

    // detect markers
    auto results = detectMarkers(image, 21, 7);

    return 0;
}


// get Corners
std::vector<std::vector<std::vector<double>>> getCorners(Stag *stag) {

    std::vector<std::vector<std::vector<double>>> ret;
    for (auto marker : stag->markers) {
        std::vector<std::vector<double>> contours;
        for (cv::Point2d pt : marker.corners) {
            contours.push_back({pt.x, pt.y});
        }
        ret.push_back(contours);
    }
    return ret;
}

// get IDs
std::vector<int> getIds(Stag *stag) {
    std::vector<int> ret;
    for (auto marker : stag->markers) {
        ret.push_back(marker.id);
    }
    return ret;
}

// detect markers in image and return corners and ids
std::tuple<std::vector<std::vector<std::vector<double>>>, std::vector<int>> detectMarkers(Mat inImage, int libraryHD, int errorCorrection) {
    // initialize STag detector
    Stag stag(libraryHD, errorCorrection, true);

    // detect markers
    stag.detectMarkers(inImage);

    // log results to directory (creates images for every detection step)
    // NOTE: the directory must exist
    stag.logResults("");

    return std::tuple<std::vector<std::vector<std::vector<double>>>, std::vector<int>>{getCorners(&stag), getIds(&stag)};
}
