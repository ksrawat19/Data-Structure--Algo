#include <iostream>
using namespace std;

int main(){
    int n = 5;

    for(int i=0; i<n; i++){
        if(i==0){
            cout<<i+1<<" ";
        }else if(i==n-1){
            for(int j=0; j<n; j++){
            cout<<j+1<<" ";
            }
        }else{
            for(int j=0; j<i+2; j++){
                if(j==0){
                    cout<<j+1<<" ";
                }
                else if(j==i+1){
                    cout<<j<<" ";
                }else{
                    cout<<"  ";
                }
            }
        }
        cout<<endl;
    }
    return 0;
}