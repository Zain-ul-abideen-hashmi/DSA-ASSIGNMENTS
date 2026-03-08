#include <iostream>
#include <string>
#include "Stack.h"
using namespace std;

int getPrecedence(char op)
{
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

string infixToPostfix(std::string infix)
{
    Stack<char> s;
    std::string postfix = "";
    for (char c : infix) {
        if (isalnum(c)) postfix += c;
        else if (c == '(') s.push(c);
        else if (c == ')') {
            while (!s.isEmpty() && s.peek() != '(') postfix += s.pop();
            s.pop(); // remove '('
        }
        else {
            while (!s.isEmpty() && getPrecedence(s.peek()) >= getPrecedence(c)) {
                postfix += s.pop();
            }
            s.push(c);
        }
    }
    while (!s.isEmpty()) postfix += s.pop();
    return postfix;
}

int evaluatePostfix(std::string postfix)
{
    Stack<int> s;
    for (char c : postfix)
    {
        if (isdigit(c)) s.push(c - '0');
        else if (c != ' ') {
            int val2 = s.pop();
            int val1 = s.pop();
            switch (c) {
            case '+': s.push(val1 + val2); break;
            case '-': s.push(val1 - val2); break;
            case '*': s.push(val1 * val2); break;
            case '/': s.push(val1 / val2); break;
            }
        }
    }
    return s.pop();
}

int main() {

    string infix = "(A+B)*(C-D)+E";
    string postfixExpr = "523*+9-";

    cout << "Infix: " << infix << std::endl;
    cout << "Postfix: " << infixToPostfix(infix) << std::endl;

    cout << "Evaluating Postfix: 5 2 3 * + 9 -" << std::endl;
    cout << "Result: " << evaluatePostfix(postfixExpr) << std::endl;

    cin.ignore(); // added by me (zain) becuase clion would exit immediately
    cin.get();

    return 0;
}
