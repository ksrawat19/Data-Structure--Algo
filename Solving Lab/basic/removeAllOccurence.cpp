// 📂 Program : Remove All Occurrences of a Substring (Leetcode-1910)
#include <iostream>
#include <string>
using namespace std;


int main() {
    string s = "daabcbaabcbc"; // dab
    string part = "abc";

    int pos = s.find(part);
    while(pos != string::npos){
        s.erase(pos, part.length());
        pos = s.find(part);
    }
    cout<<s<<endl;

    return 0;
}