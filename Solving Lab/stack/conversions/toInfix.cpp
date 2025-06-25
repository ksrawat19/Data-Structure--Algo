#include <iostream>
#include <string>
#include <stack>
using namespace std;

string postfixToInfix(string postfix) {
    stack<string> st;

    for (char ch : postfix) {
        if (isalnum(ch)) {
            st.push(string(1, ch));
        } else {
            string b = st.top(); st.pop();
            string a = st.top(); st.pop();
            string expr = "(" + a + ch + b + ")";
            st.push(expr);
        }
    }

    return st.top();
}

string prefixToInfix(string prefix) {
    stack<string> st;

    for (int i = prefix.length() - 1; i >= 0; i--) {
        char ch = prefix[i];
        if (isalnum(ch)) {
            st.push(string(1, ch));
        } else {
            string a = st.top(); st.pop();
            string b = st.top(); st.pop();
            string expr = "(" + a + ch + b + ")";
            st.push(expr);
        }
    }

    return st.top();
}

int main() {
    string postfixExpr = "abc^^";
    string prefixExpr  = "^a^bc";

    cout << "Postfix: " << postfixToInfix(postfixExpr) << endl;
    cout << "Prefix: " << prefixToInfix(prefixExpr) << endl;

    return 0;
}
