#include <bits/stdc++.h>
using namespace std;

// Tree node structure
struct Node {
    string name;
    Node* left;
    Node* right;

    // Constructor to simplify initialization
    Node(const string& n) : name(n), left(nullptr), right(nullptr) {}
};

// In-order traversal: left -> root -> right
void inOrder(Node* root) {
    if (root == nullptr) return;
    inOrder(root->left);
    cout << root->name << " ";
    inOrder(root->right);
}

// Pre-order traversal: root -> left -> right
void preOrder(Node* root) {
    if (root == nullptr) return;
    cout << root->name << " ";
    preOrder(root->left);
    preOrder(root->right);
}

// Post-order traversal: left -> right -> root
void postOrder(Node* root) {
    if (root == nullptr) return;
    preOrder(root->left);
    preOrder(root->right);
    cout << root->name << " ";
}
// Free memory (post-order deletion)
void deleteTree(Node* root) {
    if (root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    // Create nodes
    Node* root = new Node("Aimar");
    Node* node2 = new Node("Ahmad");
    Node* node3 = new Node("Anjana");
    Node* node4 = new Node("Jessy");

    // Build a binary tree
    root->left = node2;        // Aimar's left child = Ahmad
    root->right = node3;       // Aimar's right child = Anjana
    node3->left = node4;       // Anjana's left child = Jessy

    // Print traversals to show the tree structure
    cout << "In-order traversal:   ";
    inOrder(root);
    cout << "\nPre-order traversal:  ";
    preOrder(root);
    cout << "\nPost-order traversal:  ";
    postOrder(root);
    cout << endl;
    
    //     Aimar
    //     /   \
  //    Ahmad Anjana
    //         /
    //      Jessy

    // Clean up
    deleteTree(root);

    return 0;
}