#include <iostream>
using namespace std;

int main(){
    int num = 8;
    int n = num/2;

    for(int i=0; i<n; i++){
        for(int j=0; j<n-i; j++){
            cout<<"* ";
        }
        for(int j=0; j<(2*i)+1; j++){
            cout<<"- ";
        }
        for(int j=0; j<n-i; j++){
            cout<<"* ";
        }
        cout<<endl;
    }
    for(int k=0; k<n; k++){
        for(int s=0; s<k+1; s++){
            cout<<"* ";
        }
        for(int s=0; s<(2*(n-k))-1; s++){
            cout<<"- ";
        }
        for(int s=0; s<k+1; s++){
            cout<<"* ";
        }
        cout<<endl;
    }
    return 0;
}