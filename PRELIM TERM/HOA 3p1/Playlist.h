#ifndef UNTITLED1_PLAYLIST_H
#define UNTITLED1_PLAYLIST_H

#include <iostream>
#include <ostream>
#include <string>

//==========================
//Doubly linked list node allocation, with the title and the composer
//==========================
class SongNode{
    public:
    std::string songTitle;
    std::string songComposer;
    SongNode* next = nullptr;
    SongNode* prev = nullptr;
};
//===========================
// creation of the connection of the lists to the prev and to the next
//===========================
SongNode* createSongNode(std::string title, std::string composer) {
    SongNode* node = new SongNode();
    node->songTitle = title;
    node->songComposer = composer;
    node->next = node;
    node->prev = node;
    return node;
}
//====================
//inserting a new song at the front of the playlist,
//====================
void insSongAtHead(std::string title, std::string composer, SongNode** head) {
    SongNode* node = createSongNode(title, composer);

    if (*head == nullptr) {
        *head = node;
        return;
    }
    SongNode* tail = (*head)->prev;
    node->next = *head;
    node->prev = tail;
    tail->next = node;
    (*head)->prev = node;
    *head = node;
}

//======================
//end insert
//=====================
void insSongAtEnd(std::string title, std::string composer, SongNode** head) {
    SongNode* node = createSongNode(title, composer);
    if (*head == nullptr) {
        *head = node;
        return;
    }
    SongNode* tail = (*head)->prev;
    tail->next = node;
    node->prev = tail;
    node->next = *head;
    (*head)->prev = node;
}

//==================
//song search
//==================
SongNode* findSong(std::string title, SongNode* head) {
    if (head == nullptr) return nullptr;

    SongNode* current = head;
    do {
        if (current->songTitle == title) {
            return current;
        }
        current = current->next;
    } while (current != head);
    return nullptr;
}
//=============
//Insert song middle(like the general insert yeah)
//==============
void insSongBet(std::string titleToIns, std::string newTitle, std::string newComposer, SongNode** head) {
    SongNode* refNode = findSong(titleToIns, *head);

    if (refNode == nullptr) {
        std::cout << titleToIns << " was not found in the playlist" << std::endl;
        return;
    }
    SongNode* node = createSongNode(newTitle, newComposer);
    node->next = refNode->next;
    node->prev = refNode;
    refNode->next->prev = node;
    refNode->next = node;
}

//================
//song removal
//================
void songRemv(std::string titleToRemv, SongNode** head) {
    if (*head == nullptr) {
        std::cout << "Nothing to remove" << std::endl;
        return;
    }
    SongNode* current = *head;

    if (current->next == current) {
        if (current->songTitle == titleToRemv) {
            delete current;
            *head = nullptr;
            std::cout << titleToRemv << " was removed" << std::endl;
        } else {
            std::cout << titleToRemv << " was not found in the playlist" << std::endl;
        }
        return;
    }
    do {
        if (current->songTitle == titleToRemv) {
            current->prev->next = current->next;
            current->next->prev = current->prev;

            if (current == *head) {
                *head = current->next;
            }
            delete current;
            std::cout << titleToRemv << " was removed from the playlist" << std::endl;
            return;
        }
        current = current->next;
    } while (current != *head);

    std::cout << titleToRemv << " was not found in the Playlist" << std::endl;
}

//================
//Print all songs in the list
//================
void playAll(SongNode* head) {
    if (head == nullptr) {
        std::cout << "The playlist is empty" << std::endl;
        return;
    }
    std::cout << "Now Playing Playlist" << std::endl;
    SongNode* current = head;
    int tracknumb = 1;
    do {
        std::cout << tracknumb << " " << current->songTitle << "-" << current->songComposer << std::endl;
        current = current->next;
        tracknumb++;
    } while (current != head);
}

//==============================
//song playback control? next, prev
//==============================
SongNode* nextSong(SongNode* currentSong) {
    if (currentSong == nullptr) return nullptr;
    return currentSong->next;
}
SongNode* prevSong(SongNode* currentSong) {
    if (currentSong == nullptr) return nullptr;
    return currentSong->prev;
}
void printCurSong(SongNode* currentSong) {
    if (currentSong == nullptr) {
        std::cout << "Nothing to print" << std::endl;
        return;
    }
    std::cout << "Now playing: " << currentSong->songTitle << "-" << currentSong->songComposer << std::endl;
}

//=====================
//clearing/cleaning
//=====================
void clearPlay(SongNode** head) {
    if (*head == nullptr) return;

    SongNode* tail = (*head)->prev;
    tail->next = nullptr;

    SongNode* current = *head;
    while (current != nullptr) {
        SongNode* temp = current;
        current = current->next;
        delete temp;
    }
    *head = nullptr;
}

#endif //UNTITLED1_PLAYLIST_H