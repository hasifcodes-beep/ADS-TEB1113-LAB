
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// Creating a node
struct Node {
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
  four->next = NULL; // not necessary

  // print the linked list value
  head = one;
  while (head != NULL) { // checking the next is null or not, if null means it's the last node in the list
    cout << head->name;
    if (head->next != NULL){
        cout << " -> ";
    }
    head = head->next; // goes to the next node
  }
}

