#pragma once

#include<iostream>
#include<string>
using namespace std;

class BluetoothAPI{

    public:
    void playSoundViaBluetooth(string data)
    {
        cout<< "[I am playing sound via Bluetooth "<<data<<" ]"<<endl;

    }

};