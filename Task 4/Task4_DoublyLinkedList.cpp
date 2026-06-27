
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// Creating a node
class Node {
public:
  string name;
  Node* next = NULL; // by default makes the pointer as null
  Node* prev = NULL;
};

int main() {
  Node* current; // used for loop
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
  one->prev = NULL;
  one->next = two;
  two->prev = one;
  
  two->next = three;
  three->prev = two;
  
  three->next = four;
  four->prev = three;
  four->next = NULL;
  
  
  cout << "DOUBLY LINKED LIST\n";
  // print the linked list value
  current = one;
  cout << "From 1st to last: \n";
  while (current != NULL) { // checking the next is null or not, if null means it's the last node in the list
    cout << current->name;
    if (current->next != NULL){
    	cout << " -> ";
	}
    current = current->next; // goes to the next node
  }
  cout << endl;
  current = four;
  cout << "From last to 1st: \n";
  while (current != NULL) { 
    cout << current->name;
    if (current->prev != NULL){
    	cout << " -> ";
	}
    current = current->prev; // goes to the previous node

  }
  cout << endl;
}

