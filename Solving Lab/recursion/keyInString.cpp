#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool findKey(string& str, int& n, int i, char& key){
    if(i==n) return false;
    if(str[i]==key) return true;

    return findKey(str, n, i+1, key);
}
int findKeyIndex(string& str, int& n, int i, char& key){
    if(i==n) return -1;
    if(str[i]==key) return i;

    return findKeyIndex(str, n, i+1, key);
}
void keyIndex(string& str, int& n, int i, char& key){
    if(i==n) return;
    if(str[i]==key) cout<<i<<" ";

    keyIndex(str, n, i+1, key);
}
void storeKeyIndex(string& str, int& n, int i, char& key, vector<int>& ans){
    if(i==n) return;
    if(str[i]==key) ans.push_back(i);

    storeKeyIndex(str, n, i+1, key, ans);
}

int main(){
    string str = "ksrawatt";

    int i=0;
    int n = str.length();
    char key='t';
    if(findKey(str, n, i, key)){
        cout<<"found\n";
    }else{
        cout<<"not found\n";
    }
    cout<<findKeyIndex(str, n, i, key)<<endl;
    keyIndex(str, n, i, key); cout<<endl;

    vector<int> ans;
    storeKeyIndex(str, n, i, key, ans);

    for(auto i: ans){
        cout<<i<<" ";
    }
    cout<<endl;
    
    return 0;
}