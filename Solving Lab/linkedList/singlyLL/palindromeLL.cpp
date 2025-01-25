// 📂 Program 3: Palindrome Linked List (Leetcode-234)

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

    Node* reverse(Node* list){
        if(!list || !list->next){
            return list;
        }
        Node* prev = nullptr;
        Node* curr = list;
        while(curr!=nullptr){
            list = list->next;
            curr->next = prev;
            prev = curr;
            curr = list;
        }
        list = prev;
        return list;
    }

    Node* copyList(Node* head) {
    if (!head) return nullptr;

    Node* newHead = new Node(head->data);
    Node* curr = head->next;
    Node* newCurr = newHead;

    while (curr != nullptr) {
        newCurr->next = new Node(curr->data);
        newCurr = newCurr->next;
        curr = curr->next;
    }
    return newHead;
}

/*
Approach 1: Optimal 
NOTE: Problem in this approach ki hum original linked list ko change kar rhe hai jo ek bad practice hoti hai (linkedList ki copy bna lo to, without modifying the original list)
Step 1: Break linked list into 2 halfs
Step 2: Reverse second half of linked list
Step 3: Compare first half and reversed second half

Time Complexity = O(N) + O(N) + O(N) = O(N)
Space Complexity = O(1)
*/
    bool palindrome(){
        Node* newHead = copyList(head);
        if(!newHead){
            return false;
        }
        Node* firstHalf = newHead;
        Node* secondHalf = newHead;
        int len = length/2;
        for(int i=1; i<len; i++){
            firstHalf = firstHalf->next;
        }
        secondHalf = firstHalf->next;
        firstHalf->next = nullptr;
        firstHalf = newHead;

        secondHalf = reverse(secondHalf);
        bool ans = true;
        while(firstHalf && secondHalf){
            if(firstHalf->data != secondHalf->data){
                return false;
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }
        return ans;
    }
/*
Approach 2: Brute force
Step 1: Reverse linked list
Step 2: Compare actual and reversed linked list

Time Complexity = O(N) + O(N) = O(N)
Space Complexity = O(N)
*/
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
    ll.insertAtEnd(2);
    ll.insertAtEnd(1);
    cout<<"List : ";
    ll.printLL();

    if(ll.palindrome()){
        cout<<"true\n";
    }else{
        cout<<"false\n";
    }

    return 0;
}