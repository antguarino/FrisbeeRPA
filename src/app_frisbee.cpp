#include <iostream>
#include "FrisbeeRPA.h"
#include <opencv2/opencv.hpp>

using namespace std;

int main(){
    std::cout << "Frisbee Speed Calculator" << std::endl;

    FrisbeeRPA::VideoProcess fris("frisbee.MP4")

    cv::Scalar lowerColor = cv::Scalar(315, 40, 95);
    cv::Scalar upperColor = cv::Scalar(345, 30, 65);

    fris.lowerColor(lowerColor);
    fris.upperColor(upperColor);

    fris.Track();

    SpeedCalc::FPS(60);
    SpeedCalc::Scale(9/35); // 9 inches / 35 pixels
    SpeedCalc::SpeedCalc(VideoProcess::positions());
    SpeedCalc::CalcSpeed();

    GraphGen::GraphGen(SpeedCalc::CalcSpeed(), FPS());

    VideoProcess::OutputVideo("tracked_frisbee.MP4")

}