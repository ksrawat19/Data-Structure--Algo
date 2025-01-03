#include <iostream>
using namespace std;

int main(){
    int row = 3;
    int col = 5;

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout<<"* ";
        }
        cout<<endl;
    }
    return 0;
}