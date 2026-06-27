#include "InputHandler.h"

#include <iostream>
#include <string>

#include "Colors.h"

int InputHandler::selectMainMenuOption()
{
    int option;
    std::cout << "select option: ";
    std::cin >> option;
    return option;
}

void InputHandler::selectSong(int& which_playlist, int& which_song)
{
    std::cout << "Select Your Song:" << std::endl;

    std::cout << "which playlist: ";
    std::cin >> which_playlist;

    std::cout << "which song: ";
    std::cin >> which_song;
}

int InputHandler::selectPlaylist()
{
    std::cout << "Select Your Playlist" << std::endl;

    int which_playlist;

    std::cout << "which playlist: ";
    std::cin >> which_playlist;

    return which_playlist;
}

std::string InputHandler::takeTitle()
{
    std::string title;
    std::cout << "enter the title: ";
    std::cin >> title;
    return title;
}
std::string InputHandler::takeArtist()
{
    std::string artist;
    std::cout << "enter the artist: ";
    std::cin >> artist;
    return artist;
}
std::string InputHandler::takeAlbum()
{
    std::string album;
    std::cout << "enter the album: ";
    std::cin >> album;
    return album;
}
std::string InputHandler::takeGenre()
{
    std::string genre;
    std::cout << "enter the genre: ";
    std::cin >> genre;
    return genre;
}
void InputHandler::takeYear(int& minimum, int& maximum)
{
    std::cout << "enter the minimum year: "; 
    std::cin >> minimum;
    std::cout << "enter the maximum year: "; 
    std::cin >> maximum;
}
void InputHandler::takeDuration(int& minimum, int& maximum)
{
    std::cout << "enter the minimum duration: "; 
    std::cin >> minimum;
    std::cout << "enter the maximum duration: "; 
    std::cin >> maximum;
}

int InputHandler::search()
{
    int search_by;
    std::cout << "search with which item: ";
    std::cin >> search_by;
    return search_by;
}

int InputHandler::takePlaybackMode()
{
    int which_playback_mode;
    std::cout << "which playback mode: ";
    std::cin >> which_playback_mode;
    return which_playback_mode;
}

int InputHandler::takeANewFavorte()
{
    int which_song;
    std::cout << "Which song do you want to add to your favorites? ";
    std::cin >> which_song;
    return which_song;
}

int InputHandler::takeSortOption()
{
    int which_option;
    std::cout << "Sort whith which item? ";
    std::cin >> which_option;
    return which_option;
}

