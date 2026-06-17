#pragma once

#include<iostream>
#include<string>

#include "IAudioDevice.hpp"
#include "../externals/HeadphoneAPI.hpp"
#include "../models/song.hpp"

using namespace std;


class HeadphoneAdaptor:public IAudioDevice{

    private:
    HeadphoneAPI* Headphone;
    public:
    HeadphoneAdaptor(HeadphoneAPI* blu)
    {
        this->Headphone = blu;
    }
    void playAudio(Song* song)
    {
        string payload = "song "+song->getname() + " artist " + song->getartist();
        Headphone->playSoundViaHeadphone(payload);
    }



};
