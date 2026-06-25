#pragma once

#include <iostream>
#include <vector>

#include "Song.h"
#include "Playlist.h"
#include "Player.h"

class UIRender
{
private:

public:
    void clear();
    void printMainMenu();
    void printSong(Song* song);
    void printSongs(std::vector<Song*> songs);
    void printPlayingSongOptions();
    void printPlaylists(std::vector<Playlist*> playlists);
    void printSearchItems();

    void printPlaybackModes();
    void printCurrentPlaybackMode(PlaybackMode current_playback_mode);
};