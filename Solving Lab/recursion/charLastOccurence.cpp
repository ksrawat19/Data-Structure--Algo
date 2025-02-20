#include <iostream>
#include <string>
using namespace std;

// left to right
void lastOccurenceLtR(string str, int length, char target, int i, int& ans){
    if(i>=length){
        return;
    }
    if(str[i]==target) ans=i;
    return lastOccurenceLtR(str, length, target, i+1, ans);
}
// right to left
void lastOccurenceRtL(string str, char target, int i, int& ans){
    if(i<0){
        return;
    }
    if(str[i]==target){
        ans=i;
        return;
    }
    return lastOccurenceRtL(str, target, i-1, ans);
}
// M3 std function -> strrchar()
int main() {
    string str = "abcddedg"; // 6
    
    char target = 'd';
    int ans = -1;
    lastOccurenceLtR(str, str.length(), target, 0, ans);
    cout<<ans<<endl;
    
    target = 's';
    ans = -1;
    lastOccurenceRtL(str, target, str.length()-1, ans);
    cout<<ans<<endl;

    return 0;
}