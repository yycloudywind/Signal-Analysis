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

    std::vector<double> data0, data1;      //���������������������
    long data_frequency;        //����Ƶ��
    short data_bit;    //һ��������λ��
    char* data_input;      //��Ƶ���� ,����Ҫ����ʲô�Ϳ�����λ���ˣ�������ֻ�ǵ����ĸ�������
    long file_size;         //�ļ���С
    short data_channel;         //ͨ����
    long data_bitrate;          //Byte��
    long data_size;         //���ݴ�С

    void waveform();
    void printwavelog();
};


#endif //SIGNAL_FILE_READER_HLH_H
