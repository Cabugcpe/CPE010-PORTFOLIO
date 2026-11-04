#ifndef LISTSTACK_H
#define LISTSTACK_H

//class node with data and next numbers
template <typename T>
class Node{
	public:
		T data;
		Node<T>* next = nullptr;
};

//create a pointer/ reference tip that always points to current top node

// global 
template <typename T>
Node<T>* head = nullptr;


//pushing operation:
template <typename T>
void push(T newData){
	//create a new node
	Node<T>* newNode = new Node<T>;
	// assign the data to the new node
	newNode->data = newData;
	//point the newNode next to the current top
	newNode->next = head<T>;
	// asign the new Top to the new Node
	head<T> = newNode;
}

//isEmpty()
template <typename T>
bool isEmpty(){
	return head<T> == nullptr;
}

template <typename T>
T pop(){
	//if the stack is empty error cathc:
	if(isEmpty<T>()){
		std::cout<<"Stack underflow"<<std::endl;
	}
	
	// saving a current top node to a temporary variable
	Node<T>* temp = head<T>;	
	// store the data to a temporary variable
	T tempVal = temp->data;
	// move the head to next node
	head<T> = head<T>-> next;
	//free up the memory
	delete temp;
	//return the temporary variable data
	return tempVal;
}

template <typename T>
void Top(){
	//what if the stack is empty?
	if(isEmpty<T>()) return;
	std::cout<<"the top is: " << head<T>->data<<std::endl;
}

template <typename T>
void displayAll(){

	Node<T>* temp = head<T>;

	if(isEmpty<T>()){
		std::cout << "List is empty" << std::endl;
		return;
	}

	while(head<T> != nullptr){
		std::cout<< head<T>-> data;
		if(head<T> ->next != nullptr){
			std::cout<<"->";
		}
		head<T>  = head<T>->next;
	}
	head<T> = temp;
}

#endif
