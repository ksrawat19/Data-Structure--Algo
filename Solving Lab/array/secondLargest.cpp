// find the second largest element in array 
#include <iostream>
#include <climits>
using namespace std;

void secondLargest(int *arr, int _size){

    int max = arr[0];
    for(int i=0; i<_size; i++){
        if(max<arr[i]){
            max = arr[i];
        }
    }
    int secondMax = INT_MIN;
    for(int j=0; j<_size; j++){
        if(secondMax<arr[j] && arr[j]<max){
            secondMax = arr[j];
        }
    }
    cout<<secondMax<<" "<<endl;
}
void secondLargest2(int *arr, int _size){

    int max = arr[0];
    int secondMax = INT_MIN;
    for(int i=0; i<_size; i++){
        if(max<arr[i]){
            secondMax = max;
            max = arr[i];
        }else if(arr[i]<max && secondMax<arr[i]){
            secondMax = arr[i];
        }
    }
    cout<<secondMax<<" "<<endl;
}

void printArray(const int *arr, int _size){
    for(int i=0; i<_size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[] = {90, 50, 20, 20};
    int size = sizeof(arr)/sizeof(arr[0]);

    printArray(arr, size);

    // secondLargest(arr, size);
    secondLargest2(arr, size);

    return 0;
}