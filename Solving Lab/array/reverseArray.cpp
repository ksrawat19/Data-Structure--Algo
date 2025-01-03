// Reverse an array (Two pointer approach)
#include <iostream>
using namespace std;

void reverseArray(int *arr, int _size){
    int low = 0;
    int high = _size-1;

    int temp;
    while(low<high){
        temp = arr[low];
        arr[low] = arr[high];
        arr[high] = temp;
        
        low++;
        high--;
    }
}

void printArray(const int *arr, int _size){
    for(int i=0; i<_size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[] = {20, 4, 15, 2, 6};
    int size = sizeof(arr)/sizeof(arr[0]);

    // *Before reverse
    printArray(arr, size);

    reverseArray(arr, size);

    // *After reverse
    printArray(arr, size);
    
    return 0;
}