/*************************
 * @Author: hlh          *
 * @Date:2022/10/9       *
 *************************/
#ifndef SIGNAL_CALCULATE_HLH_H
#define SIGNAL_CALCULATE_HLH_H

#include<vector>
#include <cmath>

class SignalCalculateHLH {
public:
    SignalCalculateHLH(std::vector<double> data);

    long long energy;
    double range;
    int zero;
};

#endif //WAVE_WAVE_CALCULATE_H
