#include "M3uLoader.h"

#include <filesystem>
#include <fstream>

#include "Song.h"
#include "Playlist.h"
#include "MusicLibrary.h"

std::vector<Song*> M3uLoader::loadAPlaylist(const std::string& file_path)
{
    std::vector<Song*> this_playlist_songs;

    std::ifstream file(file_path);

    if (!file.is_open())
        return this_playlist_songs;

    std::string song_path;
    while (std::getline(file, song_path))
    {
        if (song_path.empty())
            continue;

        while (!song_path.empty() && song_path.back() == '\r')
            song_path.pop_back();

        Song* new_song = library.filterByFilePath(song_path);
        this_playlist_songs.push_back(new_song);
    }

    file.close();

    return this_playlist_songs;
}

std::vector<Playlist*> M3uLoader::loadPlaylists(const std::string& folder_path)
{
    std::vector<Playlist*> playlists;

    if (!std::filesystem::exists(folder_path))
        return playlists;

    for (const auto& entry : std::filesystem::directory_iterator(folder_path))
    {
        if (!entry.is_regular_file())
            continue;

        if (entry.path().extension() == ".m3u")
        {
            std::string file_path = entry.path().string();
            std::string playlist_name = entry.path().stem().string();
            std::vector<Song*> songs = loadAPlaylist(file_path);

            Playlist* new_playlist = new Playlist(playlist_name, songs);

            playlists.push_back(new_playlist);
        }
    }
    return playlists;
}

