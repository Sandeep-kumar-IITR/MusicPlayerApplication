#pragma once

#include<iostream>
#include "../devices/IAudioDevice.hpp"
#include "../enums/DeviceTypes.hpp"
#include "../factories/DeviceFactory.hpp"

class DeviceManager{
    private:
    static DeviceManager* instance;
    IAudioDevice* currentDevice;
    DeviceManager()
    {
        this->currentDevice= nullptr;
    }
    public:
    static DeviceManager* getInstance()
    {
        if(instance==nullptr)
        {
            instance = new DeviceManager();
        }
        return instance;
    }
    void connectDevice(DeviceType dvtype)
    {
        if(this->currentDevice!=nullptr)
        {
            delete this->currentDevice;
        }
        currentDevice = DeviceFactory::createdevice(dvtype);

    }
    IAudioDevice* getOutputdevice()
    {
        if(!currentDevice)
        {
            throw runtime_error("Output device not connected");
        }
        return currentDevice;

    }
    bool isDeviceConnected()
    {
        if(currentDevice==nullptr)
        {
            return false;
        }
        return true;
    }



};
DeviceManager* DeviceManager::instance =nullptr;