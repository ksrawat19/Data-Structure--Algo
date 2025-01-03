#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class Stack{
    Node* head;
    int topIndex = -1;

    public:
    Stack() : head(nullptr) {}
    
    void push(int val){
        Node* newNode = new Node(val);
        topIndex++;
        if(head == nullptr){
            head = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }

    int pop(){
        if(head == nullptr){
            cout<<"underflow"<<endl;
            return -1;
        }
        Node* temp = head;
        head = head->next;
        temp->next = nullptr;
        int removed = temp->data;
        delete temp;
        topIndex--;
        return removed;
    }

    int top(){
        if(head!=nullptr){
            return head->data;
        }
        return -1;
    }

    bool isEmpty(){
        return topIndex==-1;
    }

    int size(){
        return topIndex+1;
    }

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

int main(){
    Stack s;

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