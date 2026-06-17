#pragma once

#include <iostream>
#include <string>

#include "../models/song.hpp"
#include "../devices/IAudioDevice.hpp"

using namespace std;

class AudioEngine
{

private:
    Song *currentsong;
    bool songIspaused;

public:
    AudioEngine()
    {
        this->currentsong = nullptr;
        this->songIspaused = false;
    }
    string getcurrentsongtittle()
    {
        return this->currentsong->getname();
    }
    bool isPaused()
    {
        return this->songIspaused;
    }
    void play(IAudioDevice *audiodevice, Song *song)
    {
        if (song == nullptr)
        {
            throw runtime_error("can't play null song");
        }
        if (songIspaused && currentsong == song)
        {
            this->songIspaused = false;
            cout << "Resuming song " << this->currentsong->getname() << " " << endl;
            audiodevice->playAudio(this->currentsong);
            return;
        }
        this->currentsong = song;
        this->songIspaused = false;
        cout << "Playing song " << this->currentsong->getname() << " " << endl;
        audiodevice->playAudio(this->currentsong);
    }
    void pause()
    {
        if(this->currentsong ==nullptr)
        {
            throw runtime_error("Null song can't be pause");
        }
        if(this->songIspaused == true)
        {
            throw runtime_error("Song is already paused");
        }
        this->songIspaused = true;
        cout<<"Pausing song "<<currentsong->getname()<<" "<<endl;

    }
};