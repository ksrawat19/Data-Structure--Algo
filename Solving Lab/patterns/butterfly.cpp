#include <iostream>
using namespace std;

int main(){
    int Num = 20; 
    int n = Num/2;

    for(int i=0; i<n; i++){
        for(int j=0; j<i+1; j++){
            cout<<"* ";
        }
        // ((n-1)*2)-(2*i)
        for(int j=0; j<2*(n-1-i); j++){
            cout<<"  ";
        }
        for(int j=0; j<i+1; j++){
            cout<<"* ";
        }
        cout<<endl;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i; j++){
            cout<<"* ";
        }
        // 4*i ki jgh 2*i tk chla skte the aur space ko "  " kr dete -_-
        for(int j=0; j<4*i ; j++){
            cout<<" ";
        }
        for(int j=0; j<n-i; j++){
            cout<<"* ";
        }
        cout<<endl;
    }
    return 0;
}