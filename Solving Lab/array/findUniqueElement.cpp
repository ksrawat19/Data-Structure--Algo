// Program 01: Find unique element
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int uniqueElement(int *arr, int _size){

    // Method 1
    // for(int i=0; i<_size-1; i++){
    //     bool isUnique = true;
    //     for (int j = 0; j < _size; j++) {
    //         if (i != j && arr[i] == arr[j]) {
    //             isUnique = false; 
    //             break; 
    //         } 
    //     }
    //     if(isUnique){
    //         return arr[i];
    //     }
    // }
    // return -1;
    

    // Method 2
    sort(arr, arr+_size);
    // 2,2,10,10,11,12,12,16,16
    vector<int> ans(_size, 0);

    for(int i=0; i<_size; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;



    // Method 3
}

int main(){
    int arr[] = {2,10,11,13,10,2,16,13,16};
    int size = sizeof(arr)/sizeof(arr[0]);

    for(auto i: arr){
        cout<<i<<" ";
    }
    cout<<endl;

    cout<<uniqueElement(arr, size);

    return 0;
}