// 📂 Program : Best Time to Buy and Sell Stock (Leetcode-121)
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        // M E T H O D 1
        // int maxProfit(vector<int>& prices) {
        //     int maxProfit = INT_MIN;
        //     for(int i=0; i<prices.size(); i++){
        //         for(int j=i+1; j<prices.size(); j++){
        //             int max = prices[j] - prices[i];
        //             if(max > maxProfit) maxProfit=max;
        //         }
        //     }
        //     return (maxProfit>0)? maxProfit: 0;
        // }

        // M E T H O D 2
        int maxProfit(vector<int>& prices) {
            int minPrice = prices[0];
            int maxPrice = 0;
    
            for(int i=1; i<prices.size(); i++){
                if(prices[i] < minPrice) minPrice = prices[i];
                else if(maxPrice < (prices[i]-minPrice)) maxPrice = prices[i]-minPrice;
            }
            return maxPrice;
        }
};