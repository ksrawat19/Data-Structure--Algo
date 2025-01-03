#include <iostream>
using namespace std;

int main(){
    int num = 8;
    int n = num/2;

    for(int i=0; i<n; i++){
        for(int j=0; j<(2*i)+1; j++){
            if(j%2!=0){
                cout<<"* ";
            }else{
                cout<<i+1<<" ";
            }
        }
        cout<<endl;
    }
    for(int k=0; k<n; k++){
        for(int s=0; s<2*(n-k)-1; s++){
            if(s%2!=0){
                cout<<"* ";
            }else{
                cout<<n-k<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}