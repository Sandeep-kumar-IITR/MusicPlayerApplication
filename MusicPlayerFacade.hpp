#pragma once

#include <iostream>

#include "core/AudioEngine.hpp"
#include "models/playlist.hpp"
#include "strategies/IPlayStrategies.hpp"
#include "enums/DeviceTypes.hpp"
#include "managers/DeviceManager.hpp"
#include "enums/PlayStrategytype.hpp"
#include "managers/StrategyManager.hpp"
#include "managers/PlaylistManager.hpp"

using namespace std;

class MusicPlayerFacade
{
private:
    static MusicPlayerFacade *instance;
    AudioEngine *audioengine;
    Playlist *loadedplaylist;
    IplayStrategies *playstrategy;
    MusicPlayerFacade()
    {
        loadedplaylist = nullptr;
        audioengine = new AudioEngine();
        playstrategy = nullptr;
    }

public:
    static MusicPlayerFacade *getinstance()
    {
        if (!instance)
        {
            instance = new MusicPlayerFacade();
        }
        return instance;
    }
    void connectDevice(DeviceType devicetype)
    {
        DeviceManager::getInstance()->connectDevice(devicetype);
    }
    void setPlayStrategy(PlayStrategytype plstr)
    {
        playstrategy = StrategyManager::getinstance()->getStrategy(plstr);
    }
    void loadPlaylist(const string &name)
    {
        loadedplaylist = PlaylistManager::getInstance()->getPlaylist(name);
        if (!playstrategy)
        {
            throw runtime_error("play strategy not seted before loading");
        }
        playstrategy->setPlaylist(loadedplaylist);
    }

    void playSong(Song *song)
    {
        if (!DeviceManager::getInstance()->getOutputdevice())
        {
            throw runtime_error("No audio device connected");
        }
        IAudioDevice *device = DeviceManager::getInstance()->getOutputdevice();
        audioengine->play(device, song);
    }

    void pauseSong(Song *song)
    {
        if (audioengine->getcurrentsongtittle() != song->getname())
        {
            throw runtime_error("this song not currently playing");
        }
        audioengine->pause();
    }
    void playAllTrack()
    {
        if (!loadedplaylist)
        {
            throw runtime_error("No Playlist Loaded");
        }
        while (playstrategy->hasNext())
        {
            Song *nextSong = playstrategy->next();
            IAudioDevice *device = DeviceManager::getInstance()->getOutputdevice();
            audioengine->play(device, nextSong);
        }
    }
    void playNextTrack()
    {
        if (!loadedplaylist)
        {
            throw runtime_error("No Playlist Loaded");
        }
        if (playstrategy->hasNext())
        {
            Song *nextSong = playstrategy->next();
            IAudioDevice *device = DeviceManager::getInstance()->getOutputdevice();
            audioengine->play(device, nextSong);
        }
    }

    void playPreviousTrack()
    {
        if (!loadedplaylist)
        {
            throw runtime_error("No Playlist Loaded");
        }
        if (playstrategy->hasPrevious())
        {
            Song *nextSong = playstrategy->Previous();
            IAudioDevice *device = DeviceManager::getInstance()->getOutputdevice();
            audioengine->play(device, nextSong);
        }
    }
    void enqueueNext(Song* song)
    {
        playstrategy->addToNext(song);
    }
};

MusicPlayerFacade* MusicPlayerFacade::instance = nullptr;