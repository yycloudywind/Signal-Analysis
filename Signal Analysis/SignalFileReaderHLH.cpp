/*************************
 * @Author: hlh          *
 * @Date:2022/10/9       *
 *************************/
#include "SignalFileReaderHLH.h"

using namespace std;

SignalFileReaderHLH::SignalFileReaderHLH(const char* filename) {
    fstream fs;
    fs.open(filename, ios::binary | ios::in);
    if (!fs) {
        cout << "打开文件失败" << endl;
        system("pause");
    }
    else {
        cout << "打开文件成功" << endl;
    }

    fs.seekg(0x04);
    fs.read((char*)&file_size, sizeof(file_size));
    fs.seekg(0x16);
    fs.read((char*)&data_channel, sizeof(data_channel));
    fs.seekg(0x18);
    fs.read((char*)&data_frequency, sizeof(data_frequency));
    fs.seekg(0x1c);
    fs.read((char*)&data_bitrate, sizeof(data_bitrate));
    fs.seekg(0x22);
    fs.read((char*)&data_bit, sizeof(data_bit));
    fs.seekg(0x28);
    fs.read((char*)&data_size, sizeof(data_size));
    data_input = new char[data_size];
    fs.seekg(0x2c);
    fs.read((char*)data_input, sizeof(char) * data_size);
    fs.close();

    double finaldata, leftfinaldata, rightfinaldata;
    if (data_channel == 2) {
        for (int i = 0; i < data_size; i += 4) {
            leftfinaldata = data_input[i] + data_input[i + 1] * std::pow(2, 8);
            rightfinaldata = data_input[i + 2] + data_input[i + 3] * std::pow(2, 8);
            if (int(data_input[i + 1] / std::pow(2, 7)) == 1)
                data0.push_back(leftfinaldata - std::pow(2, 16));
            else data0.push_back(leftfinaldata);
            if (int(data_input[i + 3] / std::pow(2, 7)) == 1)
                data1.push_back(rightfinaldata - std::pow(2, 16));
            else data1.push_back(rightfinaldata);
        }
        cout << "双声道已采集" << endl;
    }
    else {
        for (int i = 0; i < data_size; i += 2) {
            finaldata = data_input[i] + data_input[i + 1] * std::pow(2, 8);
            if (int(data_input[i + 1] / std::pow(2, 7)) == 1)
                data0.push_back(finaldata - std::pow(2, 16));
            else data0.push_back(finaldata);
        }
        cout << "单声道已采集" << endl;
    }
}

void SignalFileReaderHLH::waveform() {
    auto maxPosition = max_element(data0.begin(), data0.end());
    for (int i = 0; !KEYDOWN(VK_ESCAPE) && i < 2 * data_frequency; ++i) {
        cout << i << ' ';
        cout << data0[i];
        for (int j = 0; j < data0[i] / (*maxPosition) * 25 + 25; ++j) {
            cout << " ";
        }
        cout << '*' << endl;
    }
}

void SignalFileReaderHLH::printwavelog() {
    cout << "------------------------" << endl;
    cout << "-------音频信息为---------" << endl;
    cout << "样本编码位数  ：" << data_bit << endl;
    cout << "采样频率      ：" << data_frequency << endl;
    cout << "比特率        ：" << data_bitrate << endl;
    cout << "音频通道数    ：" << data_channel << endl;
    cout << "------------------------" << endl;
}
