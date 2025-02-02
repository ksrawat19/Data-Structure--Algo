#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* prev;
    Node* next;

    Node(int data): data(data), prev(nullptr), next(nullptr) {}
};

class DoublyLL{
    Node* head;
    int len;

    public: 
    DoublyLL(): head(nullptr), len(0) {}

    // length
    int length(){
        return len;
    }

    // insert
    void insertAtHead(int data){
        Node* newNode = new Node(data);
        len++;
        if(head == nullptr){
            head = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    void insertAtTail(int data){
        Node* newNode = new Node(data);
        len++;
        if(head == nullptr){
            head = newNode;
            return;
        }
        Node* tail = head;
        while(tail->next){
            tail = tail->next;
        }
        tail->next = newNode;
        newNode->prev = tail;
    }
    void insertAtPosition(int data, int pos){
        if(pos<0 || pos>len){
            return;
        }
        if(pos==0){
            insertAtHead(data);
            return;
        }
        if(pos==len){
            insertAtTail(data);
            return;
        }
        Node* newNode = new Node(data);
        len++;
        Node* prevNode = head;
        for(int i=1; i<pos; i++){
            prevNode = prevNode->next;
        }
        Node* nextNode = prevNode->next;
        prevNode->next = newNode;
        newNode->prev = prevNode;
        newNode->next = nextNode;
        nextNode->prev = newNode;
    }


    // delete 
    int deleteAtHead(){
        if(head == nullptr){
            cout<<"pgl h kya \n";
            return -1;
        }
        int headVal = head->data;
        Node* toDelete = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        toDelete->next = nullptr;
        delete toDelete;
        len--;
        return headVal;
    }
    int deleteAtTail(){
        if(head == nullptr){
            cout<<"pgl h kya \n";
            return -1;
        }
        Node* tail = head;
        if (tail->next == nullptr) { // Only one element in the list
            int tailVal = tail->data;
            delete tail;
            head = nullptr;
            len--;
            return tailVal;
        }
        while(tail->next->next){
            tail = tail->next;
        }
        int tailVal = tail->next->data;
        Node* toDelete = tail->next;
        tail->next = nullptr;
        toDelete->prev = nullptr;
        delete toDelete;
        len--;
        return tailVal;
    }
    void deleteAtposition(int pos){
        if(pos<0 || pos>=len){
            return;
        }
        if(pos==0){
            deleteAtHead();
            return;
        }
        if(pos==len-1){
            deleteAtTail();
            return;
        }
        if(head == nullptr){
            cout<<"pgl h kya \n";
            return;
        }
        Node* prevNode = head;
        for(int i=1; i<pos; i++){
            prevNode = prevNode->next;
        }
        Node* toDelete = prevNode->next;
        Node* nextNode = toDelete->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        toDelete->next = nullptr;
        toDelete->prev = nullptr;
        delete toDelete;
        len--;
    }

    // print List
    void printDLL(){
        if(head==nullptr){
            return;
        }
        Node*temp = head;
        while(temp){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
    void printDLLreverse(){
        if(head==nullptr){
            return;
        }
        Node* tail = head;
        while(tail->next){
            tail = tail->next;
        }
        while(tail){
            cout<<tail->data<<" ";
            tail = tail->prev;
        }
        cout<<endl;
    }
    void printDLLreverse2(Node* temp){
        if(temp==nullptr){
            return;
        }
        printDLLreverse2(temp->next);
        cout<<temp->data<<" ";
    }

    bool isEmpty(){
        return !len;
    }

    // Wrapper Function:
    void printDLLreverse2(){
        printDLLreverse2(head);
        cout<<endl;
    }
};

int main(){
    DoublyLL dll;
    if(dll.isEmpty()){
        cout<<"is empty : true"<<endl;
    }else{
        cout<<"is empty : false"<<endl;
    }
    cout<<"insert :\n";
    dll.insertAtHead(20);
    dll.insertAtHead(10);
    cout<<"length : "<<dll.length()<<endl;
    dll.printDLL();
    dll.printDLLreverse();
    
    dll.insertAtTail(30);
    dll.insertAtTail(40);
    cout<<"length : "<<dll.length()<<endl;
    dll.printDLL();
    dll.printDLLreverse();

    dll.insertAtPosition(25, 2);
    dll.printDLL();

    cout<<"delete :\n";
    dll.deleteAtHead();
    cout<<"length : "<<dll.length()<<endl;
    dll.deleteAtTail();
    cout<<"length : "<<dll.length()<<endl;
    dll.printDLL();
    dll.printDLLreverse();

    dll.deleteAtposition(2);
    dll.printDLL();

    if(dll.isEmpty()){
        cout<<"is empty : true"<<endl;
    }else{
        cout<<"is empty : false"<<endl;
    }
    return 0;
}