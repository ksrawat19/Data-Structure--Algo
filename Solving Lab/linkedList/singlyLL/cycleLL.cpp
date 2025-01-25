// 📂 Program 4: Linked List Cycle (Leetcode-141)

#include <iostream>
#include <unordered_set>
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
// M1 "hare and tortoise" approach ( two pointer method)
    bool isCycle(){
        if(!head || !head->next){
            return false;
        }
        Node* slow = head;
        Node* fast = head;

        while(fast!=nullptr){
            fast = fast->next;
            if(fast!=nullptr){
                fast = fast->next;
                slow = slow->next;
            }
            if(slow==fast){
                return true;
            }
        }
        return false;
    }
// M2 using hash-tables or set (Using a set is more straightforward for this problem)
    bool isCycle2(){
        if(!head || !head->next){
            return false;
        }
        unordered_set<Node*> nodes;
        Node* curr = head;
        nodes.insert(curr);
        curr = curr->next;

        while(curr!=nullptr){
            if(nodes.find(curr) != nodes.end()){
                return true;
            }
            nodes.insert(curr);
            curr = curr->next;
        }
        return false;
    }
};
int main() {
    LinkedList ll;

    ll.insertAtEnd(1);
    ll.insertAtEnd(2);
    ll.insertAtEnd(3);
    ll.insertAtEnd(2);
    ll.insertAtEnd(1);

    if(ll.isCycle2()){
        cout<<"true\n";
    }else{
        cout<<"false\n";
    }

    return 0;
}