#pragma once

#include<iostream>
#include<string>
using namespace std;

class HeadphoneAPI{

    public:
    void playSoundViaHeadphone(string data)
    {
        cout<< "[I am playing sound via Headphone "<<data<<" ]"<<endl;

    }

};