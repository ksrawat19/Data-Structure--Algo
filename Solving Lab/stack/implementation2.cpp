// Implement Stack using Queue
#include <iostream>
#include <queue>
using namespace std;

// M1 (using two queue)
class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    MyStack() {
        
    }
    
    void push(int x) {
        q2.push(x);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        // swap(q1, q2);
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }

    }
    
    int pop() {
        int toPop = q1.front();
        q1.pop();
        return toPop;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};

// M2 (using one queue)
class MyStack {
    queue<int> q;
public:
    MyStack() {}
    
    void push(int x) {
        q.push(x);
        for(int i=1; i<q.size(); i++){
            int front = q.front();
            q.pop();
            q.push(front);
        }
    }
    
    int pop() {
        int toPop = q.front();
        q.pop();
        return toPop;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};
// in this method also can rotate queue in pop and top method rather push like below:
    // int pop() {
    //     int temp = -1;
    //     for(int i = 0; i < q.size() - 1; i++) {
    //         q.push(q.front());
    //         q.pop();
    //     }
    //     temp = q.front();
    //     q.pop();
    //     return temp;
    // }
    
    // int top() {
    //     int temp = -1;
    //     for(int i = 0; i < q.size(); i++) {
    //         temp = q.front();
    //         q.push(q.front());
    //         q.pop();
    //     }
    //     return temp;
    // }
