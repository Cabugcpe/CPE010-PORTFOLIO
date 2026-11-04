#include <iostream>
#include <chrono>

// Regular recursive power: O(n)
long long rpower(long long x, int n, long long& operations) {
    if (n == 0) {
        return 1;
    }

    operations++;

    return x * rpower(x, n - 1, operations);
}

// Improved recursive power: O(log n)
long long brpower(long long x, int n, long long& operations) {
    if (n == 0) {
        return 1;
    }

    long long y = brpower(x, n / 2, operations);

    if (n % 2 == 1) {
        operations += 2;
        return x * y * y;
    }

    operations++;

    return y * y;
}

int main() {
    int exponents[] = {100, 500, 1000, 2000, 4000};
    int numberOfExponents =
        sizeof(exponents) / sizeof(exponents[0]);

    std::cout << "PROBLEM 2: POWER ALGORITHMS\n\n";
    std::cout << "Exponent\tAlgorithm\tOperations\tRuntime (us)\n";

    for (int i = 0; i < numberOfExponents; i++) {
        int n = exponents[i];

        long long regularOperations = 0;
        long long improvedOperations = 0;

        // Measure regular recursive power
        auto start1 = std::chrono::steady_clock::now();

        long long result1 = rpower(1, n, regularOperations);

        auto stop1 = std::chrono::steady_clock::now();

        auto time1 =
            std::chrono::duration_cast<
                std::chrono::microseconds
            >(stop1 - start1).count();

        // Measure improved recursive power
        auto start2 = std::chrono::steady_clock::now();

        long long result2 = brpower(1, n, improvedOperations);

        auto stop2 = std::chrono::steady_clock::now();

        auto time2 =
            std::chrono::duration_cast<
                std::chrono::microseconds
            >(stop2 - start2).count();

        // Display results
        std::cout << n << "\t\t"
                  << "rpower\t\t"
                  << regularOperations << "\t\t"
                  << time1 << '\n';

        std::cout << n << "\t\t"
                  << "brpower\t\t"
                  << improvedOperations << "\t\t"
                  << time2 << '\n';

        // Verify both algorithms
        if (result1 != result2) {
            std::cout << "Error: Results do not match!\n";
        }

        std::cout << '\n';
    }

    return 0;
}