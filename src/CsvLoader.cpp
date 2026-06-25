#include "CsvLoader.h"

#include <fstream>
#include <sstream>
#include <vector>
#include <string>

Song* CsvLoader::convertLineToSong(const std::string& line)
{
    std::stringstream ss(line);

    std::string title, artist, album, genre, yearStr, durationStr, filePath;

    if (!std::getline(ss, title, ',')) return nullptr;
    if (!std::getline(ss, artist, ',')) return nullptr;
    if (!std::getline(ss, album, ',')) return nullptr;
    if (!std::getline(ss, genre, ',')) return nullptr;
    if (!std::getline(ss, yearStr, ',')) return nullptr;
    if (!std::getline(ss, durationStr, ',')) return nullptr;
    if (!std::getline(ss, filePath, ',')) return nullptr;

    try 
    {
        int year = std::stoi(yearStr);
        int duration = std::stoi(durationStr);

        return new Song(title, artist, album, genre, year, duration, filePath);
    }
    catch (...)
    {
        return nullptr;
    }
}

std::vector<Song*> CsvLoader::loadSongsFromCsv(const std::string& path)
{
    std::vector<Song*> songs;

    std::ifstream file(path);

    if (!file.is_open())
        return songs;

    std::string line;

    while (std::getline(file, line))
    {
        if (line.empty())
            continue;

        Song* new_song = convertLineToSong(line);

        if (new_song != nullptr)
            songs.push_back(new_song);
    }

    return songs;
}

