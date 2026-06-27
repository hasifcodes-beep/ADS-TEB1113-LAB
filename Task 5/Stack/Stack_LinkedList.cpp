#include <iostream>
using namespace std;

// Node structure for the linked list
class Node {
	public:
    string data;
    Node* next;
};

class Stack {
private:
    Node* top = nullptr;      // Pointer to the top node
    // each stack initialize with an empty node

public:

    // Check if stack is empty
    bool isEmpty() { 
        return top == nullptr;
    }

    // For a linked list, stack is never full unless memory is exhausted, because it's dynamically-sized, unlike array
    // Despite that, this is more hardware-related and hard to happen for modern computers
    // thus, isFull() is not needed


    // Push a value onto the stack
    void push(string value) {

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
        string poppedValue = temp->data;
        top = top->next;
        //delete temp;
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
        cout << "Stack elements (top to bottom): \n";
        while (current != nullptr) {
            cout << current->data << endl;
            current = current->next;
        }
        cout << endl;
    }
};

// Driver program to test the linked‑list stack
int main() {
    Stack s;

    s.push("Aimar");
    s.push("Anjana");
    s.push("Ahmad");
    s.push("Jessy");
    s.display();

    s.peek();

    s.pop();
    s.pop();
    s.pop();
    s.display();
    
	s.pop();
    s.pop();   // underflow
    s.peek();  // empty

    return 0;
}