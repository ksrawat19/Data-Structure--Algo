#include <iostream>
#include <vector>
using namespace std;

int main(){
    int v; cout<<"vertex : "; cin>>v;
    vector<vector<int>> adjacencyMatrix(v, vector<int>(v, 0));
    int e; cout<<"edges : "; cin>>e;

    for(int i=0; i<e; i++){
        int u, v;
        cin>>u >>v;
        adjacencyMatrix[u][v] = 1;
        // adjacencyMatrix[v][u] = 1;
    }

    // print
    for(int i=0; i<v; i++){
        for(int j=0; j<v; j++){
            cout<<adjacencyMatrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}