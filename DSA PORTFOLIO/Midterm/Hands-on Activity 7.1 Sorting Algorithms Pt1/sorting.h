#ifndef SORTING_H
#define SORTING_H

#include <iostream>
// FUNCTION VALUES SORT
void display(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// BUBBLE SORT
template <typename T>
void bubblesort(T arr[], int SIZE) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = i +1; j < SIZE; j++){
            if (arr[i] > arr[j]){
                std::swap(arr[i], arr[j]);
             }
        }        
    }   

}

// SMALLEST
template <typename T>
int routine_smallest(T arr[], int k, int arrSize){
    int position = k;

    T smallestElement = arr[k];

    for(int j = k+1; j < arrSize; j++){
        if(arr[j] < smallestElement){
            smallestElement = arr[j];
            position = j;
        }
    }

    return position;
}

// SELECTION SORT
template <typename T>
void selectionsort(T arr[], int arrSIZE) {
    int min, temp;

    for (int i = 0; i < arrSIZE; i++) {
        min = routine_smallest(arr, i , arrSIZE);
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
            //std::swap(arr[i], arr[min]);
           
                
    }   

}

// INSERTION SORT
template <typename T>
void insertionsort(T arr[], int arrSIZE) {
    int k = 1, j;
    T temp;
    
    while(k < arrSIZE){
    temp = arr[k];
    j = k -1;
        while (j >= 0 && temp <= arr[j] ){
            arr[j+1] = arr[j];
            j--;
        }  
        arr [j+1] = temp;
        k++;
    }
}


#endif