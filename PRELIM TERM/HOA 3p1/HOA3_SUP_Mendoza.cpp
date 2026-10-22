#include <iostream>
#include "Playlist.h"
#include <string>


int main() {
    SongNode* playlist = nullptr;   // start with an empty playlist

    // A: build the playlist directly in code
    insSongAtEnd("A Thousand Years", "Cristina Perri", &playlist);
    insSongAtEnd("Heaven Knows", "Orange&Lemons", &playlist);
    insSongAtEnd("Circles", "Post Malone", &playlist);
    insSongAtEnd("Save Your Tears", "The Weeknd", &playlist);

    std::cout << "===== Initial Playlist =====" << std::endl;
    playAll(playlist);

    // B: add a song to the top
    std::cout << "\n===== Adding a song to the TOP =====" << std::endl;
    insSongAtHead("About You", "The 1975", &playlist);
    playAll(playlist);

    // C: add a song to the middle (after an existing song, found by title)
    std::cout << "\n===== Adding a song to the MIDDLE =====" << std::endl;
    insSongBet("Heaven Knows", "Multo", "Cup Of Joe", &playlist); //song in the list -> title-> composer
    playAll(playlist);

    // D: add a song to the end
    std::cout << "\n===== Adding a song to the END =====" << std::endl;
    insSongAtEnd("Lifetime (reimagined)", "Ben&Ben", &playlist);
    playAll(playlist);

    // E: remove a song << user input for a more proper removal
    std::cout << "\n===== Removing a song =====" << std::endl;
    std::string songToRemove;
    std::cout << "Enter the title of the song to remove: ";
    std::getline(std::cin, songToRemove);
    songRemv(songToRemove, &playlist);

    std::cout << "\n===== Playlist after removal =====" << std::endl;
    playAll(playlist);

    // F: step through with next/previous, like a music player's skip buttons
    std::cout << "\n===== Stepping through with next/previous =====" << std::endl;
    SongNode* currentSong = playlist;
    printCurSong(currentSong);

    std::cout << "Pressing next..." << std::endl;
    currentSong = nextSong(currentSong);
    printCurSong(currentSong);

    std::cout << "Pressing next again..." << std::endl;
    currentSong = nextSong(currentSong);
    printCurSong(currentSong);

    std::cout << "Pressing previous..." << std::endl;
    currentSong = prevSong(currentSong);
    printCurSong(currentSong);

    // G: clear the playlist and free all remaining nodes
    clearPlay(&playlist);
    std::cout << "\n===== Playlist cleared =====" << std::endl;

    return 0;
}