# STag - A Stable, Occlusion-Resistant Fiducial Marker System

This repository is an updated fork of the [stable fiducial marker system](https://github.com/bbenligiray/stag), modified to use __OpenCV 4__.

For the corresponding __Python__ package, refer to: https://github.com/ManfredStoiber/stag-python

## 📊 Comparison Between Different Marker Systems:
[<img src="https://github.com/ManfredStoiber/stag/assets/47210077/668ca457-33dd-4ce7-8b94-662c7a5bb4d9" width="400" height="200" />](https://www.youtube.com/watch?v=vnHI3GzLVrY)

## 📖 Usage
```c++
// load image
cv::Mat image = cv::imread("example.jpg");

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
```

For an explanation of `libraryHD = 21` refer to [Configuration](#-configuration)

## 🏷 Markers

- Markers are downloadable here: [Drive](https://drive.google.com/drive/folders/0ByNTNYCAhWbIV1RqdU9vRnd2Vnc?resourcekey=0-9ipvecbezW8EWUva5GBQTQ&usp=sharing)
- Reference code for Marker Generator: [ref/marker_generator](https://github.com/ManfredStoiber/stag/tree/master/ref/marker_generator)

## 📋 Getting Started
0. __Install__ Prerequisites

    [__CMake__ >= 3.16](https://cmake.org/getting-started/)
     - On Linux: `apt install cmake`

    [__OpenCV__ 4](https://opencv.org/get-started/) for C++
     - On Linux: `apt install libopencv-dev`
1. __Clone__ this repository
   
   - `git clone https://github.com/ManfredStoiber/stag`
2. __Build__ the project.

   In the project directory, run the following commands:
    1. `mkdir build`
    2. `cd build`
    3. `cmake ..`
    4. `cmake --build .`
3. __Run__ the example
    1. `cd ../app`
    2. Run `./stag_example`
   
         This example application creates several images in the current directory, one for each detection step

## 🛠 Configuration
When initializing the library, following parameters can be specified:
- __`libraryHD`__:
  - Sets the "family" or "type" of used STag markers
    - Each library has a different amount of markers
    - Only the markers of the chosen library will be detected
  - The following HD libraries are possible:

    | __HD__           | 11     | 13    | 15  | 17  | 19 | 21 | 23 |
    |------------------|--------|-------|-----|-----|----|----|----|
    | __Library Size__ | 22,309 | 2,884 | 766 | 157 | 38 | 12 | 6  |

  - Specifies the used Hamming Distance, for further information refer to the [original paper](https://arxiv.org/abs/1707.06292)


- __`errorCorrection`__: 
   - Sets the amount of error correction
   - Has to be in range `0 <= errorCorrection <= (libraryHD-1)/2`
   - For further information refer to the [original paper](https://arxiv.org/abs/1707.06292)

## 📰 Originally Published in the Following Paper:

[B. Benligiray; C. Topal; C. Akinlar, "STag: A Stable Fiducial Marker System," Image and Vision Computing, 2019.](https://arxiv.org/abs/1707.06292)

<p align="center">
  <img src="https://user-images.githubusercontent.com/19530665/57179654-c0c11e00-6e88-11e9-9ca5-0c0153b28c91.png"/>
</p>

<p align="center">
  <img src="https://user-images.githubusercontent.com/19530665/57179660-cae31c80-6e88-11e9-8f80-bf8e24e59957.png"/>
</p>
