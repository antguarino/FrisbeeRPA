#ifndef GRAPHGEN_H
#define GRAPHGEN_H

#include <vector>

namespace ObjectRPA {

void PosGraph(const std::vector<int>& x, const std::vector<int>& y);

/**
 * Constructor to initialize GraphGen with speeds and frame rate.
 * \param[in] speeds  the vector of speeds of the frisbee
 * \param[in] fps  the frame rate of the video
 */
void SpeedGraph(const std::vector<cv::Point>& positions, const double& fps,
                const double& scale);
}

#endif  // GRAPHGEN_H