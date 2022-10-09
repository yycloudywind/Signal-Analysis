/*************************
 * @Author: hlh          *
 * @Date:2022/10/9       *
 *************************/
#ifndef SIGNAL_FILE_READER_HLH_H
#define SIGNAL_FILE_READER_HLH_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include <vector>
#include <Windows.h>
#include <algorithm>

#define KEYDOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)

class SignalFileReaderHLH {
public:
    SignalFileReaderHLH(const char* filename);

    std::vector<double> data0, data1;      //左右声道，单声道则相等
    long data_frequency;        //采样频率
    short data_bit;    //一个样本的位数
    char* data_input;      //音频数据 ,这里要定义什么就看样本位数了，我这里只是单纯的复制数据
    long file_size;         //文件大小
    short data_channel;         //通道数
    long data_bitrate;          //Byte率
    long data_size;         //数据大小

    void waveform();
    void printwavelog();
};


#endif //SIGNAL_FILE_READER_HLH_H
