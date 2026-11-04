
#ifndef QUEUELL_H
#define QUEUELL_H

struct Node
{
    char data;
    Node* next;

    Node(char value)
    {
        data = value;
        next = nullptr;
    }
};

class Queue
{
private:
    Node* front;
    Node* back;

public:
    Queue()
    {
        front = nullptr;
        back = nullptr;
    }

    ~Queue()
    {
        while (!isEmpty())
        {
            dequeue();
        }
    }

    bool isEmpty() const
    {
        return front == nullptr;
    }

    void enqueue(char value)
    {
        Node* newNode = new Node(value);
        if (isEmpty())
        {
            front = newNode;
            back = newNode;
        }
        else
        {
            back->next = newNode;
            back = newNode;
        }
    }

    char dequeue()
    {
        if (isEmpty())
        {
            return '\0';
        }
        Node* temp = front;
        char value = temp->data;
        front = front->next;

        if (front == nullptr)
        {
            back = nullptr;
        }
        delete temp;

        return value;
    }
};

#endif