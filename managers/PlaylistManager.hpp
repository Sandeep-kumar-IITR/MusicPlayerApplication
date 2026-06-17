#pragma once
#include<iostream>
#include<string>
#include<map>

#include "../models/playlist.hpp"
#include "../models/song.hpp"

using namespace std;

class PlaylistManager{
    private:
    static PlaylistManager* instance;
    map<string, Playlist*> playlists;
    PlaylistManager(){}
    public:
    static PlaylistManager* getInstance()
    {
        if(instance==nullptr)
        {
            instance = new PlaylistManager();
        }
        return instance;
    }
    void CreatePlaylist(const string &name)
    {
        if(playlists.count(name))
        {
           throw runtime_error("Playlist already exst");
        }
        playlists[name] = new Playlist(name);
    }
    void addSongToPlaylist(const string &name , Song* song)
    {
        if(!playlists.count(name))
        {
            throw runtime_error("Playlist not exist");
        }
        playlists[name]->addSong(song);

    }
    Playlist* getPlaylist(string name)
    { 
        if(!playlists.count(name))
        {
            throw runtime_error("Playlist not exist");
        }
        return playlists[name];
    }

};
PlaylistManager* PlaylistManager::instance = nullptr; 
