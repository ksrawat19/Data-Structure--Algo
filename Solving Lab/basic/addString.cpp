#include <iostream>
#include <string>
using namespace std;

string addIterative(string n1, string n2){
    int sum = 0;
    int carry = 0;
    string result = "";

    while(n1.size()!=n2.size()){
        if(n1.size()<n2.size()){
            n1.insert(n1.begin(), '0');
        }else{
            n2.insert(n2.begin(), '0');
        }
    }
    for(int i=n1.size()-1; i>=0; i--){
        int l1 =  0;
        int l2 = 0;
        if(i>=0){
            l1 = n1[i] - '0';
            l2 = n2[i] - '0';
        }
        int currSum = carry+l1+l2;
        sum = currSum%10;
        carry = currSum/10;
        result.insert(result.begin(), sum+'0');
    }
    if(carry>0){
        result.insert(result.begin(), carry+'0');
    }
    return result;
}

int addIterative1(string n1, string n2){
    int sum = 0;
    int carry = 0;
    int weight = 1;

    while(n1.size()!=n2.size()){
        if(n1.size()<n2.size()){
            n1.insert(n1.begin(), '0');
        }else{
            n2.insert(n2.begin(), '0');
        }
    }
    for(int i=n1.size()-1; i>=0; i--){
        int l1 = n1[i] - '0';
        int l2 = n2[i] - '0';

        int currSum = carry+l1+l2;
        sum = currSum%10 * weight + sum;
        carry = currSum/10;
        weight *= 10;
    }
    if(carry>0){
        sum = weight*carry+sum;
    }
    return sum;
}

int main() {
    string n1 = "19";
    string n2 = "1";

    cout<< addIterative(n1, n2) <<endl;
    cout<< addIterative1(n1, n2) <<endl;
    
    return 0;
}
// int s1 = stoi(n1);
// int s2 = stoi(n2);
// cout<<s1+s2<<endl;
// 
// char f1 = '9';
// cout<<f1-'0'<<endl;
// 
// char f2 = '3';
// cout<<f2+'0'<<endl;
