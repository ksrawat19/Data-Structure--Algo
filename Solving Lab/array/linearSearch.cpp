#include <iostream>
using namespace std;

bool linearSearch(const int *arr, int _size, int &target){

    for(int i=0; i<_size; i++){
        if(arr[i]==target){
            return true;
        }
    }
    return false;
}

int main(){
    int arr[] = {2,4,6,8,10,12};;
    int size = sizeof(arr)/sizeof(arr[0]);

    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    int target = 0;
    cin>>target;

    if(linearSearch(arr, size, target)){
        cout<<target<<" find";
    }else{
        cout<<target<<" didn't find";
    }

    return 0;
}