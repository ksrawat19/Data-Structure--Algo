#include <iostream>
using namespace std;

int main(){
    int num = 10;
    // cin>>num;
    int n = num/2;

    for(int i=0; i<n; i++){
        for(int j=0; j<n-1-i; j++){
            cout<<" ";
        }
        //* BEFORE
        // for(int j=0; j<1; j++){
        //     cout<<"* ";
        // }
        // for(int j=3; j<(2*i)+1; j++){
        //     cout<<" ";
        // }
        // for(int j=0; j<1; j++){
        //     if(i!=0){
        //         cout<<"* ";
        //     }
        // }
        //* AFTER
        for(int j=0; j<n; j++){
            if(j==0 || j==i){
                cout<<"* ";
            }else{
                cout<<"  ";
            }
        }
        cout<<endl;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            cout<<" ";
        }
        //* BEFORE
        // for(int j=0; j<1; j++){
        //     cout<<"* ";
        // }
        // // (n*2)-(2*i)
        // for(int j=3; j<2*(n-i)-1; j++){
        //     cout << " ";
        // }
        // for(int j=0; j<1; j++){
        //     if(i!=n-1){
        //         cout<<"* ";
        //     }
        // }
        //* AFTER
        for(int j=0; j<n-i; j++){
            if(j==0 || j==n-i-1){
                cout<<"* ";
            }else{
                cout<<"  ";
            }
        }
        cout<<endl;
    }
    return 0;
}