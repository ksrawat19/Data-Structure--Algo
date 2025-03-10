#include <iostream>
#include <vector>
using namespace std;

int main(){
    int v; cout<<"vertex : "; cin>>v;
    vector<vector<int>> adjMatrix(v, vector<int>(v, 0));

    int e; cout<<"edges : "; cin>>e;
    for(int i=0; i<e; i++){
        int u, v; cin>>u >>v;
        int weight = 1; 
        if (u < 0 || v < 0) {
            cout << "Invalid edge!" << endl;
            continue;
        }        
        adjMatrix[u][v] = weight;
        // for bidirectional (undirected) graph
        // adjMatrix[v][u] = 1;
    }

    // print 
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}