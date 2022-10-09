/*************************
 * @Author: hlh          *
 * @Date:2022/10/9       *
 *************************/
#ifndef SHOW_SIGNAL_WINDOWS_HLH_H
#define SHOW_SIGNAL_WINDOWS_HLH_H

#include<vector>
#include <iostream>
#include <cmath>

using namespace std;
enum windowstype {
    Rect, Hanning, Hamming
};

class ShowSignalWindowsHLH {
public:
    ShowSignalWindowsHLH(long set_length, windowstype set_type);

    double length;
    windowstype type;
    vector<double> params;

    vector<double> addwindow(vector<double> targ, long di);

};

#endif //SHOW_SIGNAL_WINDOWS_HLH_H
