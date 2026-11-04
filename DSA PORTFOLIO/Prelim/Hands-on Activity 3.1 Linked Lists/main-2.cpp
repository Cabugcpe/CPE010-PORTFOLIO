#include <iostream>
#include "singly_LL.h"
#include "double_LL.h"

int main(){
    //creating first node  'C' 'P' 'E'
   DoubleList<char>* head = createNode('C');
   DoubleList<char>* second = createNode('P');
   DoubleList<char>* third = createNode('E');


   //link the nodes together
    head -> next = second;
    second -> prev = head;
    
    second -> next = third;
    third -> prev = second;

    std::cout<<"Traversal testing: " <<std::endl;
    dllTraverse(head);

    std::cout<<"insert head testing: "<< std::endl;
    dllInsertHead('X', &head);
    dllTraverse(head);

    std::cout<<"insert end testing: "<< std::endl;
    dllInsertEnd('1', head);
    dllTraverse(head);

    std::cout<<"general insertion: "<<std::endl;
    dllGenIns('H', head);
    dllGenIns('Y', second);
    dllTraverse(head);

    std::cout<<"deletion of one node: "<<std::endl;
    dllDeleteNode('H', &head);
    dllTraverse(head);

    std::cout<<"deletion of whole list: "<<std::endl;
    dllDeleteList(&head);
    dllTraverse(head); 


    return 0;

}
#include <iostream>
#ifndef SINGLY_LL_H
#define SINGLY_LL_H

#include <iostream>

template <typename T>
class SinglyList{
    public:
        T data;
        SinglyList<T> *next = nullptr;

};

template <typename T>
void listTraversal(SinglyList<T>* head){

    if(head == nullptr){
        std::cout << "List is empty" <<std::endl;
        return;
    }

    while(head != nullptr){
        std::cout<< head->data;
        if(head->next != nullptr){
            std::cout<<"->";
        }
        head = head->next;
    }
    std::cout<<std::endl;
}

template <typename T>
void sllinsertHead(T newData, SinglyList<T>** currentHead){
    SinglyList<T>* newNode = new SinglyList<T>;
    newNode->data = newData;
    newNode->next = *currentHead;
    *currentHead= newNode;
}

template <typename T>
void sllGeneralInsert(T newData, SinglyList<T>* prevNode){
    if(prevNode == nullptr){
        std::cout<<"Previous Node cannot be Null" <<std::endl;
        return;
    }

    SinglyList<T>* newNode = new SinglyList<T>;
    newNode->data = newData;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

template <typename T>
void sllinsertEnd(T newData, SinglyList<T>** head){
    SinglyList<T>* newNode = new SinglyList<T>;
    SinglyList<T>* currentNode = *head;
    newNode->data = newData;
    newNode->next = nullptr;

    while(currentNode->next != nullptr){
        currentNode = currentNode->next;
    }

    currentNode->next = newNode;

}

template <typename T>
void sllDeleteNode(T findData, SinglyList<T>** head){
    if(*head == nullptr) return;

    SinglyList<T>* currNode = *head;
    SinglyList<T>* prevNode = nullptr;

    while(currNode != nullptr && currNode->data != findData){
        prevNode = currNode;
        currNode = currNode->next;
    }

    if(currNode == nullptr) return;

    if(prevNode == nullptr){
        *head = currNode->next;
    }else{
        prevNode-> next = currNode->next;
    }

    delete currNode;


}

template <typename T>
void sllDeleteList(SinglyList<T>** head){
    SinglyList<T>* current = *head;

    while(current != nullptr){
        SinglyList<T>* temp = current;
        current = current->next;
        delete temp;
    }
    *head = nullptr;
}

#endif
