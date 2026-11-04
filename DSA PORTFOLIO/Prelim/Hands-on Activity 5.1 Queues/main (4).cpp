#include <iostream>
#include "queueArr_alter.h"

int main(){

    //create an object
    QueueArr<char> q(6);

    q.Enqueue('J');
    std::cout<<"Front: "<<q.Front('J')<<" "<<"Back: "<<q.Back()<<std::endl;
    q.Enqueue('E');
    std::cout<<"Front: "<<q.Front('E')<<" "<<"Back: "<<q.Back()<<std::endl;
    q.Enqueue('F');
    std::cout<<"Front: "<<q.Front('F')<<" "<<"Back: "<<q.Back()<<std::endl;
    q.Enqueue('F');
    std::cout<<"Front: "<<q.Front('F')<<" "<<"Back: "<<q.Back()<<std::endl;

    return 0;
}
