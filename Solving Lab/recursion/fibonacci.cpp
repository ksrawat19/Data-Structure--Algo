// 📂 509. Fibonacci Number (leetcode)
#include <iostream>
using namespace std;

class Solution {
    public:
        int fib(int n) {
            int n1 = 0;
            int n2 = 1;
            if(n==n1 || n==n2) return n;
            return fib(n-1) + fib(n-2);
        }
};