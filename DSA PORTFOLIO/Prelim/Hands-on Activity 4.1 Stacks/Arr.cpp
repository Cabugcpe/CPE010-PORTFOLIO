#include <iostream>
#include <string>
using namespace std;

class Stack {
private:
    char arr[100];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == 99;
    }

    void push(char x) {
        if (!isFull()) {
            arr[++top] = x;
        }
    }

    char pop() {
        if (!isEmpty()) {
            return arr[top--];
        }
        return '\0';
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

            if (s.isEmpty()) {
                return false;
            }

            char open = s.pop();

            if (!isMatching(open, ch)) {
                return false;
            }
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
