#include <opencv2/opencv.hpp>
#include <iostream>
#include <chrono>
#include "src/Stag.h"
#include <vector>

using namespace std;

int main()
{

    // Create a video capture object
    //    cv::VideoCapture cap(0); // Change to your camera index if necessary
    //    if (!cap.isOpened())
    //    {
    //        std::cerr << "Error: Could not open camera." << std::endl;
    //        return -1;
    //    }
    //    cap.set(cv::CAP_PROP_FRAME_WIDTH, 1280);
    //    cap.set(cv::CAP_PROP_FRAME_HEIGHT, 720);

    //    double width = cap.get(cv::CAP_PROP_FRAME_WIDTH);
    //    double height = cap.get(cv::CAP_PROP_FRAME_HEIGHT);
    //    cout << "\nImage resolution: " << width << " x " << height;

    // set HD library {11, 13, 15, 17, 19, 21, 23}
    int libraryHD = 11;

    float maxDetTime = 0.;
    cv::Mat frame;
    while (true)
    {
        //        cap >> frame; // Capture a new frame
        frame=cv::imread("/home/zero/projects/stag-CUDA/300dpi.png");
        auto now = std::chrono::system_clock::now();
        double startTime = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count();
        
        auto corners = std::vector<std::vector<cv::Point2f>>();
        auto ids = std::vector<int>();
        auto rejectedImgPoints = std::vector<std::vector<cv::Point2f>>(); // optional, helpful for debugging

        // detect markers
        stag::detectMarkers(frame, libraryHD, corners, ids, rejectedImgPoints);
        
        now = std::chrono::system_clock::now();
        double endTime = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count();
        float timeDiff = endTime - startTime;

        std::cout << "\ncurTime: " << timeDiff << "(ms), Max Detection time: " << maxDetTime <<endl;
        if (timeDiff > maxDetTime)
            maxDetTime = timeDiff;

        // display detected markers
        stag::drawDetectedMarkers(frame, corners, ids);
        cv::imshow("Stag Marker Detection", frame);

        // Exit on 'q' key press
        if (cv::waitKey(10) == 'q')
        {
            break;
        }
    }
    return 0;
}