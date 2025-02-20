#include <iostream>
#include <vector>
using namespace std;

void printSubarrays(const vector<int>& arr) {
    int n = arr.size();
    for (int start = 0; start < n; start++) {
        for (int end = start; end < n; end++) {
            cout << "[";
            for (int k = start; k < end; k++) {
                cout << arr[k] << ", ";
            }
            cout << arr[end] << "]" << endl;
        }
    }
}

int main() {
    vector<int> arr = {1, 2, 3, 4};
    printSubarrays(arr);
    return 0;
}
