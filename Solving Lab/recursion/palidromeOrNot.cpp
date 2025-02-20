#include <iostream>
#include <string>
using namespace std;

bool palidromeOrNot(string& str, int s, int e){
    if(s>=e) return true;
    if(str[s]!=str[e]) return false;
    return palidromeOrNot(str, s+1, e-1);
}
// Wrapper Function:
bool palidromeOrNot(string& str){
    return palidromeOrNot(str, 0, str.length()-1);
}

int main() {
    string str = "racecar";

    if(palidromeOrNot(str)){
        cout<<"true\n";
    }else{
        cout<<"false\n";
    }
    return 0;
}