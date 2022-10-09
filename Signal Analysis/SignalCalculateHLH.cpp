/*************************
 * @Author: hlh          *
 * @Date:2022/10/9       *
 *************************/
#include "SignalCalculateHLH.h"

SignalCalculateHLH::SignalCalculateHLH(std::vector<double> data) {
    range = 0;
    energy = 0;
    zero = 0;
    for (int i = 0; i < data.size(); i++) {
        //计算短时能量
        energy += long(data[i]) * long(data[i]);

        //计算平均幅度
        range += (data[i]) / double(data.size());

        //计算过零率
        if (i > 0 && long(data[i]) * long(data[i - 1] < 0)) zero++;
    }
}

