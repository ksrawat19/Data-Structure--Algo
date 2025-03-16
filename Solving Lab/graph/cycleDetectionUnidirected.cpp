#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <stack>
#include <utility>
using namespace std;

class Graph{
    unordered_map<int, list<int>> edgeL;

    public:
    void addEdge(int u, int v, bool directed){
        edgeL[u].push_back(v);
        if(!directed){
            edgeL[v].push_back(u);
        }
    }
    void printEdges(){
        for(auto edge: edgeL){
            cout<<edge.first<<" - ";
            for(auto list: edge.second){
                cout<<list<<", ";
            }
            cout<<endl;
        }
    }

    void cycleDetection_uniDirectedBFS(int src){
        queue<int> q;
        unordered_map<int, bool> visited;
        unordered_map<int, int> parent;
        q.push(src);
        parent[src] = -1;
        visited[src] = true;

        while(!q.empty()){
            int front = q.front();
            q.pop();

            for(auto neighbour: edgeL[front]){
                if(!visited[neighbour]){
                    q.push(neighbour);
                    visited[neighbour] = true;
                    parent[neighbour] = front;
                }else if(neighbour!=parent[front]){
                    cout<<"cycle is present\n";
                    return;
                }
            }
        }
        cout<<"cycle is absent\n";
    }

    void cycleHelperDFS(int src, unordered_map<int, bool>& visited, unordered_map<int, int>& parent, bool& cyclePresent){
        visited[src] = true;

        for(auto neighbour: edgeL[src]){
            if(!visited[neighbour]){
                parent[neighbour] = src;
                cycleHelperDFS(neighbour, visited, parent, cyclePresent);
                if(cyclePresent){
                    return;
                }
            }else if(parent[src]!= neighbour){
                cyclePresent = true;
                return;
            }
        }
    }
    
    void cycleDetection_uniDirectedDFS(int src){
        unordered_map<int, bool> visited;
        unordered_map<int, int> parent;
        parent[src] = -1;
        
        bool cyclePresent = false;
        cycleHelperDFS(src, visited, parent, cyclePresent);
        if(cyclePresent){
            cout<<"cycle is present2\n";
        }else cout<<"cycle is absent2\n";
    }

    void cycleDetection_uniDirectedDFSstack(int src) {
        stack<pair<int, int>> s;
        unordered_map<int, bool> visited;
        s.push({src, -1});
        
        while (!s.empty()) {
            auto [node, parent] = s.top();
            s.pop();
            visited[node] = true;
    
            for (auto neighbour : edgeL[node]) {
                if (!visited[neighbour]) {
                    s.push({neighbour, node});
                } else if (neighbour != parent) {
                    cout<<"cycle is present2\n";
                    return;
                }
            }
        }
        cout<<"cycle is absent3\n";
    }
};

int main() {
    Graph g;
    g.addEdge(0, 1, 0);
    g.addEdge(1, 2, 0);
    g.addEdge(2, 3, 0);
    g.addEdge(2, 4, 0);
    g.addEdge(3, 4, 0);

    // g.addEdge(0,1,0);
    // g.addEdge(1,2,0);
    // g.addEdge(2,3,0);
    // g.addEdge(3,4,0);
    // g.addEdge(4,0,0);

    g.printEdges(); cout<<endl;

    // UNIDIRECTED
    g.cycleDetection_uniDirectedBFS(0); cout<< endl;
    g.cycleDetection_uniDirectedDFS(0); cout<< endl;
    g.cycleDetection_uniDirectedDFSstack(0); cout<< endl;

    return 0;
}