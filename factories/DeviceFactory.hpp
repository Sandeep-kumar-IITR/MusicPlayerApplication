#pragma once

#include<iostream>
#include "../devices/IAudioDevice.hpp"
#include "../devices/BluetoothAdaptor.hpp"
#include "../devices/Headphone.hpp"
#include "../devices/WiredAdaptor.hpp"
#include "../enums/DeviceTypes.hpp"

class DeviceFactory{
    public:
    static IAudioDevice* createdevice(DeviceType devicetype)
    {
        if(devicetype ==DeviceType::BLUETOOTH)
        {
            IAudioDevice* bluetoothdevice = new BlueToothAdaptor(new BluetoothAPI());
            return bluetoothdevice;
        }
        else if(devicetype ==DeviceType::WIRED)
        {
            IAudioDevice* wireddevice = new WiredAdaptor(new WiredAPI());
            return wireddevice;
        }
        if(devicetype ==DeviceType::HEADPHONE)
        {
            IAudioDevice* headphonedevice = new HeadphoneAdaptor(new HeadphoneAPI());
            return headphonedevice;
        }
        return nullptr;
    }



};