#include <iostream>
#include <filesystem>
#include "VideoProcess.h"
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>

// ./bin/app_frisbee /home/ag4933/src/cpp/rit/imgs/apps/frisbee_rpa/frisbee.MP4

using namespace std;

namespace FrisbeeRPA {

VideoProcess::VideoProcess(const string& filename) : video_(filename) {
  video_.isOpened() ? cerr << "Video Successfully Opened" << endl
                    : cerr << "Video Failed To Open" << endl;
}

void VideoProcess::Track() {
  cv::Mat frame;
  cv::Mat hsv_frame;
  cv::Mat mask;

  string outputFilename = "tracked.mp4";
  cv::VideoWriter writer;
  double fps = video_.get(cv::CAP_PROP_FPS);
  cv::Size frameSize(video_.get(cv::CAP_PROP_FRAME_WIDTH),
                     video_.get(cv::CAP_PROP_FRAME_HEIGHT));
  writer.open("tracked.mp4", cv::VideoWriter::fourcc('m', 'p', '4', 'v'), fps,
              frameSize, true);

  while (true) {
    video_ >> frame;
    if (frame.empty()) break;

    cv::cvtColor(frame, hsv_frame, cv::COLOR_BGR2HSV);
    cv::inRange(hsv_frame, lowerColor_, upperColor_, mask);

    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(mask, contours, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);

    if (!contours.empty()) {
      std::vector<cv::Point> mergedContour;
      for (const auto& contour : contours) {
        mergedContour.insert(mergedContour.end(), contour.begin(),
                             contour.end());
      }

      cv::Rect box = cv::boundingRect(mergedContour);
      cv::rectangle(frame, box, cv::Scalar(0, 0, 255), 2);
      positions_.push_back(
          cv::Point(box.x + box.width / 2, box.y + box.height / 2));

      cv::putText(frame, "Frisbee", cv::Point(box.x, box.y - 10),
                  cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(255, 255, 255), 1);

      for (size_t i = 1; i < positions_.size(); ++i) {
        cv::line(frame, positions_[i - 1], positions_[i], cv::Scalar(0, 0, 255),
                 2);
      }
    }

    cv::imshow("Frame", frame);
    writer.write(frame);
    cv::waitKey(1);
  }

  writer.release();
  cv::destroyAllWindows();
}

}
