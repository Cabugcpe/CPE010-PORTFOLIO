#include <iostream>
#include <thread>

const int SIZE = 12;
int numbers[SIZE] = {
    18, 7, 29, 14, 3, 27,
    11, 6, 20, 9, 16, 4
};

const int target = 27;
int result = -1;

void linearSearch(int start, int end) {
    for (int i = start; i < end; i++) {
        if (numbers[i] == target) {
            result = i;
            return;
        }
    }
}

int main() {
    std::thread T1(linearSearch, 0, 4);
    std::thread T2(linearSearch, 4, 8);
    std::thread T3(linearSearch, 8, 12);

    T1.join();
    T2.join();
    T3.join();

    if (result != -1) {
        std::cout << "Target found: " << target << std::endl;
        std::cout << "Index: " << result << std::endl;
    } else {
        std::cout << "Target not found." << std::endl;
    }

    return 0;
}
