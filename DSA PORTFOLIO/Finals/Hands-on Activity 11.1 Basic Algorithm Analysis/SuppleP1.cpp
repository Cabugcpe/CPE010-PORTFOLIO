
#include <iostream>
#include <chrono>

// Algorithm to check if array elements are unique
bool Unique(const int A[], int n, long long& comparisons) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            comparisons++;

            if (A[i] == A[j]) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    int sizes[] = {100, 500, 1000, 2000, 4000};
    int numberOfSizes = sizeof(sizes) / sizeof(sizes[0]);

    std::cout << "PROBLEM 1: UNIQUE ELEMENTS\n\n";
    std::cout << "Size\tComparisons\tResult\t\tRuntime (us)\n";

    for (int k = 0; k < numberOfSizes; k++) {
        int n = sizes[k];
        int* A = new int[n];

        // Fill the array with unique elements
        for (int i = 0; i < n; i++) {
            A[i] = i;
        }

        long long comparisons = 0;

        auto start = std::chrono::steady_clock::now();

        bool result = Unique(A, n, comparisons);

        auto stop = std::chrono::steady_clock::now();

        auto runtime =
            std::chrono::duration_cast<
                std::chrono::microseconds
            >(stop - start).count();

        std::cout << n << "\t"
                  << comparisons << "\t\t"
                  << (result ? "Unique" : "Not Unique")
                  << "\t\t" << runtime << '\n';

        delete[] A;
    }

    return 0;
}