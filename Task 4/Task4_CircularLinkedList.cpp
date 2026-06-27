
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// Creating a node
class Node {
public:
  string name;
  Node* next = NULL; // by default makes the pointer as null
};

int main() {
  Node* head; // used for loop
  Node* one = new Node(); // initialize nodes and putting them in memory
  Node* two = new Node();
  Node* three = new Node();
  Node* four = new Node();

  // Assign value to names
  one->name = "Aimar";
  two->name = "Ahmad";
  three->name = "Anjana";
  four->name = "Jessy";

  // Connect nodes
  one->next = two;
  two->next = three;
  three->next = four;
  four->next = one; // not necessary

  // print the linked list value
  head = one;
  for (int i = 1; i <= 4; i++) { // checking the next is null or not, if null means it's the last node in the list
    cout << head->name;
    if (i != 4){
        cout << " -> ";
    }
    head = head->next; // goes to the next node
  }
}

