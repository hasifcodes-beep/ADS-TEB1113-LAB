#include <iostream>
#include <string>
using namespace std;

#define MAX 5   // Capacity (one extra slot to distinguish full/empty)

class Queue {
private:
    string arr[MAX];   // Array to hold queue elements
    int front;         // Index of the front element
    int rear;          // Index of the rear element
    int count;         // Number of elements currently in queue

public:
    // Constructor – initialises empty queue
    Queue() {
        front = 0;
        rear = -1;
        count = 0;
    }

    // Check if the queue is full
    bool isFull() {
        return count == MAX;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return count == 0;
    }

    // Push (enqueue) an element at the rear
    void push(string value) {
        if (isFull()) {
            cout << "Queue Overflow! Cannot push \"" << value << "\"" << endl;
            return;
        }
        // Move rear circularly
        rear = (rear + 1) % MAX;
        arr[rear] = value;
        count++;
        cout << "\"" << value << "\" enqueued." << endl;
    }

    // Pop (dequeue) the front element
    void pop() {
        if (isEmpty()) {
            cout << "Queue Underflow! Cannot pop." << endl;
            return;
        }
        string dequeued = arr[front];
        // Move front circularly
        front = (front + 1) % MAX;
        count--;
        cout << "\"" << dequeued << "\" dequeued." << endl;
    }

    // Peek at the front element without removing it
    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty. Nothing to peek." << endl;
            return;
        }
        cout << "Front element is: \"" << arr[front] << "\"" << endl;
    }

    // Display all elements from front to rear
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue elements (front to rear): ";
        int index = front;
        for (int i = 0; i < count; i++) {
            cout << "\"" << arr[index] << "\" ";
            index = (index + 1) % MAX;
        }
        cout << endl;
    }
};

// Driver program to test the queue with the given data
int main() {
    Queue q;

    // Push the four given names
    q.push("Aimar");
    q.push("Ahmad");
    q.push("Anjana");
    q.push("Jessy");
    cout << endl;

    // Display the queue
    q.display();
    cout << endl;

    // Peek at the front
    q.peek();
    cout << endl;

    // Dequeue two elements
    q.pop();
    q.pop();
    cout << endl;

    // Display again
    q.display();
    cout << endl;

    // Try to pop from an empty queue (demonstrates underflow)
    q.pop();
    q.pop();   // This should trigger underflow
    cout << endl;

    // Peek when empty
    q.peek();

    return 0;
}