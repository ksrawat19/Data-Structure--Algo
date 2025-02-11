#include <iostream>
#include <climits>
using namespace std;

bool sortOrNot(int* arr, int size, int i){
    if(i==size) return true;

    if(arr[i-1]<=arr[i]){
        return sortOrNot(arr, size, i+1);
    }
    return false;
}

int main() {
    int arr[] = {12,13,14,18,25};
    // int arr[] = {1, 3, 2, 4, 5};

    int size = sizeof(arr)/sizeof(arr[0]);
    if(sortOrNot(arr, size, 1)){
        cout<<"sorted\n";
    }else{
        cout<<"not sorted\n";
    }

    return 0;
}