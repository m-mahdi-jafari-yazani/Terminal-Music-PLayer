#include "MusicLibrary.h"

#include <vector>

#include "CsvLoader.h"

MusicLibrary::MusicLibrary()
{
    CsvLoader songs_loader;
    songs = songs_loader.loadSongsFromCsv("../Data/library.csv");
}
MusicLibrary::~MusicLibrary()
{
    for(int i = 0; i < songs.size(); i++)
        delete songs[i];
}
////////////////////////////////////////////////////////////////////////////////////////////////////100
std::vector<Song*> MusicLibrary::filterByTitle(std::string title)
{
    std::vector<Song*> filtered_songs;

    for(int i = 0; i < songs.size(); i++)
        if(songs[i]->getTitle() == title)
            filtered_songs.push_back(songs[i]);

    return filtered_songs;

}
std::vector<Song*> MusicLibrary::filterByArtist(std::string artist)
{
    std::vector<Song*> filtered_songs;

    for(int i = 0; i < songs.size(); i++)
        if(songs[i]->getArtist() == artist)
            filtered_songs.push_back(songs[i]);

    return filtered_songs;
}
std::vector<Song*> MusicLibrary::filterByAlbum(std::string album)
{
    std::vector<Song*> filtered_songs;

    for(int i = 0; i < songs.size(); i++)
        if(songs[i]->getAlbum() == album)
            filtered_songs.push_back(songs[i]);

    return filtered_songs;
}
std::vector<Song*> MusicLibrary::filterByGenre(std::string genre)
{
    std::vector<Song*> filtered_songs;

    for(int i = 0; i < songs.size(); i++)
        if(songs[i]->getGenre() == genre)
            filtered_songs.push_back(songs[i]);

    return filtered_songs;
}
std::vector<Song*> MusicLibrary::filterByYear(int minimum, int maximum)
{
    std::vector<Song*> filtered_songs;

    for(int i = 0; i < songs.size(); i++)
        if(minimum <= songs[i]->getYear() && songs[i]->getYear() <= maximum)
            filtered_songs.push_back(songs[i]);

    return filtered_songs;
}
std::vector<Song*> MusicLibrary::filterByDuration(int minimum, int maximum)
{
    std::vector<Song*> filtered_songs;

    for(int i = 0; i < songs.size(); i++)
        if(minimum <= songs[i]->getDuration() && songs[i]->getDuration() <= maximum)
            filtered_songs.push_back(songs[i]);

    return filtered_songs;
}
Song* MusicLibrary::filterByFilePath(std::string file_path)
{
    for(int i = 0; i < songs.size(); i++)
        if(songs[i]->getFilePath() == file_path)
            return songs[i];

    return nullptr;
}


