#include <iostream>
#include <string>
#include "double_LL.h"

int main() {

    doubleList<std::string>* playlist = nullptr;

    // Create Playlist
    insertSong(&playlist, std::string("Your Call"));
    insertSong(&playlist, std::string("Vulnerable"));
    insertSong(&playlist, std::string("King for a day"));
    insertSong(&playlist, std::string("Twist"));

    std::cout << "PLAYLIST\n";
    playPlaylist(playlist);

    // Current Song
    doubleList<std::string>* current = playlist;

    std::cout << "\nCurrent Song: " << current->data << std::endl;

    nextSong(&current);
    std::cout << "Next Song: " << current->data << std::endl;

    nextSong(&current);
    std::cout << "Next Song: " << current->data << std::endl;

    previousSong(&current);
    std::cout << "Previous Song: " << current->data << std::endl;

    // Add Song
    insertSong(&playlist, std::string("Shape of You"));

    std::cout << "\nPlaylist After Adding a Song\n";
    playPlaylist(playlist);

    // Remove Song
    deleteSong(&playlist, std::string("Perfect"));

    std::cout << "\nPlaylist After Removing 'Perfect'\n";
    playPlaylist(playlist);

    return 0;
}

