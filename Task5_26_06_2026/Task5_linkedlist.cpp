#include <iostream>
using namespace std;

// Node structure for the linked list
struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;      // Pointer to the top node

public:
    // Constructor – initialises empty stack
    Stack() {
        top = nullptr;
    }



    // Check if stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // For a linked list, stack is never "full" unless memory is exhausted.
    // We'll check if we can allocate a new node.
    bool isFull() {
        // Try to allocate a temporary node; if it fails, the stack is full.
        Node* temp = new(nothrow) Node;
        if (temp == nullptr) {
            return true;   // memory allocation failed
        }
        delete temp;
        return false;
    }

    // Push a value onto the stack
    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << value << " (memory full)." << endl;
            return;
        }
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = top;
        top = newNode;
        cout << value << " pushed onto stack." << endl;
    }

    // Pop the top element
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop." << endl;
            return;
        }
        Node* temp = top;
        int poppedValue = temp->data;
        top = top->next;
        delete temp;
        cout << poppedValue << " popped from stack." << endl;
    }

    // Peek at the top element
    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty. Nothing to peek." << endl;
            return;
        }
        cout << "Top element is: " << top->data << endl;
    }

    // Display all elements from top to bottom
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        Node* current = top;
        cout << "Stack elements (top to bottom): ";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

// Driver program to test the linked‑list stack
int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.display();

    s.peek();

    s.pop();
    s.pop();
    s.display();

    s.pop();   // underflow
    s.peek();  // empty

    return 0;
}