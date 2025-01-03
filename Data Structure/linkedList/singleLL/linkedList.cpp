#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList{
    Node* head;
    public:

    LinkedList() : head(nullptr) {}
    // insertion
    void insertAtBeg(int val){
        Node* newNode = new Node(val);
        if(head==nullptr){
            head = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int val){
        Node* newNode = new Node(val);
        if(head==nullptr){
            head = newNode;
            return;
        }
        Node* curr = head;
        while(curr->next!=nullptr){
            curr = curr->next;
        }
        curr->next = newNode;
    }

    int deleteAtBeg(){
        if(head == nullptr){
            return -1;
        }
        Node* temp = head;
        head = head->next;
        int deleting = temp->data;
        delete temp;
        return deleting;
    }
    int deleteAtEnd(){
        if(head == nullptr){
            return -1;
        }
        Node* curr = head;
        while(curr->next->next!=nullptr){
            curr = curr->next;
        }
        Node* temp = curr->next;
        curr->next = nullptr;
        int deleting = temp->data;
        delete temp;
        return deleting;
    }

    void print(){
        if(head==nullptr){
            return;
        }
        Node* temp = head;
        while(temp!=nullptr){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};

int main(){
    LinkedList ll;

    ll.insertAtBeg(10);
    ll.insertAtBeg(20);
    ll.insertAtBeg(30);

    ll.insertAtEnd(-20);
    ll.insertAtEnd(-30);

    ll.print();

    ll.deleteAtBeg();
    ll.deleteAtEnd();

    ll.print();

    return 0;
}