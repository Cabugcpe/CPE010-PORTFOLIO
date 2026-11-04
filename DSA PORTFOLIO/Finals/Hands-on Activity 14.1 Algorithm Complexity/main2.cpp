
#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
#include "searchingAlgo.h"

int main() {
    int sizes[] = {1000, 10000, 100000};
    const int repetitions = 1000;

    std::cout << "SEARCHING ALGORITHM ANALYSIS\n";
    std::cout << "Average time per search in microseconds (us).\n\n";

    std::cout << std::fixed << std::setprecision(6);

    for (int n : sizes) {
        std::vector<int> A(n);

        for (int i = 0; i < n; i++) {
            A[i] = i + 1;
        }

        // Zero is not in the array.
        int key = 0;

        double binaryTime = measureSearch(
            binarySearch, A, key, repetitions);

        double linearTime = measureSearch(
            linearSearch, A, key, repetitions);

        std::cout << "Input Size: " << n << '\n';
        std::cout << "Binary Search: "
                  << binaryTime << " us\n";
        std::cout << "Linear Search: "
                  << linearTime << " us\n\n";
    }

    return 0;
}
