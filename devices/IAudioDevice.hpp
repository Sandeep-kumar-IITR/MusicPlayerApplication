#pragma once

#include<iostream> 
#include "../models/song.hpp"
using namespace std;


class IAudioDevice{

    public:
    virtual void playAudio(Song* song) =0;

};

