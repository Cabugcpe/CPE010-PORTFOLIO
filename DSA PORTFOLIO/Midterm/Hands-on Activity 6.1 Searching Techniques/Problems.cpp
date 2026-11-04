#include <iostream>
#include <cstdlib>
#include <time.h>
#include "node.h"
#include "searchingAlgo.h"

const int max_size = 10;

int main (){
	
	// Problem 1
	int dataset[max_size] = {12, 5, 23, 7, 16, 2, 19, 10, 4, 21};

	// Search for 18
	int comp = 0;	
	for(int i = 0; i < max_size; i++){
		comp++;
		
		if(dataset[i] == 10){
			break;
		}
	}
	std::cout << "Comparisons using Array: " << comp << "\n";
	
	// Create linked list
	Node<int>* int1 = new_node(12);
	Node<int>* int2 = new_node(5);
	Node<int>* int3 = new_node(23);
	Node<int>* int4 = new_node(7);
	Node<int>* int5 = new_node(16);
	Node<int>* int6 = new_node(2);
	Node<int>* int7 = new_node(19);
	Node<int>* int8 = new_node(10);
	Node<int>* int9 = new_node(4);
	Node<int>* int10 = new_node(21);
	
	int1->next = int2;
	int2->next = int3;
	int3->next = int4;
	int4->next = int5;
	int5->next = int6;
	int6->next = int7;
	int7->next = int8;
	int8->next = int9;
	int9->next = int10;
	
	std::cout << "Comparisons using LL: ";
	std::cout << lSLLCount(int1, 10) << "\n\n";	
	
	// Problem 2
	int count = 0;
	
	for(int i = 0; i < max_size; i++){
		if(dataset[i] == 21){
			count++;
		}
	}
	std::cout << "Array occurrences of 21: " << count << std::endl;
	
	count = 0;
	Node<int>* current = int1;
	
	while(current != NULL){
		if(current->data == 21){
			count++;
		}	
		current = current->next;
	}	
	std::cout << "Linked List occurrences of 21: " << count << "\n\n";
	
	// Problem 3
	int sorted[max_size] = {2, 4, 6, 9, 11, 13, 15, 17, 20, 24};
	std::cout << "Sorted Array: ";	
	for(int i = 0; i < max_size; i++){
		std::cout << sorted[i] << " ";
	}	
	std::cout << std::endl;
	
	// Binary Search for 13
	int low = 0; int up = max_size - 1; int middle; int counter = 1;
	while(low <= up){
		
		// Compute middle
		middle = (int)((low + up) / 2);
		
		std::cout << "Repetition " << counter << std::endl;

		if(13 == sorted[middle]){
			std::cout << "Search element is found\n";
			break;
		}
		
		else if(13 < sorted[middle]){
			up = middle - 1;
		}
		
		else{

			low = middle + 1;
		}
		counter++;
	}
	std::cout << std::endl;
	
	// Problem 4
	
	if(bSRecursive(0, max_size - 1, 13, sorted)){
		std::cout << "Search element is found\n";
	}
	else{
		std::cout << "Search element is not found\n";
	}
	
	return 0;
}
