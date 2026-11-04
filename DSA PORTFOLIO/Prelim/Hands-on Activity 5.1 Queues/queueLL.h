#ifndef QUEUELL_H
#define QUEUELL_H


// create a class the node
template <typename T>
class qNode{
    public:
        T data;
        qNode<T>* next;
};

//creates the new node
template <typename T>
qNode<T>* new_node(T newData){
    qNode<T>* newNode = new qNode<T>;
    newNode->data = newData;
    newNode->next = nullptr;
    return newNode;
}

// enqueue operation
template <typename T>
void enqueue(T newData, qNode<T>** frontPtr, qNode<T>** backPtr){
    // create the new node
    qNode<T>* newNode = new_node(newData);

    //inserting into an empty queue
    if((*frontPtr)==nullptr && (*backPtr)==nullptr){
        (*frontPtr) = newNode;
        (*backPtr) = newNode;
    }
    //inserting an item into a non empty queue
    (*backPtr)->next = newNode;
    (*backPtr) = newNode;
}

template <typename T>
void dequeue(qNode<T>** frontPtr, qNode<T>** backPtr){
    //add a isempty function here

    //create a temporary node
    qNode<T>* deleteNode = nullptr; // temp variable
    deleteNode = (*frontPtr);

    //check if the queue has only 1 node
    if((*frontPtr)->next == nullptr && (*backPtr)->next == nullptr){
        (*frontPtr) = nullptr;
        (*backPtr) = nullptr;
        delete deleteNode;
        return;
    }
    // delete the node
    (*frontPtr) = (*frontPtr)->next;
    deleteNode->next = nullptr;
    delete deleteNode;

}

//check the front
template<typename T>
void getFront(qNode<T>* frontPtr){
    if (frontPtr == nullptr){
        std::cout<<"Queue is empty!"<<std::endl;
        return;
    }

    std::cout<<"The current front: "<<frontPtr->data<<std::endl;

}

// check the back
//check the front
template<typename T>
void getBack(qNode<T>* backPtr){
    if (backPtr == nullptr){
        std::cout<<"Queue is empty!"<<std::endl;
        return;
    }

    std::cout<<"The current back: "<<backPtr->data<<std::endl;

}
//display all
template <typename T>
void displayAll(qNode<T>* frontPtr){
     if(frontPtr == nullptr){
        std::cout<<"The queue is empty!"<<std::endl;
        return;
     }
     std::cout<<"The current Queue: ";
     while(frontPtr != nullptr){
        std::cout<<frontPtr->data<<" ";
        frontPtr = frontPtr->next;
     }
     std::cout<<"\n";

}
#endif