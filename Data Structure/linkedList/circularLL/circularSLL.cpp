#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList{
    Node* head;
    int length=0;

    public:

    LinkedList() : head(nullptr) {}
    // insertion
    void insertAtBeg(int val){
        Node* newNode = new Node(val);
        length++;
        if(head==nullptr){
            head = newNode;
            newNode->next = head;
            return;
        }
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }
    void insertAtEnd(int val){
        Node* newNode = new Node(val);
        length++;
        if(head==nullptr){
            head = newNode;
            return;
        }
        Node* curr = head;
        while(curr->next!=head){
            curr = curr->next;
        }
        curr->next = newNode;
        newNode->next = head;
    }
    void insertAtPosition(int val, int pos){
        if(pos<1 || pos>length + 1){
            cout << "Invalid position!" << endl; 
            return; 
        }
        if(pos==1){
            insertAtBeg(val);
            return;
        }
        if(pos==length+1){
            insertAtEnd(val);
            return;
        }
        Node* newNode = new Node(val);
        length++;   
        Node* curr = head;
        for(int i=2; i<pos; i++){
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
    }

    int deleteAtBeg(){
        if(head == nullptr){
            return -1;
        }
        length--;
        Node* temp = head;
        Node* tail = head;
        head = head->next;
        while(tail->next!=temp){
            tail = tail->next;
        }
        tail->next = head;
        int deleting = temp->data;
        temp->next = nullptr;
        delete temp;
        return deleting;
    }
    int deleteAtEnd(){
        if(head == nullptr){
            return -1;
        }
        length--;
        Node* curr = head;
        while(curr->next->next!=head){
            curr = curr->next;
        }
        Node* temp = curr->next;
        curr->next = head;
        int deleting = temp->data;
        temp->next = nullptr;
        delete temp;
        return deleting;
    }
    int deleteAtPosition(int pos){
        if(pos<1 || pos>length){
            cout << "Invalid position!" << endl;
            return -1; 
        }
        if(pos==1){
            return deleteAtBeg();
        }
        if (pos==length){
            return deleteAtEnd();
        }
        Node* curr = head;
        Node* temp;
        for(int i=2; i<pos; i++){
            curr = curr->next;
        }
        temp = curr->next;
        curr->next = curr->next->next;
        int deleting = temp->data;
        temp->next = nullptr;
        delete temp;
        length--;
        return deleting;
    }

    int getLength(){
        return length;
    }

    bool isEmpty(){
        return length==0;
    }

    void printList(){
        if(head==nullptr){
            return;
        }
        Node* temp = head;
        while(true){
            cout<<temp->data<<" ";
            temp = temp->next;
            if(temp==head){
                break;
            }
        }
        cout<<endl;
    }
};
int main(){
    LinkedList ll;

    cout << "Inserting elements at the beginning:" << endl; 
    ll.insertAtBeg(20); 
    ll.insertAtBeg(10); 
    ll.printList(); 
    // Output: 20 10 
    cout<<"Inserting elements at the end:"<<endl;
    ll.insertAtEnd(30); 
    ll.insertAtEnd(40); 
    ll.printList(); 
    // Output: 20 10 30 40 
    cout<<"Inserting element at position 3:"<<endl; 
    ll.insertAtPosition(25, 3); 
    ll.printList(); 
    // Output: 20 10 25 30 40 
    cout<<"Deleting the first element:"<<endl; 
    ll.deleteAtBeg(); 
    ll.printList(); 
    // Output: 10 25 30 40 
    cout<<"Deleting the last element:"<<endl; 
    ll.deleteAtEnd(); 
    ll.printList(); 
    // Output: 10 25 30 
    cout<<"Deleting element at position 2:"<<endl; 
    ll.deleteAtPosition(2); 
    ll.printList(); 
    // Output: 10 30 
    cout<<"Length of the list: " << 
    ll.getLength()<<endl; 
    // Output: 2 
    cout<<"Is the list empty?: " << (ll.isEmpty() ? "Yes" : "No")<<endl; 
    // Output: No 

    return 0;
}