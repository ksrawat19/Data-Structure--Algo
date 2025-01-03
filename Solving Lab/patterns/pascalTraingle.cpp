#include <iostream>
using namespace std; 

int main(){
    int n = 6;

    for(int i=0; i<n; i++){
        for(int j=0; j<n-i; j++){
            cout<<"  ";
        }
        int coefficient;
        for( int j=0; j<=i; j++){
            if(j==0){
                coefficient = 1;
            }
            else{ 
                coefficient = coefficient*(i-j+1)/j;
            }
            cout << coefficient << "   ";
        }
        cout<<endl;
    }
    return 0;
}

/*
Enter the Number of rows - 6
Pascal's Triangle of 6 rows.
            1   
          1   1   
        1   2   1   
      1   3   3   1   
    1   4   6   4   1   
  1   5   10   10   5   1 
*/
