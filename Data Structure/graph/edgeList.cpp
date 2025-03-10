#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

class Graph{
    private:
    vector<tuple<int, int, int>> edgeList;

    public:
    void addEdge(int u, int v, int weight=1){
        edgeList.push_back({u, v, weight});
    }

    // print
    void printEdgeList(){
        for(auto edge : edgeList){
            cout<< get<0>(edge)<<" -> "<< get<1>(edge)<< " (Weight: "<< get<2>(edge)<< ")\n";
        }
    }
};

int main(){
    Graph g;

    int edge = 0; cout<<"Enter the number of edges: "; cin>>edge;

    cout<<"Enter edges (u v weight): \n";
    for(int i=0; i<edge; i++){
        int u, v, weight; 
        cin>>u>> v>> weight;
        g.addEdge(u, v, weight);
    }

    // print
    cout<<"Edge List:\n";
    g.printEdgeList();

    return 0;
}

// Enhancements:
//              INVALID EDGES
//              BIDIRECTIONAL
//              SORT IT 
//              vector<array<int, 3>> edgeList; WILL MORE MEMORY EFFICENT