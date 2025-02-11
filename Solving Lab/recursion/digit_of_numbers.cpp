#include <iostream>
using namespace std;

void digitOfNumbers(int n){
    if(n==0){
        return;
    }
    digitOfNumbers(n/10);
    cout<<n%10<<endl;
}

// wrapper function
void digitOfNumber(int& n){
    if (n == 0) {
        cout << n << endl;
        return;
    }  
    digitOfNumbers(n);
}

int main() {
    // int n = 0647;
    int n = 1902;
    digitOfNumber(n);

    return 0;
}