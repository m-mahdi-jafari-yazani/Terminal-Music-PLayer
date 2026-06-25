#pragma once

#include <string>
#include <vector>

#include "Playlist.h"
#include "MusicLibrary.h"
#include "M3uLoader.h"
#include "Player.h"
#include "InputHandler.h"
#include "UIRender.h"

class Application
{
private:
    M3uLoader playlists_loader;
    MusicLibrary* library;
    std::vector<Playlist*> playlists;
    Player play_engine;

    InputHandler* input_handler = new InputHandler();
    UIRender* user_interface = new UIRender();

    int current_playlist_index;
    int current_song_index;

public:
    Application();

    void playAMusic();

    void goPrevious();
    void goNext();

    void search_by_title();
    void search_by_artist();
    void search_by_album();
    void search_by_genre();
    void search_by_year();
    void search_by_duration();

    void search();

    void setPlaybackMode();

    void run();
};

