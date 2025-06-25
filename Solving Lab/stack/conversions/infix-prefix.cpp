#include <iostream>
#include <stack>
#include <algorithm>
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
    string postfix;

    for (char ch : infix) {
        if (isalnum(ch)) {
            postfix += ch;
        }
        else if (ch == '(') {
            st.push(ch);
        }
        else if (ch == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top(); st.pop();
            }
            if (!st.empty()) st.pop(); // Remove '('
        }
        else if (isOperator(ch)) {
            while (!st.empty() &&
                ((precedence(ch) < precedence(st.top())) ||
                 (precedence(ch) == precedence(st.top()) && isRightAssociative(ch))) &&
                 st.top() != '(') {
                postfix += st.top(); st.pop();
            }
            st.push(ch);
        }
    }

    while (!st.empty()) {
        postfix += st.top(); st.pop();
    }

    return postfix;
}

string infixToPrefix(string infix) {
    reverse(infix.begin(), infix.end());

    for (int i = 0; i < infix.size(); ++i) {
        if (infix[i] == '(') infix[i] = ')';
        else if (infix[i] == ')') infix[i] = '(';
    }

    string postfix = infixToPostfix(infix);
    reverse(postfix.begin(), postfix.end());
    return postfix;
}

int main() {
    // string expr = "(A-B/C)*(A/K-L)";
    string expr = "a ^ b ^ c";
    cout << "Infix: " << expr << endl;
    cout << "Prefix: " << infixToPrefix(expr) << endl;
    return 0;
}
