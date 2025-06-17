// Program 01: Find unique element
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// NOTE: only work if one unique element is present in the array, if more than one unique the map will useful!!
int uniqueElement(int *arr, int _size){

    // // Method 1
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
    

    // // Method 2
    // 2,2,10,10,11,12,12,16,16
    vector<int> v(arr, arr + _size);
    sort(v.begin(), v.end());

    for (int i = 0; i < _size; i++) {
        if ((i == 0 || v[i] != v[i - 1]) &&
            (i == _size - 1 || v[i] != v[i + 1])) {
            return v[i];
        }
    }
    return -1;
    
    
    // // Method 3 (using xor)
    // int unique = 0;
    // for(int i=0; i<_size; i++){
    //     unique ^= arr[i];
    // }
    // return (unique)? unique: -1;
}

int main(){
    int arr[] = {2,13,10,2,16,13,16};
    int size = sizeof(arr)/sizeof(arr[0]);

    for(auto i: arr){
        cout<<i<<" ";
    }
    cout<<endl;

    cout<<uniqueElement(arr, size);

    return 0;
}