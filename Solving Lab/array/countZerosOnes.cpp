// Count 0's and 1's in an array
#include <iostream>
using namespace std;

// counting zero's and one's
void countZerosOnes(int *arr, int _size){
    int zeroCount = 0;
    int oneCount = 0;

    for(int i=0; i<_size; i++){
        if(arr[i]==0){
            zeroCount++;
        }else if(arr[i]==1){
            oneCount++;
        }
    }
    cout<<"Zero's : "<<zeroCount<<endl;
    cout<<"One's : "<<oneCount<<endl;
}

int main(){
    int arr[] = {0, 1, 1, 1, 0, 1, 0, 1};
    int size = sizeof(arr)/sizeof(arr[0]);

    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    countZerosOnes(arr, size);

    return 0;
}