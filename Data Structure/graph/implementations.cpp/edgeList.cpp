#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <list>
#include <set>
#include <utility>
#include <tuple>
using namespace std;

int main(){
    // vector<vector<int>>v (5, vector<int>(5));
    vector<vector<int>> edgeListV{
        {0, 1},
        {0, 2},
        {1, 0},
        {1, 3},
        {2, 0},
        {2, 3},
        {3, 1}, 
        {3, 2},
        {3, 4},
        {4, 3}
    };

    int edgeListA[][10] = {
        {0, 1},
        {0, 2},
        {1, 0},
        {1, 3},
        {2, 0},
        {2, 3},
        {3, 1}, 
        {3, 2},
        {3, 4},
        {4, 3}
    };

    int u = 0; int v = 5; int w = 9;

    vector<pair<int, int>> edgeListVp;
    edgeListVp.push_back({u, v});

    vector<tuple<int, int, int>> edgeListVpW;
    edgeListVpW.push_back({u, v, w});

    list<pair<int, int>> edgeListL;
    // edgeListL.push_back(make_pair(u, v));
    edgeListL.push_back({u, v});

    list<tuple<int, int, int>> edgeList;
    edgeList.push_back({u, v, w});  // Add weighted edges dynamically

    
    map<pair<int, int>, int> edgeListMW;
    edgeListMW[{u, v}] = w;
    
    set<pair<int, int>> edgeListS;
    edgeListS.insert({u, v});  // Add edges uniquely

    multimap<pair<int, int>, int> edgeListMM;
    edgeListMM.insert({{u, v}, w});  // Add multiple weighted edges between the same nodes
    
    // unordered_map<pair<int, int>, int> edgeListUW;
    // edgeListUW[{u, v}] = w; // need to provide a custom hash function for pair<int, int>.

    // list<vector<int>> v(2);
    // v.push_back({u, v});

    return 0;
}