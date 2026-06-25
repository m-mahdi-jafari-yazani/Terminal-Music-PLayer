#pragma once

#include <string>
#include <vector>

#include "Song.h"

class Playlist
{
private:
    std::string name;
    std::vector<Song*> songs;

public:
    Playlist(std::string name_, std::vector<Song*> songs_);
    int size() { return songs.size(); }
    std::string getName() { return name; }
    std::vector<Song*> getSongs() { return songs; }
};