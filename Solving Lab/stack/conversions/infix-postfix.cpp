// Infix to Postfix Conversion using Stack
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

bool isRightAssociative(char op) {
    return op == '^';
}

bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

string infixToPostfix(string infix) {
    stack<char> st;
    string postfix = "";

    for (char ch : infix) {
        if (isalnum(ch)) {
            postfix += ch;
        }
        else if (ch == '(') {
            st.push(ch);
        }
        else if (ch == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop();
        }
        else if (isOperator(ch)) {
            while (!st.empty() && 
                   ((precedence(ch) < precedence(st.top())) || 
                   (precedence(ch) == precedence(st.top()) && !isRightAssociative(ch))) &&
                   st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }

    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

int main() {
    string exp = "a ^ b ^ c";
    // string exp = "A - B + C";
    // string expr = "(A-B/C)*(A/K-L)";
    cout << "Infix expression: " << exp << endl;
    cout << "Postfix: " << infixToPostfix(exp) << endl;
  return 0;
}