#include <iostream>
#include <vector>
#include <chrono>
#include "sorting.h"

int main() {
    int sizes[] = {100, 1000, 10000};

    std::cout << "SORTING ALGORITHM ANALYSIS\n";
    std::cout << "Time is measured in microseconds (us).\n\n";

    for (int n : sizes) {
        std::vector<int> sorted(n);
        std::vector<int> reversed(n);

        for (int i = 0; i < n; i++) {
            sorted[i] = i + 1;
            reversed[i] = n - i;
        }

        std::cout << "Input Size: " << n << '\n';

        // Bubble Sort Best Case
        std::vector<int> A = sorted;

        auto start = std::chrono::steady_clock::now();
        bubbleSort(A);
        auto end = std::chrono::steady_clock::now();

        std::cout << "Bubble Sort Best Case: "
                  << std::chrono::duration<double, std::micro>(
                         end - start).count()
                  << " us\n";

        // Bubble Sort Worst Case
        A = reversed;

        start = std::chrono::steady_clock::now();
        bubbleSort(A);
        end = std::chrono::steady_clock::now();

        std::cout << "Bubble Sort Worst Case: "
                  << std::chrono::duration<double, std::micro>(
                         end - start).count()
                  << " us\n";

        // Insertion Sort Best Case
        A = sorted;

        start = std::chrono::steady_clock::now();
        insertionSort(A);
        end = std::chrono::steady_clock::now();

        std::cout << "Insertion Sort Best Case: "
                  << std::chrono::duration<double, std::micro>(
                         end - start).count()
                  << " us\n";

        // Insertion Sort Worst Case
        A = reversed;

        start = std::chrono::steady_clock::now();
        insertionSort(A);
        end = std::chrono::steady_clock::now();

        std::cout << "Insertion Sort Worst Case: "
                  << std::chrono::duration<double, std::micro>(
                         end - start).count()
                  << " us\n\n";
    }

    return 0;
}
