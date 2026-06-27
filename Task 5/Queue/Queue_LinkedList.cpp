#include <iostream>
#include <string>
using namespace std;

// Node structure for the linked list
struct Node {
    string data;
    Node* next;
};

class Queue {
private:
    Node* front;   // Pointer to the front (head) of the queue
    Node* rear;    // Pointer to the rear (tail) of the queue

public:
    // Constructor – initialises empty queue
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    // Destructor – deallocates all nodes
    ~Queue() {
        while (!isEmpty()) {
            pop();
        }
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Check if the queue is full (i.e., memory exhausted)
    bool isFull() {
        Node* temp = new(nothrow) Node;
        if (temp == nullptr) {
            return true;   // allocation failed
        }
        delete temp;
        return false;
    }

    // Enqueue (push) an element at the rear
    void push(string value) {
        if (isFull()) {
            cout << "Queue Overflow! Cannot push \"" << value << "\" (memory full)." << endl;
            return;
        }
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if (isEmpty()) {
            // If queue is empty, both front and rear point to the new node
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "\"" << value << "\" enqueued." << endl;
    }

    // Dequeue (pop) the front element
    void pop() {
        if (isEmpty()) {
            cout << "Queue Underflow! Cannot pop." << endl;
            return;
        }
        Node* temp = front;
        string dequeued = temp->data;
        front = front->next;

        // If the queue becomes empty, rear must also be null
        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;
        cout << "\"" << dequeued << "\" dequeued." << endl;
    }

    // Peek at the front element without removing it
    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty. Nothing to peek." << endl;
            return;
        }
        cout << "Front element is: \"" << front->data << "\"" << endl;
    }

    // Display all elements from front to rear
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        Node* current = front;
        cout << "Queue elements (front to rear): ";
        while (current != nullptr) {
            cout << "\"" << current->data << "\" ";
            current = current->next;
        }
        cout << endl;
    }
};

// Driver program to test the linked-list queue
int main() {
    Queue q;

    // Enqueue some names (same as Part A for comparison)
    q.push("Aimar");
    q.push("Ahmad");
    q.push("Anjana");
    q.push("Jessy");
    cout << endl;

    q.display();
    cout << endl;

    q.peek();
    cout << endl;

    // Dequeue two elements
    q.pop();
    q.pop();
    cout << endl;

    q.display();
    cout << endl;

    // Dequeue the rest
    q.pop();
    q.pop();
    cout << endl;

    // Try to pop from empty queue
    q.pop();
    cout << endl;

    // Peek when empty
    q.peek();
    

    return 0;
}