#pragma once

#include <string>

class Song
{
private:
    std::string title;
    std::string artist;
    std::string album;
    std::string genre;
    int year;
    int duration; // second
    std::string file_path;


public:
    Song(std::string title_,
         std::string artist_,
         std::string album_,
         std::string grnre_,
         int year_,
         int duraion_,
         std::string file_path_);

    std::string getTitle() { return title; }
    std::string getArtist() { return artist; }
    std::string getAlbum() { return album; }
    std::string getGenre() { return genre; }
    int getYear() { return year; }
    int getDuration() { return duration; }
    std::string getFilePath() const { return file_path; }
};
