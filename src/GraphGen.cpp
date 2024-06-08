#include <iostream>
#include <vector>
#include <opencv2/core.hpp>
#include <matplot/matplot.h>
#include "GraphGen.h"

namespace FrisbeeRPA {

void PosGraph(const std::vector<int>& x, const std::vector<int>& y) {
  matplot::plot(x, y)->color("r").line_width(2);
  matplot::title("Frisbee Path");
  matplot::xlabel("Horizontal");
  matplot::ylabel("Vertical");
  matplot::xlim({0, 1920});
  matplot::ylim({1080, 0});
  matplot::show();
  matplot::save("PosGraph.eps");
}

void SpeedGraph(const std::vector<cv::Point>& positions, const double& fps,
                const double& scale) {
  double dx, dy, speed;
  std::vector<double> speeds_vector, time;

  for (size_t i = 1; i < positions.size(); i++) {
    dx = positions[i].x - positions[i - 1].x;
    dy = positions[i].y - positions[i - 1].y;
    speed = sqrt(dx * dx + dy + dy) * scale * fps;
    speeds_vector.push_back(speed);
  }

  for (size_t i = 0; i < speeds_vector.size(); i++) {
    time.push_back(i / fps);
  }

  matplot::plot(time, speeds_vector);
  matplot::title("Speed Over Time");
  matplot::xlabel("Time (seconds)");
  matplot::ylabel("Speed (inches/second)");

  matplot::show();
  matplot::save("SpeedGraph.eps");
}

}