#include <iostream>
#include <unordered_map>
#include <list>
#include <stack>
using namespace std;

template <class T>
class Graph{
    unordered_map<T, list<T>> edgeL;

    public:
    void addEdge(T u, T v, bool directed){
        edgeL[u].push_back(v);
        if(!directed){
            edgeL[v].push_back(u);
        }
    }

    void printEdges(){
        for(auto edge: edgeL){
            cout<<edge.first<<" -> ";
            for(auto list: edge.second){
                cout<<list<<", ";
            }
            cout<<endl;
        }
    }   

    void DFSstack(T src){
        stack<T> s;
        s.push(src);
        unordered_map<T, bool> visited;

        while(!s.empty()){
            T front = s.top();
            s.pop();
            if(!visited[front]){
                cout<<front<<" ";
                visited[front] = true;
            }
        
            for(auto neighbour: edgeL[front]){
                if(!visited[neighbour]){
                    s.push(neighbour);
                }
            }
        }
    }

    void dfsRecursive(T src, unordered_map<T, bool>& visited){
        cout<<src<<" ";
        visited[src] = true;
        for(auto neighbour: edgeL[src]){
            if(!visited[neighbour]){
                dfsRecursive(neighbour, visited);
            }
        }
    }
    void DFS(T src){
        unordered_map<T, bool> visited;
        dfsRecursive(src, visited);
    }
};

int main(){
    Graph<char> g;
    g.addEdge('a', 'b', 0);
    g.addEdge('a', 'c', 0);
    g.addEdge('b', 'd', 0);
    g.addEdge('c', 'd', 0);
    g.addEdge('d', 'e', 0);

    g.printEdges(); cout<<endl;

    // FOR CONNECTED GRAPH
    cout<<"DFS -> "; g.DFS('a'); cout<<endl;
    cout<<"DFS -> "; g.DFSstack('a'); cout<<endl;

    return 0;
}