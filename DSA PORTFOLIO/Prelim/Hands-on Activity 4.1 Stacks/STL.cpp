#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

bool checkBalanced(string expr) {

    stack<char> s;

    for (char ch : expr) {

        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        }

        else if (ch == ')' || ch == '}' || ch == ']') {

            if (s.empty())
                return false;

            char open = s.top();
            s.pop();

            if (!isMatching(open, ch))
                return false;
        }
    }

    return s.empty();
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
