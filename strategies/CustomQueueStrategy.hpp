#pragma once

#include <iostream>
#include <queue>
#include <stack>
#include <vector>

#include "../models/playlist.hpp"
#include "IPlayStrategies.hpp"

using namespace std;

class CustomQueuePlay : public IplayStrategies
{
private:
    Playlist *currentPlaylist;
    queue<Song*> nextQueue;
    stack<Song*> history;
    int index;

public:
    CustomQueuePlay()
    {
        currentPlaylist = nullptr;
        index = -1;
    }
    void setPlaylist(Playlist *playlist) override
    {
        currentPlaylist = playlist;
        while (!nextQueue.empty()) nextQueue.pop();
        while (!history.empty()) history.pop();
        index = -1;
    }

    bool hasNext() override
    {
        if (!nextQueue.empty()) return true;
        return (currentPlaylist && (index + 1 < currentPlaylist->getPlaylistSize()));
    }
    Song *next() override
    {
        if (!hasNext())
        {
            throw runtime_error("Playlist not loaded or no next song");
        }
        Song *selected = nullptr;
        if (!nextQueue.empty())
        {
            selected = nextQueue.front();
            nextQueue.pop();
        }
        else
        {
            index++;
            selected = currentPlaylist->getSongList()[index];
        }
        history.push(selected);
        return selected;
    }

    bool hasPrevious() override
    {
        return !history.empty();
    }
    Song *Previous() override
    {
        if (!hasPrevious())
        {
            throw runtime_error("Playlist not loaded or no Previous song");
        }
        Song *song = history.top();
        history.pop();
        return song;
    }

    void addToNext(Song *song) override
    {
        nextQueue.push(song);
    }
};
