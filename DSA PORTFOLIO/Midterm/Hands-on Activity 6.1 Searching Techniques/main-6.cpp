#include <iostream>
#include <cstdlib>
#include <time.h>
#include "node.h"
#include "searchingAlgo.h"

const int max_size = 50;

int main (){
	// Generate random values
	int dataset[max_size];
	srand(time(0));
	
	for(int i = 0; i < max_size; i++){
		dataset[i] = rand();
	}
	for(int i = 0; i < max_size; i++){
		std::cout << dataset[i] << " ";
	}
	std::cout << std::endl;
	
	int userInput;
	
	// Linear Search
	std::cout << "What number to search?\n";
	std::cin >> userInput;
	std::cout << "Array result LS: ";
	
	linearSearchArr(max_size, userInput, dataset);
	
	Node<char>* name1 = new_node('C');
	Node<char>* name2 = new_node('A');
	Node<char>* name3 = new_node('B');
	Node<char>* name4 = new_node('U');
	Node<char>* name5 = new_node('G');
	
	name1->next = name2;
	name2->next = name3;
	name3->next = name4;
	name4->next = name5;
	
	// Link List Linear Search
	std::cout << "Linked List Linear Search: \n";
	std::cout << "For 'J': ";
	linearSearchLL(name1, 'J');
	
	std::cout << "\n For 'A': ";
	linearSearchLL(name1, 'A');
	std::cout << std::endl;

	// Link List Binary Search
	std::cout << "Linked List Binary Search: \n";
	std::cout << "\n For 'M': ";
	binarySearchLL(name4, 'M');
	
	std::cout << "\n For 'B': ";
	binarySearchLL(name3, 'B');
	
	// Array Binary Search
	int listArrBS[5] = {6, 11, 27, 59, 82};
	
	std::cout << "\nBinary Search Array:\n";
	binarySearchArr(5, 11, listArrBS);
	binarySearchArr(5, 100, listArrBS);
	
	return 0;
}
