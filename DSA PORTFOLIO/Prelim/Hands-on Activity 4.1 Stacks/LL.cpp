#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void push(char x) {
        Node* newNode = new Node;
        newNode->data = x;
        newNode->next = top;
        top = newNode;
    }

    char pop() {

        if (isEmpty())
            return '\0';

        Node* temp = top;
        char value = temp->data;

        top = top->next;
        delete temp;

        return value;
    }
};

bool isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

bool checkBalanced(string expr) {

    Stack s;

    for (char ch : expr) {

        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        }

        else if (ch == ')' || ch == '}' || ch == ']') {

            if (s.isEmpty())
                return false;

            char open = s.pop();

            if (!isMatching(open, ch))
                return false;
        }
    }

    return s.isEmpty();
}

int main() {

    string expression;

    cout << "Enter Expression: ";
    getline(cin, expression);

    if (checkBalanced(expression))
        cout << "Expression is Balanced." << endl;
    else
        cout << "Expression is NOT Balanced." << endl;

    return 0;
}
