// Delete in a Doubly Linked List (GFG)

#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;

    Node(int data): data(data), prev(nullptr), next(nullptr) {}
};

class LinkedList{
    Node* head;

    public:
    LinkedList(): head(nullptr) {}

    void insert(vector<int> &v){
        Node* newNode = nullptr;
        if(head==nullptr){
            newNode = new Node(v[0]);
            head = newNode;
        }
        Node* tail = head;
        for(int i=1; i<v.size(); i++){
            newNode = new Node(v[i]);
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    // index starts from 1, in this question x is position here  
    Node* deleteNode(int x){
        if(head==nullptr) return nullptr;
        
        Node* temp = head;
        for(int i=1; i<x; i++){
            if (temp == nullptr) return nullptr;
            temp = temp->next;
        }
        if(temp->prev!=nullptr){
            temp->prev->next = temp->next;
        }else{
            head = temp->next;
        }
        if(temp->next!=nullptr){
            temp->next->prev = temp->prev;
        }
        delete temp;
        return head;
    }
};

void print(Node* node){
    if(!node){
        return;
    }
    while(node){
        cout<<node->data<<" ";
        node = node->next;
    }
    cout<<endl;
}

int main(){
    vector<int> v {1, 2, 3};
    LinkedList dll;
    dll.insert(v);

    print(dll.deleteNode(2));

    return 0;
}