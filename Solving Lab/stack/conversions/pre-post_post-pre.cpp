#include <iostream>
#include <string>
#include <stack>
using namespace std;

string prefixToPostfix(string prefix) {
    stack<string> st;

    for (int i = prefix.length() - 1; i >= 0; i--) {
        char ch = prefix[i];

        if (isalnum(ch)) {
            st.push(string(1, ch));
        } else {
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();
            string expr = op1 + op2 + ch;
            st.push(expr);
        }
    }

    return st.top();
}

string postfixToPrefix(string postfix) {
    stack<string> st;

    for (char ch : postfix) {
        if (isalnum(ch)) {
            st.push(string(1, ch));
        } else {
            string op2 = st.top(); st.pop();
            string op1 = st.top(); st.pop();
            string expr = ch + op1 + op2;
            st.push(expr);
        }
    }

    return st.top();
}

int main() {
    string prefixExpr = "^a^bc";
    string postfixExpr = "abc^^";

    cout << "=== Prefix to Postfix ===" << endl;
    cout << "Prefix:  " << prefixExpr << endl;
    cout << "Postfix: " << prefixToPostfix(prefixExpr) << endl << endl;

    cout << "=== Postfix to Prefix ===" << endl;
    cout << "Postfix: " << postfixExpr << endl;
    cout << "Prefix:  " << postfixToPrefix(postfixExpr) << endl;

    return 0;
}
