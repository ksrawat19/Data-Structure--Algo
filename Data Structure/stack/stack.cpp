#include <iostream>
using namespace std;

class Stack{
    int* arr;
    int maxSize;
    int topIndex = -1;

    public:
    Stack(int size) : arr(new int[size]), maxSize(size) {
        // this->arr = new int[size];
        // this->size = size;
    }

    void push(int val){
        if(topIndex == maxSize-1){
            cout<<"overflow"<<endl;
            return;
        }
        topIndex++;
        arr[topIndex] = val;
    }

    int pop(){
        if(topIndex == -1){
            cout<<"underflow"<<endl;
            return -1;
        }
        int removed = arr[topIndex--];
        return removed;
    }

    int top(){
        if(topIndex == -1){
            cout<<"stack is empty"<<endl;
            return -1;
        }
        return arr[topIndex];
    }

    bool isEmpty(){
        if(topIndex == -1){
            return true;
        }
        return false;

        // return (topIndex == -1)
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