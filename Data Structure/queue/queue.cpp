#include <iostream>
using namespace std;

class Queue{
    int* arr;
    int frontIndex = -1;
    int rearIndex = -1;
    int maxSize;

    public:
    Queue(int size) : arr(new int[size]), maxSize(size) {}

    void enqueue(int data){
        if(rearIndex == maxSize-1){
            cout<<"overflow"<<endl;
            return;
        }
        if(frontIndex == -1){
            frontIndex = rearIndex = 0;
            arr[rearIndex] = data;
            return;
        }
        rearIndex++;
        arr[rearIndex] = data;
    }

    int dequeue(){
        if(rearIndex == -1){
            cout<<"underflow"<<endl;
            return -1;
        }
        int removed = arr[frontIndex];
        if(frontIndex==rearIndex){
            frontIndex = rearIndex = -1;
        }else{
            frontIndex++;
        }
        return removed;
    }

    int front(){
        if(frontIndex != -1){
            return arr[frontIndex]; 
        }
        return -1;
    }
    int back(){
        if(rearIndex != -1){
            return arr[rearIndex]; 
        }
        return -1;
    }

    bool isEmpty(){
        if(rearIndex==-1){
            return true;
        }
        return false;
    }

    int size(){
        if (isEmpty()) return 0;
        return (rearIndex-frontIndex+1);
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