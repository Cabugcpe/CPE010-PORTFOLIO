#include <iostream>

const size_t maxCap = 100;
int stack[maxCap];
int top = -1, newData, elements;

//prototyping
bool isFull();
bool isEmpty();
void push();
void pop();
void Top();

//display all
void displayAll();

int main(){
    std::cout<<"Enter the number of maximum elements for the new stack (max: 100): ";
    std::cin>>elements;

    while(true){
        int choice = 0;
        std::cout<<"Select Stack Operation:"<<std::endl;
        std::cout<<"1. PUSH\n2. POP\n3. VIEW TOP\n4. IS EMPTY?\n5. IS FULL\n6. displayAll"<<std::endl;
        std::cin >> choice;

        switch(choice){
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                Top();
                break;

            case 4:
                std::cout<<isEmpty()<<std::endl;
                break;

            case 5:
                std::cout<<isFull()<<std::endl;
                break;

            case 6:
                displayAll();
                break;

            default:
                std::cout<<"Invalid Choice"<<std::endl;
                break;
        }
    }

    return 0;
}

bool isEmpty(){
    //top is -1
    if(top == -1){
        std::cout<<"Stack Underflow"<<std::endl;
        return true;
    }
    return false;
}

bool isFull(){
    //Not equal to maxCap
    if(top >= elements){
        std::cout<<"Stack Overflow"<<std::endl;
        return true;
    }
    return false;
}

void push(){
    //check if stack is full, if yes, return error
    if (isFull()){
        return;
    }

    //ask user input values to be pushed into stack
    std::cout<<"What number would you like to add" ;
    std::cin>>newData;

    //store inside stack
    stack[++top] = newData;
}

void pop(){
    // check if empty
    if (isEmpty()){
        return;
    }

    //display element to be popped
    std::cout<<"Popping: "<<stack[top]<<std::endl;

    //decrement top;
    top--;
}

void Top(){
    //error checking
    if(isEmpty()){
        return;
    }

    //display top
    std::cout<<"The top element is"<<stack[top]<<std::endl;
}

void displayAll(){
    if (isEmpty()){
        return;
    }

    for (int i = top; i >= 0; i--){
        std::cout << stack[i] << " ";
    }

    std::cout << std::endl;
}