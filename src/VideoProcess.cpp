#include <iostream>
#include "VideoProcess.h"
#include <opencv2/opencv.hpp>

using namespace std;

namespace FrisbeeRPA{

VideoProcess::VideoProcess(const string& filename) {
    cv::VideoCapture video_(filename);
    video_.isOpened() ? cerr << "Video Successfully Opened" << endl : cerr << "Video Failed To Open" << endl;
}

void VideoProcess::Track() {
    cv::Mat frame;
    cv::Mat hsv_frame;
    cv::Mat mask;

    while (!frame.empty()) {
        video_ >> frame;

        cv::cvtColor(frame, hsv_frame, cv::COLOR_BGR2HSV);
        cv::inRange(hsv_frame, lowerColor_, upperColor_, mask);

        std::vector<std::vector<cv::Point>> contours;
        cv::findContours(mask, contours, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);

        cv::imshow("Frame", frame);
    }
    

    cv::destroyAllWindows();
}

void VideoProcess::OutputVideo(const std::string& outputFilename) {
    
    cv::VideoWriter writer;

    cv::Mat frame;
    cv::Mat hsv_frame;
    cv::Mat mask;

    cv::Size frameSize(video_.get(cv::CAP_PROP_FRAME_WIDTH), video_.get(cv::CAP_PROP_FRAME_HEIGHT));

    cv::cvtColor(frame, hsv_frame, cv::COLOR_BGR2HSV);
    cv::inRange(hsv_frame, lowerColor_, upperColor_, mask);

    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(mask, contours, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);

    writer.open(outputFilename, cv::VideoWriter::fourcc('H', '2', '6', '4'), video_.get(cv::CAP_PROP_FPS), frameSize, true);

    while(!frame.empty()) {

        cv::Rect box = cv::boundingRect(contours);
        cv::rectangle(frame, box, cv::Scalar(0, 0, 255), 2);

        video_ >> frame;
        writer.write(frame);
        
    }
}

}