#include "Song.h"

Song::Song(std::string title_,
           std::string artist_,
           std::string album_,
           std::string genre_,
           int year_,
           int duration_,
           std::string file_path_)
           : title(title_),
             artist(artist_),
             album(album_),
             genre(genre_),
             year(year_),
             duration(duration_),
             file_path(file_path_) {}