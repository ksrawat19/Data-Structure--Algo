// 📂 509. Fibonacci Number (leetcode)
#include <iostream>
using namespace std;

class Solution {
    public:
        int fib(int n) {
            int n1 = 0;
            int n2 = 1;
            if(n==n1 || n==n2) return n;
            int ans = 0;
            for(int i=1; i<n; i++){
                ans = n1+n2;
                n1 = n2;
                n2 = ans;
            }
            return ans;
        }
};