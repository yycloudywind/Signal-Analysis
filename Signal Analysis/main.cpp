/*************************
 * @Author: hlh          *
 * @Date:2022/10/9       *
 *************************/
#include "SignalFileReaderHLH.h"
#include "ShowSignalWindowsHLH.h"
#include "SignalCalculateHLH.h"
#include <Windows.h>

using namespace std;

#define KEYDOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)

//��ͼ����
void form(vector<long long> v1, long freq) {
    auto maxPosition = max_element(v1.begin(), v1.end());
    for (int i = 2; !KEYDOWN(VK_ESCAPE) && i < 2 * freq; ++i) {
        cout << i << ' ';
        cout << v1[i];
        for (int j = 0; j < v1[i] / (*maxPosition) * 25 + 25; ++j) {
            cout << " ";
        }
        cout << '*' << endl;
    }
}

void form(vector<double> v1, long freq) {
    auto maxPosition = max_element(v1.begin(), v1.end());
    for (int i = 0; !KEYDOWN(VK_ESCAPE) && i < 2 * freq; ++i) {
        cout << i << ' ';
        cout << v1[i];
        for (int j = 0; j < v1[i] / (*maxPosition) * 25 + 25; ++j) {
            cout << " ";
        }
        cout << '*' << endl;
    }
}

void form(vector<int> v1, long freq) {
    auto maxPosition = max_element(v1.begin(), v1.end());
    for (int i = 0; !KEYDOWN(VK_ESCAPE) && i < 2 * freq; ++i) {
        cout << i << ' ';
        cout << v1[i];
        for (int j = 0; j < v1[i] + 25; ++j) {
            cout << " ";
        }
        cout << '*' << endl;
    }
}

vector<long long> Energy;
vector<double> Range;
vector<int> Zero;

int command = 1;

void ui() {
    cout << "1-----���Ʋ��� " << endl;
    cout << "2---- ������������ " << endl;
    cout << "3---- ���Ʒ��Ȳ��� " << endl;
    cout << "4---- ���ƹ����ʲ��� " << endl;
    cout << "0---- �˳� " << endl;
}

int main()
{
    SignalFileReaderHLH wave("wav.wav");
    ShowSignalWindowsHLH windows(20, Hanning);
    wave.printwavelog();
    cout << "��������" << endl;
    for (double i = 2; i < 2 * wave.data_frequency; i++) {
        vector<double> rst = windows.addwindow(wave.data0, i);
        SignalCalculateHLH wavecalculate(rst);
        Energy.push_back(wavecalculate.energy);    //��ʱ����
        Range.push_back(wavecalculate.range);    //��ʱƽ������
        Zero.push_back(wavecalculate.zero);    //��ʱ������
    }
    system("pause");
    while (command) {
        ui();
        cin >> command;
        switch (command) {
        case 1:
            wave.waveform();
            break;
        case 2:
            form(Energy, wave.data_frequency);
            break;
        case 3:
            form(Range, wave.data_frequency);
            break;
        case 4:
            form(Zero, wave.data_frequency);
            break;
        default:
            break;
        }
        system("cls");
    }
    return 0;
}