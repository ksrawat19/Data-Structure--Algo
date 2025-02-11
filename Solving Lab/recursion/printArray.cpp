#include <iostream>
using namespace std;

void printArray(int *arr, int n){
    if(n==0) return;

    cout<<arr[0]<<" ";
    printArray(arr+1, n-1);
}

void printArrayReverse(int *arr, int n){
    if(n==0) return;

    printArrayReverse(arr+1, n-1);
    cout<<arr[0]<<" ";
}

int main(){
    int arr[] = {12,13,25,18,15};
    int size = sizeof(arr)/sizeof(arr[0]);

    printArray(arr, size);
    cout<<endl;
    printArrayReverse(arr, size);

    return 0;
}