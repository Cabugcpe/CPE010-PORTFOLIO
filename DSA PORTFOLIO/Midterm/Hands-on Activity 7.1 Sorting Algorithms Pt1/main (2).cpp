#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sorting.h"

int main() {
    // array with 100 size
    const int SIZE = 100;
    int unsortedArr[SIZE];

    // Random Values
    std::srand(std::time(0));

    // Generate 100 random values
    for (int i = 0; i < SIZE; i++) {
        unsortedArr[i] = std::rand() % 100 + 1;
    }

    // Display all elements
    std::cout << "Unsorted Array: "<<std::endl;
    display(unsortedArr, SIZE);

    std::cout << "Bubble sort: "<<std::endl;
    bubblesort(unsortedArr, SIZE);
    display(unsortedArr, SIZE);

    std::cout << "Routine smallest: "<<std::endl;
    routine_smallest(unsortedArr, 0 , SIZE);
    display(unsortedArr, SIZE);

    std::cout << "Selection sort: "<<std::endl;
    bubblesort(unsortedArr, SIZE);
    display(unsortedArr, SIZE);

    std::cout << "Insertion sort: "<<std::endl;
    insertionsort(unsortedArr, SIZE);
    display(unsortedArr, SIZE);

    return 0;
}