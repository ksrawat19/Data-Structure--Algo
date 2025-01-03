// Minimum and maximum number in an array
#include <iostream>
#include <climits>
using namespace std;

int findMin(const int *arr, int _size){
    int min = INT_MAX;

    for(int i=0; i<_size; i++){
        if(arr[i]<min){
            min = arr[i];
        }
    }
    return min;
}
int findMax(const int *arr, int _size){
    int max = INT_MIN;

    for(int i=0; i<_size; i++){
        if(arr[i]>max){
            max = arr[i];
        }
    }
    return max;
}

int main(){
    int arr[8] = {20, 4, 15, 2, 6, 8, 11, 25};
    int size = sizeof(arr)/sizeof(arr[0]);

    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    cout<<"min value : "<<findMin(arr, size)<<endl;
    cout<<"max value : "<<findMax(arr, size)<<endl;

    return 0;
}