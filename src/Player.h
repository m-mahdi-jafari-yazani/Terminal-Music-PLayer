#pragma once

#define MA_NO_ENCODING
#define MA_NO_GENERATION
#include "miniaudio.h"

#include "Song.h"
#include "Playlist.h"

enum class PlayerState
{
    PLAYING,
    STOPPED
};

enum class PlaybackMode
{
    NO_REPEAT,
    REPEAT_SONG,
    REPEAT_PLAYLIST,
    SHUFFLE
};

class Player 
{
private:
    ma_engine engine;
    ma_sound  sound;

    std::vector<Playlist*> playlists;

    Playlist* current_playlist;
    Song* current_song;

    PlayerState current_state = PlayerState::PLAYING;
    PlaybackMode current_mode = PlaybackMode::NO_REPEAT;

public:
    void setPlaylists(std::vector<Playlist*> playlists_) { playlists = playlists_; }
    void setCurrentState(PlayerState current_state_) { current_state = current_state_; }
    void setCurrentMode(PlaybackMode current_mode_) { current_mode = current_mode_; }

    PlaybackMode getCurrentMode() { return current_mode; }

    int play(int which_playlist, int which_song);
    void skip(float seconds);
    

};
