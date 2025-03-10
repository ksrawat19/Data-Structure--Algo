#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

template <typename T>
class Graph {
    public:
        unordered_map<T, list<T>> adjList;

        // Add an edge to the graph
        void addEdge(T u, T v, bool direction) {
            adjList[u].push_back(v);
            // Add reverse edge for undirected graphs
            if (direction == 0)
                adjList[v].push_back(u);
        }

        // Print the adjacency list
        void printAdjList() {
            for (auto node : adjList) {
                cout << node.first << " -> ";
                for (auto neighbor : node.second) {
                    cout << neighbor << ", ";
                }
                cout << endl;
            }
        }
};

int main() {
    Graph<char> g;

    // Add edges for a directed graph
    g.addEdge('A', 'B', 1);
    g.addEdge('A', 'C', 1);
    g.addEdge('B', 'C', 1);

    // Print adjacency list
    g.printAdjList();

    return 0;
}