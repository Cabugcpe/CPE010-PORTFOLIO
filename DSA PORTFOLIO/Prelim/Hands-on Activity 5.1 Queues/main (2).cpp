#include <iostream>
#include <queue>

void display(std::queue<char> copyQ);

int main(){
    // create an object
    std::queue<char> myQ;

    myQ.push('J');
    myQ.push('E');
    myQ.push('F');
    myQ.push('F');
    myQ.push('O');
    myQ.push('R');
    myQ.push('D');
    myQ.push('N');
    myQ.push('I');
    myQ.push('E');
    myQ.push('L');
    display(myQ);
    
    // TRY ALL MEMBER FUNCTIONS:
    // empty
    std::cout<<"isEmpty: "<<myQ.empty()<<std::endl;
    // size
    std::cout<<"Size: "<< myQ.size()<<std::endl;
    // front
    std::cout<<"Front: "<< myQ.front()<<std::endl;
    // back
    std::cout<<"Back: "<< myQ.back()<<std::endl;
    // pop
    std::cout<<"Popping: "<< myQ.front()<<std::endl;
    myQ.pop();
    // display
    display(myQ);
    // push
    std::cout<<"Pushing: "<< myQ.back()<<std::endl;
    myQ.push('J');
    // display
    display(myQ);

    return 0;
}
void display(std::queue<char> copyQ){
    //creates a copy of the queue that was passed
    std::queue<char> c = copyQ;

    while (!c.empty())
    {
        std::cout<<" "<<c.front();
        c.pop();
    }
    std::cout<<"\n";

}