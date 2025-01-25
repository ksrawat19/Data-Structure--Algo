// 📂 Program 2: Middle of the Linked List (Leetcode-876)
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
    // method 1
    void middle(){
        if(!head || !head->next){
            return;
        }
        int len = (length/2);
        Node* middle = head;
        for(int i=0; i<len; i++){
            middle = middle->next;
        }
        head = middle;
    }
    // method 2 (two-pointer method also "Hare and Tortoise" approach.)
    void middleM2(){
        Node* slow = head;
        Node* fast = head;
        while(fast!=nullptr){
            fast = fast->next;
            if(fast!=nullptr){
                fast = fast->next;
                slow = slow->next;
            }
        }
        head = slow;
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
    // ll.insertAtEnd(5);
    cout<<"Before middle : ";
    ll.printLL();

    ll.middleM2();
    cout<<"After middle : ";
    ll.printLL();

    return 0;
}