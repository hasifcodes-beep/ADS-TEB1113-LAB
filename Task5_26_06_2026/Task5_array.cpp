#include <iostream>
using namespace std;

#define MAX 10   // Maximum size of the stack

class Stack {
private:
    int arr[MAX];   // Array to hold stack elements
    int top;        // Index of the top element (-1 if empty)

public:
    // Constructor – initialises an empty stack
    Stack() {
        top = -1;
    }

    // Check if the stack is full
    bool isFull() {
        return top == MAX - 1;
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Push an element onto the stack
    void push(int value) {
        if (isFull()) { // check overflow
            cout << "Stack Overflow! Cannot push " << value << endl;
            return;
        }
        arr[++top] = value;
        cout << value << " pushed onto stack." << endl;
    }

    // Pop the top element from the stack
    void pop() {
        if (isEmpty()) { // check underflow
            cout << "Stack Underflow! Cannot pop." << endl;
            return;
        }
        cout << arr[top--] << " popped from stack." << endl;
    }

    // Return the top element without removing it
    void peek() {
        if (isEmpty()) { // check underflow
            cout << "Stack is empty. Nothing to peek." << endl;
            return;
        }
        cout << "Top element is: " << arr[top] << endl;
    }

    // Display all elements of the stack (from top to bottom)
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack elements (top to bottom): ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// Main program
int main() {
    Stack s; // init our stack

    s.push(10); // push/insert (at the top)
    s.push(20);
    s.push(30);
    s.display();

    s.peek();

    s.pop();
    s.pop();
    s.display();

    s.pop();   // This will show underflow
    s.peek();  // This will show empty

    return 0;
}