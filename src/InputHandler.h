#pragma once

#include <string>

class InputHandler
{
private:

public:
    int selectMainMenuOption();
    void selectSong(int& which_playlist, int& which_song);
    int selectPlaylist();

    std::string takeTitle();
    std::string takeArtist();
    std::string takeAlbum();
    std::string takeGenre();
    void takeYear(int& minimum, int& maximum); 
    void takeDuration(int& minimum, int& maximum);

    int search();

    int takePlaybackMode();

    int takeANewFavorte();

    int takeSortOption();
};