/*************************
 * @Author: hlh          *
 * @Date:2022/10/9       *
 *************************/
#include "ShowSignalWindowsHLH.h"

using namespace std;

ShowSignalWindowsHLH::ShowSignalWindowsHLH(long set_length, windowstype set_type) {
    length = set_length;
    type = set_type;
    //¾ØÐÎ´°
    if (type == Rect) {
        for (int i = 0; i < length; i++) {
            params.push_back(1);
        }
    }
    //ººÄþ´°
    if (type == Hanning) {
        for (int i = 0; i < length; i++) {
            params.push_back(0.5 - 0.5 * cos(2 * M_PI * i / (length - double(1))));
        }
    }
    //ººÃ÷´°
    if (type == Hamming) {
        for (int i = 0; i < length; i++) {
            params.push_back(0.54 - 0.46 * cos(2 * M_PI * i / (length - double(1))));
        }
    }
}

//Ö¡ÒÆ
vector<double> ShowSignalWindowsHLH::addwindow(vector<double> v, long di) {
    vector<double> result;
    for (int i = 0; i < length - 2; i++) {
        result.push_back(v[di + i] * params[i]);
    }
    return result;
};
