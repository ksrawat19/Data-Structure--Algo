#include <iostream>
#include <vector>
using namespace std;

int maxSumOfNonAdjacentElements(vector<int>& v, int size, int i){
    if(i>=size){
        return 0;
    }
    // include
    int a1 = v[i] + maxSumOfNonAdjacentElements(v, size, i+2);
    // exclude
    int a2 = maxSumOfNonAdjacentElements(v, size, i+1);
    return max(a1, a2);
}

int main() {
    vector<int>v {2, 1, 4, 9};

    cout<< maxSumOfNonAdjacentElements(v, v.size(), 0) <<endl;

    return 0;
}