// Extreme print an array (Two pointer approach)
#include <iostream>
using namespace std;

void xtremePrint(int *arr, int _size){
    int low = 0;
    int high = _size-1;

    //*I wrote
    // while(low<high){
    //     cout<<arr[low]<<" ";
    //     cout<<arr[high]<<" ";

    //     low++;
    //     high--;
    // }
    // if(_size%2!=0){
    //     cout<<arr[low]<<" ";
    // }

    //*My friend wrote
    while(low<=high){
        if(low==high){
            cout<<arr[low]<<" ";  
        }else{
            cout<<arr[low]<<" ";
            cout<<arr[high]<<" ";
        }
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
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr)/sizeof(arr[0]);

    printArray(arr, size);

    xtremePrint(arr, size);

    return 0;
}