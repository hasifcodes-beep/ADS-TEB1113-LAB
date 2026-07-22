#include <iostream>
using namespace std;

// Node in the adjacency linked list
struct AdjNode {
    int dest;
    AdjNode* next;
    AdjNode(int d) : dest(d), next(nullptr) {}
};

// Graph class with array of linked lists
class Graph {
private:
    int V;                // Number of vertices
    AdjNode** adjList;    // Array of head pointers

public:
    // Constructor
    Graph(int vertices) {
        V = vertices;
        adjList = new AdjNode*[V];
        for (int i = 0; i < V; i++)
            adjList[i] = nullptr;
    }

    // Destructor to free memory
    ~Graph() {
        for (int i = 0; i < V; i++) {
            AdjNode* curr = adjList[i];
            while (curr) {
                AdjNode* temp = curr;
                curr = curr->next;
                delete temp;
            }
        }
        delete[] adjList;
    }

    // Add an edge (undirected by default, set directed=true for directed)
    void addEdge(int src, int dest, bool directed = false) {
        // Add edge from src to dest
        AdjNode* newNode = new AdjNode(dest);
        newNode->next = adjList[src];
        adjList[src] = newNode;

        // If undirected, add reverse edge
        if (!directed) {
            AdjNode* newNode2 = new AdjNode(src);
            newNode2->next = adjList[dest];
            adjList[dest] = newNode2;
        }
    }

    // Print the graph
    void printGraph() {
        for (int i = 0; i < V; i++) {
            cout << "Vertex " << i << ": ";
            AdjNode* curr = adjList[i];
            while (curr) {
                cout << curr->dest << " -> ";
                curr = curr->next;
            }
            cout << "NULL" << endl;
        }
    }
};

int main() {
    // Create a graph with 5 vertices
    Graph g(5);

    // Add edges (undirected by default)
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
\

    cout << "Adjacency List (Undirected Graph):" << endl;
    g.printGraph();

    return 0;
}