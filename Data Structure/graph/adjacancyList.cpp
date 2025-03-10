#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <utility>
using namespace std;

// Class for Unweighted Graphs
class UnweightedGraph {
    unordered_map<int, list<int>> adjList; 
    // Adjacency list for unweighted graphs

public:
    // Add an edge to the unweighted graph
    void addEdge(int u, int v, bool isDirected) {
        adjList[u].push_back(v);
        // Add reverse edge for undirected graphs
        if (!isDirected) {
            adjList[v].push_back(u);
        }
    }

    // Print adjacency list for unweighted graph
    void printAdjList() {
        cout << "Unweighted Graph Adjacency List:" << endl;
        for (auto vertex : adjList) {
            cout << vertex.first << " -> ";
            for (auto neighbor : vertex.second) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
};

// Class for Weighted Graphs
class WeightedGraph {
    unordered_map<int, list<pair<int, int>>> adjList; // Adjacency list for weighted graphs

public:
    // Add an edge to the weighted graph
    void addEdge(int u, int v, int weight, bool isDirected) {
        adjList[u].push_back({v, weight});
        // Add reverse edge for undirected graphs
        if (!isDirected) {
            adjList[v].push_back({u, weight});
        }
    }

    // Print adjacency list for weighted graph
    void printAdjList() {
        cout << "Weighted Graph Adjacency List:" << endl;
        for (auto vertex : adjList) {
            cout << vertex.first << " -> ";
            for (auto neighbor : vertex.second) {
                cout << "(" << neighbor.first << ", " << neighbor.second << ") ";
            }
            cout << endl;
        }
    }
};

int main() {
    // Example: Unweighted Graph
    UnweightedGraph unweightedGraph;
    int edgesUnweighted;
    cout << "Enter number of edges for the unweighted graph: ";
    cin >> edgesUnweighted;

    cout << "Enter edges (u v isDirected) for the unweighted graph:" << endl;
    for (int i = 0; i < edgesUnweighted; i++) {
        int u, v;
        bool isDirected;
        cin >> u >> v >> isDirected;
        unweightedGraph.addEdge(u, v, isDirected);
    }
    unweightedGraph.printAdjList();

    // Example: Weighted Graph
    WeightedGraph weightedGraph;
    int edgesWeighted;
    cout << "\nEnter number of edges for the weighted graph: ";
    cin >> edgesWeighted;

    cout << "Enter edges (u v weight isDirected) for the weighted graph:" << endl;
    for (int i = 0; i < edgesWeighted; i++) {
        int u, v, weight;
        bool isDirected;
        cin >> u >> v >> weight >> isDirected;
        weightedGraph.addEdge(u, v, weight, isDirected);
    }
    weightedGraph.printAdjList();

    return 0;
}

// int main() {
//     int v; // Number of vertices
//     cout << "Enter the number of vertices: ";
//     cin >> v;

//     // Declare adjacency list
//     vector<vector<int>> adjList(v);

//     int e; // Number of edges
//     cout << "Enter the number of edges: ";
//     cin >> e;

//     // Input edges
//     cout << "Enter edges (u v):" << endl;
//     for (int i = 0; i < e; i++) {
//         int u, v;
//         cin >> u >> v;

//         // Add edge u -> v
//         adjList[u].push_back(v);

//         // Uncomment the next line for undirected graphs
//         // adjList[v].push_back(u);
//     }

//     // Print adjacency list
//     cout << "Adjacency List:" << endl;
//     for (int i = 0; i < v; i++) {
//         cout << i << " -> ";
//         for (auto neighbor : adjList[i]) {
//             cout << neighbor << " ";
//         }
//         cout << endl;
//     }

//     return 0;
// }
