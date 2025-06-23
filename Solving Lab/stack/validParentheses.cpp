// 20. Valid Parentheses
#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;

        int size = s.length();
        for(int i=0; i<size; i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='[') stk.push(s[i]);
            else{
                if(stk.empty()) return false;
                char top = stk.top();
                if(top=='(' && s[i]!=')' ||
                   top=='[' && s[i]!=']' ||
                   top=='{' && s[i]!='}'){
                    return false;
                   }
                stk.pop();
            }
        }
        return stk.empty();
    }
};