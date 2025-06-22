// Implement Stack using Arrays
#include <iostream>
using namespace std;

class Stack{
    private:
    int *arr;
    int maxSize;
    int topIndex;
    
    public:
    Stack(int _size){
        maxSize = _size;
        arr = new int[_size];
        topIndex = -1;
    }

    void push(int x) {
        if(topIndex==maxSize-1){
            return;
        }
        // topIndex++;
        arr[++topIndex] = x;
    }
    
    int pop() {
        if(topIndex==-1) return -1;
        return arr[topIndex--];
    }
    
    int top() {
        if(topIndex==-1) return -1;
        return arr[topIndex];
    }
    
    bool isEmpty() {
        return topIndex==-1;
    }

    int size(){
        return topIndex+1;
    }
};

int main(){
    Stack s(5);

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();

    if(s.isEmpty()){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }

    cout<<"size is : "<<s.size()<<endl;

    return 0;
}