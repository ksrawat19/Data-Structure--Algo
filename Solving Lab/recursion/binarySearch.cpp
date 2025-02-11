#include <iostream>
#include <algorithm>
using namespace std;

bool binarySearch(int* arr,int& size, int beg, int end, int& key){
    if(beg>end) return false;

    int mid = beg + (end - beg) / 2;
    if(arr[mid] == key) return true;
    if(key>arr[mid]){
        return binarySearch(arr, size, mid+1, end, key);
    }else{
        return binarySearch(arr, size, beg, mid-1, key);
    }
}
// wrapper function 
bool binarySearch(int* arr, int& size, int& key){
    int beg = 0; 
    int end = size-1;
    // sort krna mtt bhool be kya kr rha hai, hr baar ka hai tera *sle
    sort(arr, arr+size);
    return binarySearch(arr, size, beg, end, key);
}

int main() {
    int arr[] = {5, 3, 8, 1, 7};
    // int arr[] = {12,23,54,57,88};
    int size = sizeof(arr)/sizeof(arr[0]);

    for(auto i: arr){
        cout<<i<<" ";
    }
    cout<<endl;
    
    int key = 0;
    cout<<"key : "; cin>>key;
    cout<<binarySearch(arr, size, key);
    cout<<endl;

    return 0;
}