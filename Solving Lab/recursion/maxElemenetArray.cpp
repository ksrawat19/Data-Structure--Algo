#include <iostream>
using namespace std;

int findMax(int *arr, int n, int i){
    if(i==n) return arr[i];

    return max(arr[i], findMax(arr, n, i+1));
}
int findMax(int *arr, int n){
    int i=0;
    return findMax(arr, n-1, i);
}

int main(){
    int arr[] = {12,13,25,18,21};
    int size = sizeof(arr)/sizeof(arr[0]);

    cout<<findMax(arr, size)<<endl;

    return 0;
}