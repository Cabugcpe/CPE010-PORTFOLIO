#ifndef QUEUEARR_H
#define QUEUEARR_H

#include <cstddef>
#include <iostream>

template <typename T>
class QueueArr{
    private:
        T* q_Array;
        size_t q_capacity;
        size_t q_size;
        int q_front;
        int q_back;
    

    public:
        //Construct emT queue
        QueueArr(size_t capacity);

        //Destructor
        ~QueueArr();

        bool Empty();
        bool Full();

        size_t Size();

        void Clear();

        //initialize front and back
        T Front(T newData);
        T Back();

        void Enqueue(T newData);
        void Dequeue();

        QueueArr(const QueueArr& other);
        QueueArr& operator=(const QueueArr& other);

};

//definition of constructor
template <typename T>
QueueArr<T>::QueueArr(size_t q_capacity){
    //capacity
    this->q_capacity = q_capacity;
    //size = 0
    q_size = 0;
    //front = 0
    q_front = 0;
    //back = -1
    q_back = -1;
    //update capacity
    q_Array = new T[q_capacity];

    std::cout<<"Constructor was called"<<std::endl;
}   
//Destroyer        
template <typename T>
QueueArr<T>::~QueueArr(){
    delete[] q_Array;
    std::cout<<"Destructor was called"<<std::endl;
}

//isempty
template <typename T>
bool QueueArr<T>::Empty(){
    return (q_size == 0);
}

//isfull
template <typename T>
bool QueueArr<T>::Full(){
    return (q_size == q_capacity);
}

//size
template <typename T>
size_t QueueArr<T>::Size(){
    return q_size;
}

//clear
template <typename T>
void QueueArr<T>::Clear(){
    //queue size = 0
    q_size = 0;
    //queue front and queue back to 0 and -1
    q_front = 0;
    q_back = -1;
    return;
}

//front
template <typename T>
T QueueArr<T>::Front(T newData){
    //check if queue is empty
    //if not empty, show the front
    if(Empty()){
        std::cout<<"Queue is empty"<<std::endl;
        return T{};
    }
    else{
        return q_Array[q_front];
    }
}

//back
template <typename T>
T QueueArr<T>::Back(){
    //check if queue is empty
    //if not empty, show the back
    if(Empty()){
        std::cout<<"Queue is empty"<<std::endl;
        return T{};
    }
    else{
        return q_Array[q_back];
    }
}

//enqueue
template <typename T>
void QueueArr<T>::Enqueue(T newData){
    //check if queue is full
    if(Full()){
        std::cout<<"Queue is full"<<std::endl;
        return;
    }
    else{
        //compute back 
        q_back = (q_back + 1) % q_capacity;
        //add new data to the back
        q_Array[q_back] = newData;
        //increment size
        q_size++;
    }
}

//dequeue
template <typename T>
void QueueArr<T>::Dequeue(){
    //check if queue is empty
    if(Empty()){
        std::cout<<"Queue is empty"<<std::endl;
        return;
    }
    else{
        //compute front
        q_front = (q_front + 1) % q_capacity;
        //decrement size
        q_size--;
    }

    //if queue empty, reset everything
    if(q_size ==0){
        Clear();
        return;
    }
}

//


#endif