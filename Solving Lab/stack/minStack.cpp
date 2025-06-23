// 155. Min Stack
#include <iostream>
#include <stack>
using namespace std;

class MinStack {
    stack<int> stk, minStk;
public:
    MinStack() {}
    
    void push(int val) {
        stk.push(val);
        if(minStk.empty() || val<minStk.top()){
            minStk.push(val);
        }else{
            minStk.push(minStk.top());
        }
    }
    
    void pop() {
        stk.pop();
        minStk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return minStk.top();
    }
};

// someone's optimized code 
class MinStack {
    stack<long long> st;
    long long min;
public:
    MinStack() {
    }
    
    void push(int val) {
        long long v = val;
        if(st.empty()){
            min = v;
            st.push(v);
        }
        else{
            if(v>min){
                st.push(v);
            }
            else{
                st.push(2LL * v - min);
                min = v;
            }
        }
    }
    void pop() {
        if(st.empty())
            return;
        long long x = st.top();
        st.pop();
        if(x<min)
            min = 2*min - x;
    }
    
    int top() {
        if(st.empty())
            return -1;
        long long x = st.top();
        if(min<x)
            return x;
        return min;
    }
    
    int getMin() {
        return min;
    }
};