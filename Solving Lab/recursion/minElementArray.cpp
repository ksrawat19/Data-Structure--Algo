#include <iostream>
#include <climits>
using namespace std;

int findMin(int *arr, int n, int i){
    if(i==n) return arr[i];

    return min(arr[i], findMin(arr, n, i+1));
}
int findMin(int *arr, int n){
    int i=0;
    return findMin(arr, n-1, i);
}

int findMin(int *arr, int n, int i, int minElement){
    if(i==n) return minElement;

    if(arr[i]<minElement) minElement=arr[i];

    return findMin(arr, n, i+1, minElement);
}
int findMin2(int *arr, int n){
    int i=0;
    int minElement = INT_MAX;
    return findMin(arr, n, i, minElement);

}
int main(){
    int arr[] = {12,13,25,18,21};
    int size = sizeof(arr)/sizeof(arr[0]);

    cout<<findMin(arr, size)<<endl;

    cout<<findMin2(arr, size)<<endl;

    return 0;
}