#include <iostream>
#include <vector>
#include <cmath>
#include "SpeedCalc.h"
#include <opencv2/opencv.hpp>

using namespace std;

namespace FrisbeeRPA{
    SpeedCalc::SpeedCalc(std::vector<cv::Point> positions) {}
    std::vector<double> SpeedCalc::CalcSpeed() {
        double dx, dy, speed;
        std::vector<double> speeds_vector;

        for (int i = 1; i < positions_.size(); i++) {
            dx = positions_[i].x - positions_[i - 1].x;
            dy = positions_[i].y - positions_[i - 1].y;
            speed = sqrt(dx * dx + dy + dy) * scale_ * fps_;
            speeds_vector.push_back(speed);
        }
        
        return speeds_vector;
    }
}