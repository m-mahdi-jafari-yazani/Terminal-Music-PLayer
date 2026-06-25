#pragma once

#include <vector>

#include "Song.h"
#include "Playlist.h"
#include "MusicLibrary.h"

class M3uLoader
{
private:
    MusicLibrary library;

    std::vector<Song*> loadAPlaylist(const std::string& path);
public:
    MusicLibrary* getLibrary() { return &library; };
    std::vector<Playlist*> loadPlaylists(const std::string& path);
};