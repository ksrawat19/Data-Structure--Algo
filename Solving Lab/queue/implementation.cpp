// Implement Queue using Arrays
#include <iostream>
using namespace std;

class Queue{
    private:
    int *arr;
    int maxSize;
    int frontIndex;
    int rearIndex;

    public:
    Queue(int _size){
        maxSize = _size;
        arr = new int[_size];
        frontIndex = rearIndex = -1;
    }

    void enqueue(int val){
        if(rearIndex==maxSize-1) return;
        if (rearIndex == -1) {
            frontIndex = rearIndex = 0;
        } else {
            rearIndex++;
        }
        arr[rearIndex] = val;
    }
    int dequeue(){
        if(frontIndex==-1) return -1;
        int toPop =arr[frontIndex];
        if(frontIndex==rearIndex){
            frontIndex=rearIndex=-1;
        }else{
            frontIndex++;
        }
        return toPop;
    }
    int front(){
        return (frontIndex!=-1)? arr[frontIndex]: -1;
    }
    int back(){
        return (rearIndex!=-1)? arr[rearIndex]: -1;
    }
    int size(){
        return rearIndex-frontIndex+1;
    }
    bool isEmpty(){
        return (rearIndex==-1 || frontIndex>rearIndex);
    }
};

int main(){
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    cout<<"size : "<<q.size()<<endl;
    q.dequeue();
    cout<<"size after dequeue : "<<q.size()<<endl;

    cout<<"front : "<<q.front()<<endl;
    cout<<"back : "<<q.back()<<endl;
    
    if(q.isEmpty()){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }
    
    return 0;
}