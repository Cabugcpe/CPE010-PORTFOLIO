#ifndef DOUBLE_LL_H
#define DOUBLE_LL_H
#include <iostream>

template <typename T>
class doubleList {
public:
    T data;
    doubleList<T>* next;
    doubleList<T>* prev;
};

// Create Node
template <typename T>
doubleList<T>* newNode(const T& newData) {
    doubleList<T>* temp = new doubleList<T>;

    temp->data = newData;

    // Circular pointers
    temp->next = temp;
    temp->prev = temp;

    return temp;
}

// Insert at End
template <typename T>
void insertSong(doubleList<T>** head, const T& newData) {

    doubleList<T>* temp = newNode(newData);

    // Empty playlist
    if (*head == nullptr) {
        *head = temp;
        return;
    }

    doubleList<T>* last = (*head)->prev;

    temp->next = *head;
    temp->prev = last;

    last->next = temp;
    (*head)->prev = temp;
}

// Delete Song
template <typename T>
void deleteSong(doubleList<T>** head, T value) {

    if (*head == nullptr)
        return;

    doubleList<T>* current = *head;

    do {

        if (current->data == value) {

            // Only one node
            if (current->next == current) {
                delete current;
                *head = nullptr;
                return;
            }

            current->prev->next = current->next;
            current->next->prev = current->prev;

            if (current == *head)
                *head = current->next;

            delete current;
            return;
        }

        current = current->next;

    } while (current != *head);
}

// Play Playlist
template <typename T>
void playPlaylist(doubleList<T>* head) {

    if (head == nullptr) {
        std::cout << "Playlist is empty.\n";
        return;
    }

    doubleList<T>* current = head;

    std::cout << "\nSongs in Playlist\n";

    do {

        std::cout << current->data << std::endl;
        current = current->next;

    } while (current != head);
}

// Next Song
template <typename T>
void nextSong(doubleList<T>** current) {

    if (*current != nullptr)
        *current = (*current)->next;
}

// Previous Song
template <typename T>
void previousSong(doubleList<T>** current) {

    if (*current != nullptr)
        *current = (*current)->prev;
}

#endif
