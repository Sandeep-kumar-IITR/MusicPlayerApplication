#pragma once

#include <iostream>

#include "../models/playlist.hpp"
#include "IPlayStrategies.hpp"

using namespace std;

class SequentialPlay : public IplayStrategies
{
private:
    Playlist *currentPlaylist;
    int index;

public:
    SequentialPlay()
    {
        currentPlaylist = nullptr;
        index = -1;
    }
    void setPlaylist(Playlist *playlist) override
    {
        currentPlaylist = playlist;
        index = -1;
    }

    bool hasNext() override
    {
        return (index + 1 < currentPlaylist->getPlaylistSize());
    }
    Song *next() override
    {
        if (!currentPlaylist || !hasNext())
        {
            throw runtime_error("Playlist not loaded or no next song");
        }

        index++;
        return currentPlaylist->getSongList()[index];
    }

     bool hasPrevious() override
    {
        return ((index - 1 )>0);
    }
    Song *Previous() override
    {
        if (!currentPlaylist || !hasPrevious())
        {
            throw runtime_error("Playlist not loaded or no Previous song");
        }

        index--;
        return currentPlaylist->getSongList()[index];
    }

    
    void addToNext(Song *song) {}
};
