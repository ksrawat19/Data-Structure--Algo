// 📂 Program 1: Reverse Linked List (Leetcode-206)

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int data): data(data), next(nullptr) {}
};

class LinkedList{
    Node* head;

    public:
    LinkedList(): head(nullptr) {}

    void insertAtEnd(int data){
        Node* newNode = new Node(data);
        if(head==nullptr){
            head = newNode;
            return;
        }
        Node* temp = head;
        while(temp->next!=nullptr){
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void reverse(){
        if(!head || !head->next){
            return;
        }
        Node* prev = nullptr;
        Node* curr = head;
        while(curr!=nullptr){
            head = head->next;
            curr->next = prev;
            prev = curr;
            curr = head;
        }
        head = prev;
    }
    // A L S O
    // void reverse() {
    // Node* prev = nullptr;
    // Node* curr = nullptr;

    // while (head != nullptr) {
    //     curr = head->next;
    //     head->next = prev; 
    //     prev = head;
    //     head = curr;
    // }
    // head = prev; 
    // }
    void reverseRecursively(Node* prev, Node* curr){
        if(!curr){
            head = prev;
            return;
        }
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
        reverseRecursively(prev, curr);
    }

    void printLL(){
        if(head==nullptr){
            cout<<"kya kr rha h byi\n";
            return;
        }
        Node* temp = head;
        while(temp!=nullptr){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
    // Helper Function to Call Reverse Recursively
    void reverseRecursively(){
        reverseRecursively(nullptr, head);
    }
};

int main() {
    LinkedList ll;

    ll.insertAtEnd(1);
    ll.insertAtEnd(2);
    ll.insertAtEnd(3);
    ll.insertAtEnd(4);
    ll.insertAtEnd(5);
    cout<<"Before reverse : ";
    ll.printLL();

    ll.reverseRecursively();
    cout<<"After reverse : ";
    ll.printLL();

    return 0;
}