#include <iostream>
#include "imgs/ipcv/frisbee_rpa/FrisbeeRPA.h"
#include <opencv2/core.hpp>
#include <matplot/matplot.h>

using namespace std;

int main(int argc, char* argv[]) {
  std::cout << "Frisbee Speed Calculator" << std::endl;

  FrisbeeRPA::VideoProcess fris(argv[1]);

  cv::Scalar lowerColor = cv::Scalar(155, 65, 213);
  cv::Scalar upperColor = cv::Scalar(168, 118, 255);

  fris.lowerColor(lowerColor);
  fris.upperColor(upperColor);

  fris.Track("Frisbee");

  std::vector<cv::Point> positions = fris.positions();

  std::vector<int> positions_x;
  std::vector<int> positions_y;
  for (size_t i = 0; i < positions.size(); i++) {
    positions_x.push_back(positions[i].x);
    positions_y.push_back(positions[i].y);
  }

  FrisbeeRPA::SpeedGraph(positions, 59.94, 0.25);
  FrisbeeRPA::PosGraph(positions_x, positions_y);
}