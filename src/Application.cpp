#include "Application.h"

#include <iostream>
#include <random>

#include "Song.h"




Application::Application()
{
    library = playlists_loader.getLibrary();
    playlists = playlists_loader.loadPlaylists("../Data/playlists");
    play_engine.setPlaylists(playlists);
}

bool Application::isValid(int current_playlist_index, int current_song_index)
{
    if(current_playlist_index < 0 || playlists.size() <= current_playlist_index)
        return false;
    
    if(current_song_index < 0 || playlists[current_playlist_index]->getSongs().size() <= current_playlist_index)
        return false;

    return true;
}

void Application::playAMusic()
{
    user_interface->clear();
    user_interface->printPlaylists(playlists, favorites);
    input_handler->selectSong(current_playlist_index, current_song_index); // pass by reference

    if(!isValid(current_playlist_index, current_song_index))
        throw std::out_of_range("Invalid index");

    int command;

    while(true)
    {
        user_interface->clear();
        user_interface->printPlaylists(playlists, favorites);
        user_interface->printSong(playlists[current_playlist_index]->getSongs()[current_song_index]);
        user_interface->printCurrentPlaybackMode(play_engine.getCurrentMode());
        user_interface->printPlayingSongOptions();

        command = play_engine.play(current_playlist_index, current_song_index);

        if(command == 0)
        {
            break;
        }
        else if(command == 1)
        {
            goPrevious();
        }
        else if(command == 2)
        {
            goNext();
        }
        else if(command == 3)
        {
            // NO_REPEAT
            goNext();
        }
        else if(command == 4)
        {
            // REPEAT_SONG
        }
        else if(command == 5)
        {
            // REPEAT_PLAYLIST
            if(current_song_index == playlists[current_playlist_index]->size() - 1)
                current_song_index = 0;
            else
                current_song_index++;
        }
        else if(command == 6)
        {
            std::random_device rd;
            std::mt19937 gen(rd());

            std::uniform_int_distribution<> dist1(0, playlists.size() - 1);
            current_playlist_index = dist1(gen);

            std::uniform_int_distribution<> dist2(0, playlists[current_playlist_index]->size() - 1);
            current_song_index = dist2(gen);
        }

    }
    user_interface->clear();
}

void Application::goPrevious()
{
    if(current_song_index == 0)
    {
        if(current_playlist_index == 0)
        {
            current_playlist_index = playlists.size() - 1;
            current_song_index = playlists[current_playlist_index]->size() - 1;
        }
        else
        {
            current_playlist_index--;
            current_song_index = playlists[current_playlist_index]->size() - 1;
        }
    }
     else
        current_song_index--;

}
void Application::goNext()
{
    if(current_song_index == playlists[current_playlist_index]->size() - 1)
    {
        if(current_playlist_index == playlists.size() - 1)
        {
            current_playlist_index = 0;
            current_song_index = 0;
        }
        else
        {
            current_playlist_index++;
            current_song_index = 0;
        }
    }
    else
    {
        current_song_index++;
    }
}

void Application::search_by_title()
{
    std::string title = input_handler->takeTitle();
    std::vector<Song*> filtered_songs = library->filterByTitle(title);
    user_interface->printSongs(filtered_songs);
}
void Application::search_by_artist()
{
    std::string artist = input_handler->takeArtist();
    std::vector<Song*> filtered_songs = library->filterByArtist(artist);
    user_interface->printSongs(filtered_songs);
}
void Application::search_by_album()
{
    std::string album = input_handler->takeAlbum();
    std::vector<Song*> filtered_songs = library->filterByAlbum(album);
    user_interface->printSongs(filtered_songs);
}
void Application::search_by_genre()
{
    std::string genre = input_handler->takeGenre();
    std::vector<Song*> filtered_songs = library->filterByGenre(genre);
    user_interface->printSongs(filtered_songs);
}
void Application::search_by_year()
{
    int min_year;
    int max_year;
    input_handler->takeYear(min_year, max_year);
    std::vector<Song*> filtered_songs = library->filterByYear(min_year, max_year);
    user_interface->printSongs(filtered_songs);
}
void Application::search_by_duration()
{
    int min_duration;
    int max_duration;
    input_handler->takeDuration(min_duration, max_duration);
    std::vector<Song*> filtered_songs = library->filterByDuration(min_duration, max_duration);
    user_interface->printSongs(filtered_songs);
}

void Application::search()
{
    user_interface->clear();

    int search_by;

    while(true)
    {
        user_interface->printSearchItems();

        search_by = input_handler->search();

        if(search_by == 1)
        {
            search_by_title();
        }
        else if(search_by == 2)
        {
            search_by_artist();
        }
        else if(search_by == 3)
        {
            search_by_album();
        }
        else if(search_by == 4)
        {
            search_by_genre();
        }
        else if(search_by == 5)
        {
            search_by_year();
        }
        else if(search_by == 6)
        {
            search_by_duration();
        }
        else if(search_by == 0)
        {
            break;
        }
        else 
        {
            user_interface->clear();
        }
    }

    user_interface->clear();
}

void Application::setPlaybackMode()
{
    user_interface->clear();
    user_interface->printPlaybackModes();

    int which_mode;
    which_mode = input_handler->takePlaybackMode();

    if(which_mode == 1)
    {
        play_engine.setCurrentMode(PlaybackMode::NO_REPEAT);
    }
    else if(which_mode == 2)
    {
        play_engine.setCurrentMode(PlaybackMode::REPEAT_SONG);
    }
    else if(which_mode == 3)
    {
        play_engine.setCurrentMode(PlaybackMode::REPEAT_PLAYLIST);
    }
    else if(which_mode == 4)
    {
        play_engine.setCurrentMode(PlaybackMode::SHUFFLE);
    }
    else
    {
        setPlaybackMode();
    }
    user_interface->clear();
}

void Application::addASongToFavorites()
{
    user_interface->clear();
    user_interface->printSongs(library->getAllSongs()); 
    int which_song = input_handler->takeANewFavorte();

    if(which_song < 0 || library->getAllSongs().size() <= which_song)
    {
        user_interface->clear();
        addASongToFavorites();
        return;
    }

    favorites.push_back(library->getAllSongs()[which_song]);
    user_interface->clear();
}

void Application::TemporarySortLibrary()
{
    user_interface->clear();

    while(true)
    {
        user_interface->printSortOptions();
        int which_option = input_handler->takeSortOption();

        if (which_option == 0)
            break;

        else if(which_option < 0 || 6 < which_option)
        {
            user_interface->clear();
            TemporarySortLibrary();
            return;
        }

        std::vector<Song*> copy_library = library->getAllSongs();


        std::sort(copy_library.begin(), copy_library.end(),
            [which_option](Song* a, Song* b)
            {
                switch (which_option)
                {
                    case 1:     return a->getTitle() < b->getTitle();
                    case 2:     return a->getArtist() < b->getArtist();
                    case 3:     return a->getAlbum() < b->getAlbum();
                    case 4:     return a->getGenre() < b->getGenre();
                    case 5:     return a->getYear() < b->getYear();
                    case 6:     return a->getDuration() < b->getDuration();
                    default:    return false;
                }
            });

        user_interface->printSongs(copy_library);
    }
    user_interface->clear();
}

void Application::run()
{   
    user_interface->clear(); 

    int command;

    while(true)
    {
        user_interface->clear();
        user_interface->printMainMenu();
        command = input_handler->selectMainMenuOption();

        label:
        if(command == 1)
        {
            try
            {
                playAMusic();
            }
            catch(std::out_of_range& e)
            {
                user_interface->clear();
                goto label;
            }
        }
        
        else if(command == 2)
            search();

        else if(command == 3)
            setPlaybackMode();
        
        else if(command == 4)
            addASongToFavorites();
        
        else if(command == 5)
            TemporarySortLibrary();

        else if(command == 0)
            return;
    }
}



