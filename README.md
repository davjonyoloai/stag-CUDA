# STag - A Stable, Occlusion-Resistant Fiducial Marker System

This repository is an updated fork of the [stable fiducial marker system](https://github.com/bbenligiray/stag), modified to use OpenCV 4.

Corresponding python package: https://github.com/ManfredStoiber/stag-python

## 📊 Comparison Between Different Marker Systems:
[<img src="https://github.com/ManfredStoiber/stag/assets/47210077/668ca457-33dd-4ce7-8b94-662c7a5bb4d9" width="400" height="200" />](https://www.youtube.com/watch?v=vnHI3GzLVrY)

## 📋 Getting Started
0. Install Prerequisites
    - [CMake >= 3.16](https://cmake.org/getting-started/)
        - On Linux: `apt install cmake`
    - [OpenCV 4](https://opencv.org/get-started/) for C++
        - On Linux: `apt install libopencv-dev`
1. Clone this repository: `git clone https://github.com/ManfredStoiber/stag`
2. Build
    1. cd into project: `cd stag`
    2. `mkdir build`
    3. `cd build`
    4. `cmake ..`
    5. `make`
3. Run test app
    1. `cd ../app`
    2. Run `./stagtest`. This creates several images in the current directory, one for each detection step

## 📖 Usage

For an example how to use this library, refer to [main.cpp](https://github.com/ManfredStoiber/stag/blob/master/main.cpp) and [src/Stag.h](https://github.com/ManfredStoiber/stag/blob/master/src/Stag.h)

## 🏷 Markers

- Collection of markers: [Drive](https://drive.google.com/drive/folders/0ByNTNYCAhWbIV1RqdU9vRnd2Vnc?resourcekey=0-9ipvecbezW8EWUva5GBQTQ&usp=sharing)
- Marker Generator: see [ref/marker generator](https://github.com/ManfredStoiber/stag/tree/master/ref/marker%20generator) for reference code for marker generation

## 📔 Known Issues
- Sometimes markers are detected multiple times
    - Workaround: only use one of the detections

## 📰 Originally Published in the Following Paper:

[B. Benligiray; C. Topal; C. Akinlar, "STag: A Stable Fiducial Marker System," Image and Vision Computing, 2019.](https://arxiv.org/abs/1707.06292)

Some figures from the paper:

<p align="center">
  <img src="https://user-images.githubusercontent.com/19530665/57179654-c0c11e00-6e88-11e9-9ca5-0c0153b28c91.png"/>
</p>

<p align="center">
  <img src="https://user-images.githubusercontent.com/19530665/57179660-cae31c80-6e88-11e9-8f80-bf8e24e59957.png"/>
</p>
