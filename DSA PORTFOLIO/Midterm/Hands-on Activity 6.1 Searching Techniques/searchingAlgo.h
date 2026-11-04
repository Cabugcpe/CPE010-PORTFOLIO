#include "node.h"

#ifndef SEARCHINGALGO_H
#define SEARCHINGALGO_H

// Procedure:

template <typename T>
void linearSearchArr(int arrSize, T dataFind, T list[]){
	
	
	for(int i = 0; i < arrSize; i++){
		if(dataFind == list[i]){
			// Print "Searching is successful"
			std::cout << "Searching is successful\n";
			return;
		}
	}
	
	
	std::cout << "Searching is unsuccessful\n";
}

template <typename T>
void linearSearchLL(Node<T>* head, T dataFind){
	while(head != nullptr){
		if(head->data == dataFind){
			std::cout << "Searching is successful\n";
			return;
		}
		head = head->next;
	}
	std:: cout << "Searching is unsuccessful\n";
}

template <typename T>
Node<T>* getMiddle(Node<T>* start, Node<T>* last){
	Node<T>* slow = start;
	Node<T>* fast = start;
	
	while(fast != last && fast->next != last){

		slow = slow->next;
	
		fast = fast->next->next;
	}
	return slow;
}

template <typename T>
void binarySearchLL(Node<T>* start, T dataFind){
	
	
	Node<T>* last = nullptr;
	
	
	while(start != last){
		
	
	Node<T>* middle = getMiddle(start, last);
		
	
	if(middle->data == dataFind){
		std::cout << "Searching is successful\n";
		return;
	}
		
	
	else if(middle->data > dataFind){
		last = middle;
	}
		
	
	else{
		start = middle->next;
	}
}
	
	std::cout << "Searching is unsuccessful\n";
}

template <typename T>
void binarySearchArr(int arrSize, T dataFind, T list[]){
	
	int low = 0, up = arrSize-1, middle;
	
	
	while(low <= up){
		
		
		middle = (int)((low+up)/2);
		
		
		if(dataFind == list[middle]){
			std::cout << "Search element is found!\n";
			return;
		}
		
		
		else if(dataFind < list[middle]){
		up = middle-1;
		}
		else{
			
			low = middle + 1;
		}
	}
	std::cout << "Search element is not found! \n";
}

// Supplementary Task:

template <typename T>
int lSLLCount(Node<T>* head, T dataFind){
	int comp = 0;
	
	while(head != nullptr){
		comp++;
		
		if(head->data == dataFind){
			return comp;
		}
		
		head = head->next;
	}
	
	return comp;
}

template <typename T>
int bSRecursive(int low, int up, T dataFind, T list[]){
	
	
	if(low > up){
		return 0;
	}
	int middle = (low + up) / 2;
	
	
	if(dataFind == list[middle]){
		return 1;
	}
	
	
	else if(dataFind < list[middle]){
		return bSRecursive(low, middle - 1, dataFind, list);
	}
	
	else{
		// Search right
		return bSRecursive(middle + 1, up, dataFind, list);
	}
}
#endif
