#pragma once
#include "managers/PlaylistManager.hpp"
#include "MusicPlayerFacade.hpp"
#include "enums/PlayStrategytype.hpp"

using namespace std;

class MusicPlayerApplication {
private:
    static MusicPlayerApplication* instance;
    vector<Song*> songLibrary;
    MusicPlayerApplication() {}

public:
    static MusicPlayerApplication* getInstance() {
        if (!instance) {
            instance = new MusicPlayerApplication();
        }
        return instance;
    }

    void createSongInLibrary(const string& title, const string& artist,
                                const string& path) {
        Song* newSong = new Song(title, artist, path);
        songLibrary.push_back(newSong);
    }

    Song* findSongByTitle(const string& title) {
        for (Song* s : songLibrary) {
            if (s->getname() == title) {
                return s;
            }
        }
        return nullptr;
    }
    void createPlaylist(const string& playlistName) {
        PlaylistManager::getInstance()->CreatePlaylist(playlistName);
    }

    void addSongToPlaylist(const string& playlistName,
                            const string& songTitle) {
        Song* song = findSongByTitle(songTitle);
        if (!song) {
            throw runtime_error("Song \"" + songTitle + "\" not found in library.");
        }
        PlaylistManager::getInstance()
            ->addSongToPlaylist(playlistName, song);
    }

    void connectAudioDevice(DeviceType deviceType) {
        MusicPlayerFacade::getinstance()->connectDevice(deviceType);
    }

    void selectPlayStrategy(PlayStrategytype strategyType) {
        MusicPlayerFacade::getinstance()->setPlayStrategy(strategyType);
    }

    void loadPlaylist(const string& playlistName) {
        MusicPlayerFacade::getinstance()->loadPlaylist(playlistName);
    }

    void playSingleSong(const string& songTitle) {
        Song* song = findSongByTitle(songTitle);
        if (!song) {
            throw runtime_error("Song \"" + songTitle + "\" not found.");
        }
        MusicPlayerFacade::getinstance()->playSong(song);
    }

    void pauseCurrentSong(const string& songTitle) {
        Song* song = findSongByTitle(songTitle);
        if (!song) {
            throw runtime_error("Song \"" + songTitle + "\" not found.");
        }
        MusicPlayerFacade::getinstance()->pauseSong(song);
    }

    void playAllTracksInPlaylist() {
        MusicPlayerFacade::getinstance()->playAllTrack();
    }

    void playPreviousTrackInPlaylist() {
        MusicPlayerFacade::getinstance()->playPreviousTrack();
    }

    void queueSongNext(const string& songTitle) {
        Song* song = findSongByTitle(songTitle);
        if (!song) {
            throw runtime_error("Song \"" + songTitle + "\" not found.");
        }
        MusicPlayerFacade::getinstance()->enqueueNext(song);
    }
};

MusicPlayerApplication* MusicPlayerApplication::instance = nullptr;