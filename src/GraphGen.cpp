#include <iostream>
#include <vector>
#include <matplot/matplot.h>
#include "GraphGen.h"

namespace FrisbeeRPA {

GraphGen::GraphGen(const std::vector<double>& speeds, double fps) {

    std::vector<double> time;
    for (size_t i = 0; i < speeds.size(); i++) {
        time.push_back(i / fps);
    }

    matplot::plot(time, speeds);
    matplot::title("Frisbee Speed Over Time");
    matplot::xlabel("Time (seconds)");
    matplot::ylabel("Speed (inches/second)");

    matplot::show();
}

}