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
        //�����ʱ����
        energy += long(data[i]) * long(data[i]);

        //����ƽ������
        range += (data[i]) / double(data.size());

        //���������
        if (i > 0 && long(data[i]) * long(data[i - 1] < 0)) zero++;
    }
}

