#include <iostream>
using namespace std;
// TODO ans theek hai but variable name delho apne stupipd
int main(){
    int n = 8;

    for(int i=0; i<n/2; i++){
        for(int j=0; j<((n/2)-1)-i; j++){
            cout<<" ";
        }
        for(int j=0; j<i+1; j++){
            cout<<"* ";
        }
        cout<<endl;
    }
    for(int i=0; i<n/2; i++){
        for(int j=0; j<i; j++){
            cout<<" ";
        }
        for(int j=0; j<(n/2)-i; j++){
            cout<<"* ";
        }
        cout<<endl;
    }
    return 0;
}