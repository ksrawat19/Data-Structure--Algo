#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
    Node* head;
    int length = 0;

public:
    DoublyLinkedList() : head(nullptr) {}

    // Insertion
    void insertAtBeg(int val) {
        Node* newNode = new Node(val);
        length++;
        if (head == nullptr) {
            head = newNode;
            newNode->next = newNode;
            newNode->prev = newNode;
            return;
        }
        Node* tail = head->prev;
        newNode->next = head;
        newNode->prev = tail;
        head->prev = newNode;
        tail->next = newNode;
        head = newNode;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        length++;
        if (head == nullptr) {
            head = newNode;
            newNode->next = newNode;
            newNode->prev = newNode;
            return;
        }
        Node* tail = head->prev;
        newNode->next = head;
        newNode->prev = tail;
        tail->next = newNode;
        head->prev = newNode;
    }

    void insertAtPosition(int val, int pos) {
        if (pos < 1 || pos > length + 1) {
            cout << "Invalid position!" << endl;
            return;
        }
        if (pos == 1) {
            insertAtBeg(val);
            return;
        }
        if (pos == length + 1) {
            insertAtEnd(val);
            return;
        }
        Node* newNode = new Node(val);
        length++;
        Node* curr = head;
        for (int i = 2; i < pos; i++) {
            curr = curr->next;
        }
        newNode->next = curr->next;
        newNode->prev = curr;
        curr->next->prev = newNode;
        curr->next = newNode;
    }

    // Deletion
    int deleteAtBeg() {
        if (head == nullptr) {
            return -1;
        }
        length--;
        Node* tail = head->prev;
        Node* temp = head;
        if (head == head->next) {
            head = nullptr;
        } else {
            head = head->next;
            head->prev = tail;
            tail->next = head;
        }
        int deleting = temp->data;
        delete temp;
        return deleting;
    }

    int deleteAtEnd() {
        if (head == nullptr) {
            return -1;
        }
        length--;
        Node* tail = head->prev;
        if (head == tail) {
            head = nullptr;
        } else {
            Node* newTail = tail->prev;
            newTail->next = head;
            head->prev = newTail;
        }
        int deleting = tail->data;
        delete tail;
        return deleting;
    }

    int deleteAtPosition(int pos) {
        if (pos < 1 || pos > length) {
            cout << "Invalid position!" << endl;
            return -1;
        }
        if (pos == 1) {
            return deleteAtBeg();
        }
        if (pos == length) {
            return deleteAtEnd();
        }
        Node* curr = head;
        for (int i = 2; i < pos; i++) {
            curr = curr->next;
        }
        Node* temp = curr->next;
        curr->next = curr->next->next;
        curr->next->prev = curr;
        int deleting = temp->data;
        delete temp;
        length--;
        return deleting;
    }

    // Utility
    int getLength() {
        return length;
    }

    bool isEmpty() {
        return length == 0;
    }

    void printList() {
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
    void printListReverse() {
        if (head == nullptr) {
            return;
        }
        Node* temp = head->prev;

        // Node* temp = head;
        // while(temp->next!=head){
        //     temp = temp->next;
        // }
        do {
            cout << temp->data << " ";
            temp = temp->prev;
        } while (temp != head->prev);
        cout << endl;
    }
};

int main() {
    DoublyLinkedList circular_dll;

    cout << "Inserting elements at the beginning:" << endl;
    circular_dll.insertAtBeg(20);
    circular_dll.insertAtBeg(10);
    circular_dll.printList();
    // Output: 10 20
    cout << "Inserting elements at the end:" << endl;
    circular_dll.insertAtEnd(30);
    circular_dll.insertAtEnd(40);
    circular_dll.printList();
    // Output: 10 20 30 40
    cout << "Inserting element at position 3:" << endl;
    circular_dll.insertAtPosition(25, 3);
    circular_dll.printList();
    // Output: 10 20 25 30 40
    cout << "Deleting the first element:" << endl;
    circular_dll.deleteAtBeg();
    circular_dll.printList();
    // Output: 20 25 30 40
    cout << "Deleting the last element:" << endl;
    circular_dll.deleteAtEnd();
    circular_dll.printList();
    // Output: 20 25 30
    cout << "Deleting element at position 2:" << endl;
    circular_dll.deleteAtPosition(2);
    circular_dll.printList();
    // Output: 20 30
    cout << "Length of the list: " << circular_dll.getLength() << endl;
    // Output: 2
    cout << "Is the list empty?: " << (circular_dll.isEmpty() ? "Yes" : "No") << endl;
    // Output: No

    circular_dll.printListReverse();

    return 0;
}