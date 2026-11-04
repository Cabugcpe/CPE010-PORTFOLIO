#include <iostream>
#include <thread>

int total = 0;

void add(int value) {
    total += value;
}

int main() {
    std::thread T1(add, 1);
    std::thread T2(add, 2);
    std::thread T3(add, 3);

    T1.join();
    std::cout << "After T1.join(): " << total << std::endl;

    T2.join();
    std::cout << "After T2.join(): " << total << std::endl;

    T3.join();
    std::cout << "After T3.join(): " << total << std::endl;

    return 0;
}
