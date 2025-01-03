#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class Queue{
    Node* head;
    Node* tail;
    int queueSize = 0;

    public:
    Queue() : head(nullptr), tail(nullptr) {}

    void enqueue(int data){
        queueSize++;
        Node* newNode = new Node(data);
        if(tail == nullptr){
            head = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
    }

    int dequeue(){
        if(head == nullptr){
            cout<<"underflow"<<endl;
            return -1;
        }
        Node* temp = head;
        head = head->next;
        temp->next = nullptr;
        int removed = temp->data;
        delete temp;
        queueSize--;
        return removed;
    }

    int front(){
        if(head!=nullptr){
            return head->data;
        }
        return -1;
    }
    int back(){
        if(tail!=nullptr){
            return tail->data;
        }
        return -1;
    }

    bool isEmpty(){
        return queueSize==0;
    }

    int size(){
        return queueSize;
    }

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
        delete head;
        delete tail;
    }
};

int main(){
    Queue q;

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