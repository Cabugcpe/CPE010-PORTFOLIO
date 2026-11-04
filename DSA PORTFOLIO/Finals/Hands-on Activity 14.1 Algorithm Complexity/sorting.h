#ifndef SORTING_H
#define SORTING_H

#include <vector>

void bubbleSort(std::vector<int>& A) {
    int n = static_cast<int>(A.size());

    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;

        for (int j = 0; j < n - i - 1; j++) {
            if (A[j] > A[j + 1]) {
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
                swapped = true;
            }
        }

        if (!swapped) {
            break;
        }
    }
}

void insertionSort(std::vector<int>& A) {
    int n = static_cast<int>(A.size());

    for (int i = 1; i < n; i++) {
        int key = A[i];
        int j = i - 1;

        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            j--;
        }

        A[j + 1] = key;
    }
}

#endif