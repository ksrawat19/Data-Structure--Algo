// 📂 Program X : Rotate List (Leetcode-61)

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int data): data(data), next(nullptr) {}
};

class LinkedList{
    Node* head;
    int length; 
    public:
    LinkedList(): head(nullptr), length(0) {}

    Node* findTail(){
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        Node* tail = head;
        while(tail->next!=nullptr){
            tail = tail->next;
        }
        return tail;
    }

    void insertAtEnd(int data){
        Node* newNode = new Node(data);
        length++;
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

    void rotate(){
        if(head==nullptr){
            return;
        }
        int k; cout<<"k : "; cin>>k;
        k = k%length;
        if(k==0){
            return;
        }
        Node* tail = findTail();
        Node* temp = head;
        for(int i=1; i<length-k; i++){
            temp = temp->next;            
        }
        tail->next = head;
        head = temp->next;
        temp->next = nullptr;
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
};

int main() {
    LinkedList ll;

    ll.insertAtEnd(1);
    ll.insertAtEnd(2);
    ll.insertAtEnd(3);
    ll.insertAtEnd(4);
    ll.insertAtEnd(5);
    cout<<"Before rotate : ";
    ll.printLL();

    ll.rotate();
    cout<<"After rotate : ";
    ll.printLL();

    return 0;
}