#include "UIRender.h"

#include <iomanip>

#include "Colors.h"

void UIRender::clear()
{
    std::cout << "\033[2J\033[H";
}

void UIRender::printMainMenu()
{
    std::cout << MAGENTA
              << "1. Play a Music" << std::endl
              << "2. Search" << std::endl
              << "3. Set Playback Mode" << std::endl
              << "4. Add a Song to Favorites" << std::endl
              << "5. Temporary Sort" << std::endl
              << "0. EXIT" << std::endl
              << RESET;
}

void UIRender::printSong(Song* song)
{
    std::cout << CYAN
              << "Title:    " << song->getTitle() << std::endl 
              << "Artist:   " << song->getArtist() << std::endl
              << "Album:    " << song->getAlbum() << std::endl
              << "Genre:    " << song->getGenre() << std::endl
              << "Duration: " << song->getDuration() << std::endl
              << "Year:     " << song->getYear() << std::endl
              << RESET;
}

void UIRender::printSongs(std::vector<Song*> songs)
{
    std::cout << BRED
              << "--------------------------------------------------" << std::endl
              << RESET;

    for(int i = 0; i < songs.size(); i++)
    {
        std::cout << BLUE << i << ". " << std::endl << RESET;
        printSong(songs[i]);
        if(i < songs.size() - 1)
        {
            std::cout << YELLOW
                      << "------------------------------" << std::endl
                      << RESET;
        }
    }

    std::cout << BRED
              << "--------------------------------------------------" << std::endl
              << RESET;
}

void UIRender::printPlayingSongOptions()
{
    std::cout << BBLUE
              << "1. PAUSE/RESUME" << std::endl
              << "2. PREVIOUS" << std::endl
              << "3. NEXT" << std::endl
              << "4. -10 SEC" << std::endl
              << "5. +10 SEC" << std::endl
              << "6. FINISH" << std::endl
              << "0. EXIT" << std::endl
              << RESET;
}

void UIRender::printPlaylists(std::vector<Playlist*> playlists, std::vector<Song*> favorites)
{
    std::cout << BOLD << ITALIC << BLUE << "PLAYLISTS" << RESET << std::endl;

    for(int i = 0; i < playlists.size(); i++)
    {
        std::cout << YELLOW << i << ". " << playlists[i]->getName() << RESET << std::endl;
        std::vector<Song*> this_playlist_songs = playlists[i]->getSongs();
        for(int j = 0; j < this_playlist_songs.size(); j++)
        {
            std::cout << GREEN << "    " << j << ". " << this_playlist_songs[j]->getTitle() << RESET;
            if (std::find(favorites.begin(), favorites.end(), this_playlist_songs[j]) != favorites.end())
                std::cout << RED << " ♥ " << RESET;
            std::cout << std::endl;
        }
    }
}

void UIRender::printSearchItems()
{
    std::cout << BGREEN
              << "1. search by title" << std::endl
              << "2. search by artist" << std::endl
              << "3. search by album" << std::endl
              << "4. search by genre" << std::endl
              << "5. search by year" << std::endl
              << "6. search by duration" << std::endl
              << "0. EXIT" << std::endl
              << RESET;
}

void UIRender::printPlaybackModes()
{
    std::cout << BBLUE
              << "1. NO REPEAT" << std::endl
              << "2. REPEAT SONG" << std::endl
              << "3. REPEAT PLAYLIST" << std::endl
              << "4. SHUFFLE" << std::endl
              << RESET;    
}

void UIRender::printCurrentPlaybackMode(PlaybackMode current_playback_mode)
{
    std::cout << BRED << "PLAYBACK MODE: ";
    
    if(current_playback_mode == PlaybackMode::NO_REPEAT)
    {
        std::cout << "NO REPEAT";
    }
    else if(current_playback_mode == PlaybackMode::REPEAT_SONG)
    {
        std::cout << "REPEAT SONG";
    }
    else if(current_playback_mode == PlaybackMode::REPEAT_PLAYLIST)
    {
        std::cout << "REPEAT PLAYLIST";
    }
    else if(current_playback_mode == PlaybackMode::SHUFFLE)
    {
        std::cout << "SHUFFLE";
    }

    std::cout << std::endl << RESET;
}

void UIRender::printSortOptions()
{
    std::cout << YELLOW
              << "1. Sort by title" << std::endl
              << "2. Sort by artist" << std::endl
              << "3. Sort by album" << std::endl
              << "4. Sort by genre" << std::endl
              << "5. Sort by year" << std::endl
              << "6. Sort by duration" << std::endl
              << "0. Exit" << std::endl
              << RESET;
}

