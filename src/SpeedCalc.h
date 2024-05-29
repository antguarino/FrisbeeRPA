#ifndef SPEEDCALC_H
#define SPEEDCALC_H

namespace FrisbeeRPA {

    class SpeedCalc{
        public:
            /**
             * Constructor to initialize SpeedCalc with a vector of positions.
             * \param[in] positions  the vector of points representing the positions of the frisbee
             */
            SpeedCalc(std::vector<cv::Point> positions) {positions_ = positions};

            // Getters and Setters for fps_ and scale_
            double FPS() const { return fps_; }
            void FPS(const double& fps)  { fps_ = fps; }

            double Scale() const { return scale_; }
            void Scale(const double& scale)  { scale_ = scale; }

            /**
             * Function to calculate the speed of the frisbee from its positions.
             * \return  a vector containing the speed of the frisbee at each point in time in inches per second.
             */
            std::vector<double> CalcSpeed();


        private:
        std::vector<cv::Point> positions_;
        double fps_;
        double scale_;
    };
}

#endif // SPEEDCALC_H