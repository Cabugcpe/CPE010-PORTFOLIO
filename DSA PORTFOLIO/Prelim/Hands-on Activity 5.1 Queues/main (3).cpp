#include <iostream>
#include "queueLL.h"

int main (){
    qNode<char>* front = nullptr;
    qNode<char>* back = nullptr;

    //enqueue
    enqueue('J', &front, &back);
    std::cout<< front->data << " " << back->data <<std::endl;
    enqueue('E', &front, &back);
    std::cout<< front->data << " " << back->data <<std::endl;
    enqueue('P', &front, &back);
    std::cout<< front->data << " " << back->data <<std::endl;
    
    //display JEP
    displayAll(front);

    //dequeue
    dequeue(&front, &back);
    std::cout << front->data << " " << back->data <<std::endl;
    dequeue(&front, &back);
    std::cout << front->data << " " << back->data <<std::endl;
    dequeue(&front, &back);

    //display Empty
    displayAll(front);

    //front
    enqueue('J', &front, &back);
    getFront(front);
    //back
    enqueue('E', &front, &back);
    getBack(back);
    std::cout<<front->data<<" "<<back-> data <<std::endl;
    
    // display ALL J and E
    displayAll(front);

    return 0;
}