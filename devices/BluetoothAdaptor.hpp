#pragma once

#include<iostream>
#include<string>

#include "IAudioDevice.hpp"
#include "../externals/BluetoothAPI.hpp"
#include "../models/song.hpp"

using namespace std;


class BlueToothAdaptor:public IAudioDevice{

    private:
    BluetoothAPI* bluetooth;
    public:
    BlueToothAdaptor(BluetoothAPI* blu)
    {
        this->bluetooth = blu;
    }
    void playAudio(Song* song)
    {
        string payload = "song "+song->getname() + " artist " + song->getartist();
        bluetooth->playSoundViaBluetooth(payload);
    }



};
