#pragma once

#include<iostream> 
#include<vector>
#include<string>
#include "song.hpp"

using namespace std;

class Playlist{
    private:
    string name;
    vector<Song*> songList;

    public:
    Playlist(string name)
    {
        this->name = name;
    }
    string getPlaylistName()
    {
        return this->name;
    }
    int getPlaylistSize()
    {
        return (int)this->songList.size();
    }
    vector<Song*> getSongList()
    {
        return this->songList;
    }

    void addSong(Song* sng)
    {
        if(sng==nullptr)
        {
            throw runtime_error("cannot add null song to playlist");
            
        }
        songList.push_back(sng);
    }


};