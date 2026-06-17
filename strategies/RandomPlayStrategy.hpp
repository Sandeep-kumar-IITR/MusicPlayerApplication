#pragma once

#include <iostream>
#include<stack>
#include<vector>


#include "../models/playlist.hpp"
#include "IPlayStrategies.hpp"

using namespace std;

class RandomPlay : public IplayStrategies
{
private:
    Playlist *currentPlaylist;
    vector<Song*> remaningsong;
    stack<Song*> history;

    

public:
    RandomPlay()
    {
        currentPlaylist = nullptr;
        srand((unsigned)time(nullptr));
    }
    void setPlaylist(Playlist *playlist) override
    {
        currentPlaylist = playlist;
        if(!currentPlaylist||currentPlaylist->getPlaylistSize()==0) return;
        remaningsong = currentPlaylist->getSongList();
        history = stack<Song*>();

    }

    bool hasNext() override
    {
        return (remaningsong.size()!=0);
    }
    Song *next() override
    {
        if (!currentPlaylist || !hasNext())
        {
            throw runtime_error("Playlist not loaded or no next song");
        }

        int idx = rand()%remaningsong.size();
        Song* selectedSong = remaningsong[idx];
        swap(remaningsong[idx] , remaningsong.back());
        remaningsong.pop_back();
        history.push(selectedSong);
        return selectedSong;
    }

     bool hasPrevious() override
    {
        return (!history.empty());
    }
    Song *Previous() override
    {
        if (!hasPrevious())
        {
            throw runtime_error("Playlist not loaded or no Previous song");
        }

        Song* song  = history.top();
        history.pop();
        return song;
    }

    
    void addToNext(Song *song) {}
};
