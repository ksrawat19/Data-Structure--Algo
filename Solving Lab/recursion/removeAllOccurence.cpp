// 📂 Program : Remove All Occurrences of a Substring (Leetcode-1910)
#include <iostream>
#include <string>
using namespace std;

void removeAllOccurrences(string& s, string& part){
    int pos = s.find(part);
    if(pos == string::npos) return;
    s.erase(pos, part.length());
    return removeAllOccurrences(s, part);
}

int main() {
    string s = "daabcbaabcbc"; // dab
    string part = "abc";

    removeAllOccurrences(s, part);
    cout<<s<<endl;

    return 0;
}