// 📂 Program : Add Strings (Leetcode-415)
#include <iostream>
#include <string>
using namespace std;

string addRecursive(string n1, string n2, int& sum, int& carry, int i, string& result){
    // base case
    if(i<0){
        if(carry>0) result.insert(result.begin(), carry+'0');
        return result;
    }
    int l1 = n1[i] - '0';
    int l2 = n2[i] - '0';

    int currSum = carry+l1+l2;
    sum = currSum%10;
    carry = currSum/10;
    result.insert(result.begin(), sum+'0');
    return addRecursive(n1, n2, sum, carry, i-1, result);
}

string addRecursive(string& n1, string& n2){
    int sum = 0;
    int carry = 0;
    while(n1.size() != n2.size()){
        if(n1.size()<n2.size()){
            n1.insert(n1.begin(), '0');
        }else{
            n2.insert(n2.begin(), '0');
        }
    }
    string result = "";
    return addRecursive(n1, n2, sum, carry, n1.length()-1, result);
}

int main() {
    string n1 = "119";
    string n2 = "12";

    cout<< addRecursive(n1, n2) <<endl;
    
    return 0;
}