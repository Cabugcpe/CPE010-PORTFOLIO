#ifndef DOUBLE_LL_H
#define DOUBLE_LL_H

template<typename T>
class DoubleList{
    public:
    T data;
    DoubleList<T>* prev = nullptr;
    DoubleList<T>* next = nullptr;
};

template <typename T>
DoubleList<T>* createNode(T newData){
    DoubleList<T> *newNode = new DoubleList<T>;

    newNode-> data = newData;
    newNode-> prev = nullptr;
    newNode-> next = nullptr;

    return newNode;
}


template<typename T>
void dllTraverse(DoubleList<T> *currentNode){
    if(currentNode == nullptr){
        std::cout <<"the list is empty.";
        return;
    }
    
    DoubleList<T>* tail;
    
    std::cout<<"Forward: " <<std::endl;
    while(currentNode != nullptr){
        std::cout<<currentNode->data<<" ";
        tail = currentNode;
        currentNode = currentNode->next;
    }

    std::cout<<"\nBackward: " <<std::endl;
    while(tail != nullptr){
        std::cout<<tail->data<<" ";
        tail = tail->prev;
    }
    std::cout<<std::endl;

}

template<typename T>
void dllInsertHead(T newData, DoubleList<T>** currentHead){
    DoubleList<T>* newNode = createNode(newData);
    newNode->next = *currentHead;
    if(*currentHead != nullptr){
        (*currentHead)->prev = newNode;
    }
    *currentHead = newNode;

}

template<typename T>
void dllInsertEnd(T newData, DoubleList<T> *currentHead){
    DoubleList<T> *newNode = createNode(newData);
    while(currentHead->next !=nullptr){
        currentHead = currentHead->next;
    }
    
    currentHead->next = newNode;
    newNode->prev = currentHead;
}


template <typename T>
void dllGenIns(T newData, DoubleList<T>* prevNode) {
    if (prevNode == nullptr) {
        std::cout << "Previous node cannot be empty" << std::endl;
        return; // Prevents dereferencing nullptr below
    }

    // Create new node
    DoubleList<T>* newNode = createNode(newData);

    // Link pointers
    newNode->next = prevNode->next;
    newNode->prev = prevNode;

    if (prevNode->next != nullptr) {
        prevNode->next->prev = newNode; // Connect the existing next node back to newNode
    }

    prevNode->next = newNode;
}


template <typename T>
void dllDeleteNode(T findData, DoubleList<T>** head){
    if(*head == nullptr) return;

    DoubleList<T>* currNode = *head;

    
    while(currNode != nullptr && currNode->data != findData){
        currNode = currNode->next;
    }

    
    if(currNode == nullptr) return;

    
    if(currNode == *head){
        *head = currNode->next;
        if(*head != nullptr){
            (*head)->prev = nullptr;
        }
    } 
    
    else {
        currNode->prev->next = currNode->next;
        if(currNode->next != nullptr){
            currNode->next->prev = currNode->prev;
        }
    }

    delete currNode;
}

template <typename T>
void dllDeleteList(DoubleList<T>** head){
    DoubleList<T>* current = *head;

    while(current != nullptr){
        DoubleList<T>* temp = current;
        current = current->next;
        delete temp;
    }
    
    *head = nullptr;
}


#endif
