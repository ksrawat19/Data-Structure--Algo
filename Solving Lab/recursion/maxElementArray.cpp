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

int findMax(int *arr, int n, int i, int maxElement){
    if(i==n) return maxElement;

    if(arr[i]>maxElement) maxElement=arr[i];

    return findMax(arr, n, i+1, maxElement);
}
int findMax2(int *arr, int n){
    int i=0;
    int maxElement = 0;
    return findMax(arr, n, i, maxElement);

}
int main(){
    int arr[] = {12,13,25,18,21};
    int size = sizeof(arr)/sizeof(arr[0]);

    cout<<findMax(arr, size)<<endl;

    cout<<findMax2(arr, size)<<endl;

    return 0;
}