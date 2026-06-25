#pragma once

#include "Song.h"

#include <vector>


class MusicLibrary
{
private:
    std::vector<Song*> songs;

public:
    MusicLibrary();
    ~MusicLibrary();
    
    int size() { return songs.size(); }
    Song* getSong(int index) { return songs[index]; }
    std::vector<Song*> getAllSongs() { return songs; }
       
    std::vector<Song*> filterByTitle(std::string title);
    std::vector<Song*> filterByArtist(std::string artist);
    std::vector<Song*> filterByAlbum(std::string album);
    std::vector<Song*> filterByGenre(std::string genre);
    std::vector<Song*> filterByYear(int minimum, int maximum);
    std::vector<Song*> filterByDuration(int minimum, int maximum);
    Song* filterByFilePath(std::string file_path);
};
