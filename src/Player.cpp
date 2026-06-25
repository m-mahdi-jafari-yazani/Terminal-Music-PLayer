#include "Player.h"

#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <thread>

#define MINIAUDIO_IMPLEMENTATION
#include "miniaudio.h"


int Player::play(int which_playlist, int which_song)
{
    current_playlist = playlists[which_playlist];
    current_song = current_playlist->getSongs()[which_song];

    if (ma_engine_init(NULL, &engine) != MA_SUCCESS)
    {
        std::cerr << "Error" << std::endl;
        return false;
    }

    std::string current_song_path = "../Data/" + current_song->getFilePath();
    
    if (ma_sound_init_from_file(&engine, current_song_path.c_str(), 0, NULL, NULL, &sound) != MA_SUCCESS)
    {
        std::cerr << "Error" << std::endl;
        return false;
    }

    ma_sound_start(&sound);

    int command;

    while(true)
    {
        std::cin >> command;
        if(command == 1)
        {
            if(current_state == PlayerState::PLAYING)
            {
                setCurrentState(PlayerState::STOPPED);
                ma_sound_stop(&sound); 
            }
            else
            {
                setCurrentState(PlayerState::PLAYING);
                ma_sound_start(&sound);
            }
        }
        else if(command == 2)
        {
            ma_sound_uninit(&sound);
            ma_engine_uninit(&engine);    
            return 1;
        }
        else if(command == 3)
        {
            ma_sound_uninit(&sound);
            ma_engine_uninit(&engine);    
            return 2;
        }
        else if(command == 4)
        {
            skip(-10);
        }
        else if(command == 5)
        {
            skip(10);
        }
        else if(command == 6)
        {
            break;
        }
        else if(command == 0)
        {
            current_state = PlayerState::STOPPED;
            ma_sound_uninit(&sound);
            ma_engine_uninit(&engine);
            return 0;
        }
    }

    if(current_mode == PlaybackMode::NO_REPEAT)
    {
        ma_sound_uninit(&sound);
        ma_engine_uninit(&engine);
        return 3;
    }
    else if(current_mode == PlaybackMode::REPEAT_SONG)
    {
        ma_sound_uninit(&sound);
        ma_engine_uninit(&engine);
        return 4;
    }
    else if(current_mode == PlaybackMode::REPEAT_PLAYLIST)
    {
        ma_sound_uninit(&sound);
        ma_engine_uninit(&engine);
        return 5;
    }
    else if(current_mode == PlaybackMode::SHUFFLE)
    {
        ma_sound_uninit(&sound);
        ma_engine_uninit(&engine);
        return 6;
    }

    ma_sound_uninit(&sound);
    ma_engine_uninit(&engine);
    return 0;
}

void Player::skip(float seconds)
{
    ma_uint64 cursor;
    ma_sound_get_cursor_in_pcm_frames(&sound, &cursor);

    ma_uint64 offset =
        (ma_uint64)(ma_engine_get_sample_rate(&engine) * fabs(seconds));

    if (seconds > 0)
    {
        cursor += offset;
    }
    else
    {
        cursor = (cursor > offset) ? (cursor - offset) : 0;
    }

    ma_sound_seek_to_pcm_frame(&sound, cursor);
}

