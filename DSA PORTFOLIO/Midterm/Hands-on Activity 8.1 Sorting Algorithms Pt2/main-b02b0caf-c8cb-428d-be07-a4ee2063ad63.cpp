#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sorting.h"

int main() {

    // Array with 100 elements
    const int SIZE = 100;
    int unsortedArr[SIZE];

    // Generate random values
    srand(time(0));
    for (int i = 0; i < SIZE; i++) {
        unsortedArr[i] = rand() % 100 + 1;
    }
    // Unsorted Array
    std::cout << "Unsorted Array:" << std::endl;
    display(unsortedArr, SIZE);

    // Shell Sort
    std::cout << "\nShell Sort:" << std::endl;
    int shellArr[SIZE];
    // Copy the original unsorted array
    for (int i = 0; i < SIZE; i++) {
        shellArr[i] = unsortedArr[i];
    }
    shellsort(shellArr, SIZE);
    display(shellArr, SIZE);

    // Merge Sort
    std::cout << "\nMerge Sort:" << std::endl;
    int mergeArr[SIZE];
    // Copy the original unsorted array
    for (int i = 0; i < SIZE; i++) {
        mergeArr[i] = unsortedArr[i];
    }
    mergesort(mergeArr, 0, SIZE - 1);
    display(mergeArr, SIZE);

    // Quick Sort
    std::cout << "\nQuick Sort:" << std::endl;
    int quickArr[SIZE];
    // Copy the original unsorted array
    for (int i = 0; i < SIZE; i++) {
        quickArr[i] = unsortedArr[i];
    }
    quicksort(quickArr, 0, SIZE - 1);
    display(quickArr, SIZE);

    return 0;
}

