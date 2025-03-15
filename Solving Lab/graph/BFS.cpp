#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;

template <class T>
class Graph{
    unordered_map<T, list<T>> edgeL;

    public:
    void addEdge(T u, T v, bool direction){
        edgeL[u].push_back(v);
        if(!direction){
            edgeL[v].push_back(u);
        }
    }

    void printEdges(){
        for(auto edge : edgeL){
            cout<<edge.first<<" - ";
            for(auto list : edge.second){
                cout<<list<<", ";
            }
            cout<<endl;
        }
    }

    void BFS(T src){
        queue<T> q;
        unordered_map<T, bool> visited;

        q.push(src);
        visited[src] = true;

        while(!q.empty()){
            T front = q.front();
            q.pop();
            cout<<front<<" ";

            for(auto neighbour : edgeL[front]){
                if(!visited[neighbour]){
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
    }
};

int main(){
    Graph<int> g;

    // g.addEdge(0, 1, 0);
    // g.addEdge(0, 2, 0);
    // g.addEdge(0, 3, 0);
    // g.addEdge(1, 2, 0);
    
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(2, 4, 0);
    g.addEdge(3, 0, 1);

    g.printEdges(); cout<<endl;

    // FOR CONNECTED GRAPH
    cout<<"BFS -> "; g.BFS(0); cout<<endl;

    return 0;
}