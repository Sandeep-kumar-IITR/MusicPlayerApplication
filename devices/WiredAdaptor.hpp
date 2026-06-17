#pragma once

#include<iostream>
#include<string>

#include "IAudioDevice.hpp"
#include "../externals/WiredAPI.hpp"
#include "../models/song.hpp"

using namespace std;


class WiredAdaptor:public IAudioDevice{

    private:
    WiredAPI* Wired;
    public:
    WiredAdaptor(WiredAPI* blu)
    {
        this->Wired = blu;
    }
    void playAudio(Song* song)
    {
        string payload = "song "+song->getname() + " artist " + song->getartist();
        Wired->playSoundViaWired(payload);
    }



};
