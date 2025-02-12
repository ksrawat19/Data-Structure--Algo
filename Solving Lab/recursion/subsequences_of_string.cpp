#include <iostream>
#include <string>
using namespace std;

void printSubsequences(const string& str, string output, int i){
    if(i==str.length()){
        cout<<output<<endl;
        return;
    }
    // include OR pick
    output.push_back(str[i]);
    printSubsequences(str, output, i+1);
    // exclude OR not-pick
    output.pop_back();
    printSubsequences(str, output, i+1);

}

int main() {
    string str = "abc";
    string output = "";

    printSubsequences(str, output, 0);

    return 0;
}