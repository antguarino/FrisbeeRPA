#ifndef VIDEOPROCESS_H
#define VIDEOPROCESS_H

#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <string>

namespace ObjectRPA {

class VideoProcess {
 public:
  /**
   * Constructor to initialize VideoProcess with a video file.
   * \param[in] filename  the path to the video file to be processed
   */
  VideoProcess(const std::string& filename);

  // Getters and Setters for lowerColor_, upperColor_, and positions_
  cv::Scalar lowerColor() const { return lowerColor_; }
  void lowerColor(const cv::Scalar& lowerColor) { lowerColor_ = lowerColor; }

  cv::Scalar upperColor() const { return upperColor_; }
  void upperColor(const cv::Scalar& upperColor) { upperColor_ = upperColor; }

  std::vector<cv::Point> positions() const { return positions_; }

  /**
   * Function to track the frisbee in the video and store its positions
   */
  void Track(const std::string& obj);

 private:
  cv::VideoCapture video_;
  cv::Scalar lowerColor_;
  cv::Scalar upperColor_;
  double fps_;
  std::vector<cv::Point> positions_;
};
}

#endif  // VIDEOPROCESS_H