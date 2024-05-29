#ifndef GRAPHGEN_H
#define GRAPHGEN_H

namespace FrisbeeRPA {

    class GraphGen{
        public:
        /**
         * Constructor to initialize GraphGen with speeds and frame rate.
         * \param[in] speeds  the vector of speeds of the frisbee
         * \param[in] fps  the frame rate of the video
         */
        GraphGen::GraphGen(const std::vector<double>& speeds, double fps);

        private:
    };
}

#endif // GRAPHGEN_H