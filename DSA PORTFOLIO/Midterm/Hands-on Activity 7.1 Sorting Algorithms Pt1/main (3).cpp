#include <iostream>
#include <cstdlib>
#include <ctime>
#include "insertionsort.h"

int main() {
    const int SIZE = 100;
    int A[SIZE];
    int count[6] = {0};

    // GENERATES 100 RANDOM VOTES
    std::srand(std::time(0));

    for (int i = 0; i < SIZE; i++) {
        A[i] = std::rand() % 5 + 1;
    }

    // UNSORTED ARRAY
    std::cout << "Unsorted: " << std::endl;

    for (int i = 0; i < SIZE; i++) {
        std::cout << A[i] << " ";

        if ((i + 1) % 20 == 0)
            std::cout << std::endl;
    }

    // INSERTION SORT
    insertionsort(A, SIZE);

    // SORTED ARRAY
    std::cout << "\nSorted: " << std::endl;

    for (int i = 0; i < SIZE; i++) {
        std::cout << A[i] << " ";

        if ((i + 1) % 20 == 0)
            std::cout << std::endl;
    }

    // MANUAL COUNT VOTING RESULT
    int manualCount[6] = {0};

    for (int i = 0; i < SIZE; i++) {
        manualCount[A[i]]++;
    }

    std::cout << "\nManual Count: " << std::endl;

    for (int i = 1; i <= 5; i++) {
        std::cout << "Vote " << i << ": "
                  << manualCount[i] << std::endl;
    }

    // COUNTING VOTING RESULT
    for (int i = 0; i < SIZE; i++) {
        count[A[i]]++;
    }

    // WINNER RESULT
    int winner = 1;

    for (int i = 2; i <= 5; i++) {
        if (count[i] > count[winner]) {
            winner = i;
        }
    }

    std::cout << "\nCANDIDATE VOTING RESULTS:" << std::endl;

    std::cout << "Candidate 1 - Bo Dalton Capistrano: "
              << count[1] << " votes" << std::endl;

    std::cout << "Candidate 2 - Cornelius Raymon Agustin: "
              << count[2] << " votes" << std::endl;

    std::cout << "Candidate 3 - Deja Jayla Banaga: "
              << count[3] << " votes" << std::endl;

    std::cout << "Candidate 4 - Lalla Brielle Yabut: "
              << count[4] << " votes" << std::endl;

    std::cout << "Candidate 5 - Franklin Relano Castro: "
              << count[5] << " votes" << std::endl;

    std::cout << "The winner is ";

    switch (winner) {
        case 1:
            std::cout << "Bo Dalton Capistrano";
            break;

        case 2:
            std::cout << "Cornelius Raymon Agustín";
            break;

        case 3:
            std::cout << "Deja Jayla Bañaga";
            break;

        case 4:
            std::cout << "Lalla Brielle Yabut";
            break;

        case 5:
            std::cout << "Franklin Relano Castro";
            break;
    }

    std::cout << " With " << count[winner] << " votes!" << std::endl;

    return 0;
}