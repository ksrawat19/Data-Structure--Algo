#include <iostream>
#include <string>
using namespace std;

void reverseString(string& str, int s, int e){
    if(s>=e){
        return;
    }
    swap(str[s], str[e]);
    return reverseString(str, s+1, e-1);
}

int main() {
    string str = "abcde";
    cout<<str<<endl;

    int s = 0;
    int e = str.length()-1;
    reverseString(str, s, e);
    cout<<str<<endl;

    return 0;
}