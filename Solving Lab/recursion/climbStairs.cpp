// 📂 Program : Climbing Stairs (Leetcode-70)
#include <iostream>
using namespace std;

// Time Limit Exceeded,  31/45 testcases passed
int climbStairs(int n){
    if(n==1 || n==2) return n;

    return (climbStairs(n-1) + climbStairs(n-2));
}

int main(){
    int n;
    cin>>n;
    cout<<climbStairs(n)<<endl;

    return 0;
}