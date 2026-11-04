#ifndef SEARCHINGALGO_H
#define SEARCHINGALGO_H

int linearSearch(const std::vector<int>& A, int key) {
    for (int i = 0; i < static_cast<int>(A.size()); i++) {
        if (A[i] == key) {
            return i;
        }
    }

    return -1;
}

int binarySearch(const std::vector<int>& A, int key) {
    int low = 0;
    int high = static_cast<int>(A.size()) - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (A[mid] == key) {
            return mid;
        } else if (A[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

template <typename SearchFunction>
double measureSearch(SearchFunction searchFunction,
                     const std::vector<int>& A,
                     int key,
                     int repetitions) {
    int result = -1;

    auto start = std::chrono::steady_clock::now();

    for (int i = 0; i < repetitions; i++) {
        result = searchFunction(A, key);
    }

    auto end = std::chrono::steady_clock::now();

    // Use the result so the search result is checked.
    if (result != -1) {
        std::cout << "Key found at index: " << result << '\n';
    }

    double totalTime = std::chrono::duration<double,
        std::micro>(end - start).count();

    return totalTime / repetitions;
}

#endif