#include <iostream> 
using namespace std;

int main(){
    int n = 5;

    char ch = 'A';
    for(int i=0; i<n; i++) {
        ch = 'A';
        for(int j=0; j<=i; j++) {
            cout << ch++ << " ";
        }
        ch--;
        for(int j=i-1; j>=0; j--) {
            cout << --ch << " ";
        }
        cout << endl;
    }
    return 0;
}