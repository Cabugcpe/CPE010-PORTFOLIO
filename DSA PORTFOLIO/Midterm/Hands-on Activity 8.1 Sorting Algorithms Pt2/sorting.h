#ifndef SORTING_H
#define SORTING_H
#include <iostream>
#include <utility>

// DISPLAY ARRAY
template <typename T>
void display(T arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// SHELL SORT
template <typename T>
void shellsort(T arr[], int size) {
    for (int interval = size / 2; interval > 0; interval /= 2) {

        for (int i = interval; i < size; i++) {

            T temp = arr[i];
            int j;

            for (j = i; j >= interval && arr[j - interval] > temp; j -= interval) {
                arr[j] = arr[j - interval];
            }

            arr[j] = temp;
        }
    }
}

// MERGE SORT
template <typename T>
void merge(T arr[], int left, int middle, int right) {

    int n1 = middle - left + 1;
    int n2 = right - middle;

    T* L = new T[n1];
    T* R = new T[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[middle + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {

        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }

        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

template <typename T>
void mergesort(T arr[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        // Sort first half
        mergesort(arr, left, middle);
        // Sort second half
        mergesort(arr, middle + 1, right);
        // Merge both halves
        merge(arr, left, middle, right);
    }
}

// QUICK SORT
template <typename T>
int partition(T arr[], int low, int high) {
    T pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);

    return i + 1;
}

template <typename T>
void quicksort(T arr[], int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        // Sort elements before pivot
        quicksort(arr, low, pivot - 1);
        // Sort elements after pivot
        quicksort(arr, pivot + 1, high);
    }
}

#endif
