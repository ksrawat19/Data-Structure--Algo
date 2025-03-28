// only if the weight of all the edges is same
#include <iostream>
#include <unordered_map>
#include <list>
#include <utility>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
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

    void shortestPathBFS(int src, int destination){
        queue<int> q;
        unordered_map<int, bool> visited;
        unordered_map<int, int> parent;
        q.push(src);
        visited[src] = true;
        parent[src] = -1;

        bool found = false;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            for(auto neighbour: adjList[front]){   
                if(!visited[neighbour.first]){
                    visited[neighbour.first] = true;
                    parent[neighbour.first] = front;
                    q.push(neighbour.first);
                }
            }
            if(visited[destination]){
                found = true;
                break;
            }
        }
        if(found){
            // vector<int> v;
            // while(destination!=-1){
            //     v.push_back(destination);
            //     destination = parent[destination];
            // }
            // reverse(v.begin(), v.end());
            // for(auto path: v){
            //     cout<<path<<", ";
            // }
            stack<int> s;
            while(destination!=-1){
                s.push(destination);
                destination= parent[destination];
            }
            while(!s.empty()){
                cout<<s.top()<<", ";
                s.pop();
            }
        }else{
            cout<<"not found"<<endl;
        }
    }
};
int main(){
    Graph g;
    g.addEdge(0,1,1,1);
    g.addEdge(0,2,1,1);
    g.addEdge(0,3,1,1);
    g.addEdge(1,4,1,1);
    g.addEdge(4,5,1,1);
    g.addEdge(2,5,1,1);
    g.addEdge(3,6,1,1);
    g.addEdge(6,5,1,1);
    g.printAdjList();

    g.shortestPathBFS(0, 5);

    return 0;
}