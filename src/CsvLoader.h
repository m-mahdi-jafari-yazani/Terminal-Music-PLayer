#pragma once

#include <vector>

#include "Song.h"

class CsvLoader
{
private:
    Song* convertLineToSong(const std::string& line);
public:
    std::vector<Song*> loadSongsFromCsv(const std::string& path);
};

