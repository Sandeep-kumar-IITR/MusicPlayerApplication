#pragma once
#include<iostream>
#include<string>

using namespace std;

class Song{
    private:
    string name;
    string artist;
    string path;
    public:
    Song(string name , string artist , string path)
    {
        this->name = name;
        this->artist = artist;
        this->path = path;
    }
    string getname()
    {
        return this->name;

    }
    string getartist()
    {
        return this->artist;
    }
    string getpath()
    {
        return this->path;
    }

};