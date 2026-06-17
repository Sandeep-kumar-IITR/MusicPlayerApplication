#pragma once

#include<iostream>
#include "../models/playlist.hpp"
#include "../models/song.hpp"

class IplayStrategies{
    public:
    virtual void setPlaylist(Playlist* playlist)=0;
    virtual Song* next() = 0;
    virtual bool hasNext()=0;
    virtual Song* Previous() = 0;
    virtual bool hasPrevious()=0;
    virtual void addToNext(Song* song) {}
    
};
