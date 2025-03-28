// only if the weight of all the edges is same
#include <iostream>
#include <unordered_map>
#include <list>
#include <utility>
#include <stack>
#include <vector>
#include <climits>
using namespace std;

class Graph{
    unordered_map<int, list<pair<int,int>>> adjList;
    public:
    void addEdge(int u, int v, int weight, bool directed){
        adjList[u].push_back({v, weight});
        if(!directed){
            adjList[v].push_back({u, weight});
        }
    }
    void printAdjList(){
        for(auto edge: adjList){
            cout<<edge.first<<" -> ";
            for(auto list: edge.second){
                cout<<"("<<list.first<<", "<<list.second<<"), ";
            }
            cout<<endl;
        }
    }

    void topologicalSort(int src, unordered_map<int, bool>& visited, stack<int>& s){
        visited[src] = true;
        for(auto neighbour: adjList[src]){
            if(!visited[neighbour.first]){
                topologicalSort(neighbour.first, visited, s);
            }
        }
        s.push(src);
    }
    void shortestPathDFS(int src, int destination, int nodes){
        stack<int> s;
        unordered_map<int, bool> visited;
        topologicalSort(src, visited, s);
        
        vector<int> distance(nodes, INT_MAX);
        src = s.top();
        distance[src] = 0;

        while(!s.empty()){
            src = s.top();
            if(distance[src]!=INT_MAX){
                for(auto neighbour: adjList[src]){
                    if(distance[neighbour.first] > distance[src]+neighbour.second){
                        distance[neighbour.first] = distance[src]+neighbour.second;
                    }
                }
            }
            s.pop();
        }
        // for(auto i: distance){
        //     if(i==INT_MAX){
        //         cout<<"INF, ";
        //     }else{
        //         cout<<i<<", ";
        //     }
        // }

        cout << "From source node shortest path is: ";
        cout << ((distance[destination] == INT_MAX) ? "INF" : to_string(distance[destination])) << " "; 
    }
};
int main(){
    Graph g;
    // g.addEdge(0,1,5,1);
    // g.addEdge(0,2,3,1);
    // g.addEdge(2,1,2,1); 
    // g.addEdge(1,3,3,1);
    // g.addEdge(2,4,6,1);
    // g.addEdge(4,3,1,1);
    // g.addEdge(2,3,5,1);

    g.addEdge(0, 1, 2, 1);
    g.addEdge(0, 2, 3, 1);
    g.addEdge(1, 3, 4, 1);
    g.addEdge(4, 5, 6, 1);

    g.printAdjList();

    g.shortestPathDFS(0, 4, 5);

    return 0;
}