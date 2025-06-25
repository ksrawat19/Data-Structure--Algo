#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = rear = nullptr;
    }

    void enqueue(int val) {
        Node* newNode = new Node(val);
        if (rear == nullptr) {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == nullptr)
            rear = nullptr;
        delete temp;
    }

    int frontVal() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return front->data;
    }
    int back() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return rear->data;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void display() {
        Node* temp = front;
        cout << "Queue: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }

    ~Queue() {
        while (!isEmpty())
            dequeue();
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();  // Output: 10 20 30

    q.dequeue();
    q.display();  // Output: 20 30

    cout << "Front element: " << q.frontVal() << endl; // Output: 20
    cout << "Rear element: " << q.back() << endl; // Output: 30

    return 0;
}
