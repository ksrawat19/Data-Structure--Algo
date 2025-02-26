// 📂 Program : Best Time to Buy and Sell Stock (Leetcode-121)
#include <iostream>
#include <vector>
using namespace std;

int bestTime(vector<int>& p, int i, int minPrice, int maxPrice){
    if(i>=p.size()) return maxPrice;

    if(p[i] < minPrice) minPrice = p[i];
    else if(maxPrice < p[i]-minPrice) maxPrice = p[i]-minPrice;
    return bestTime(p, i+1, minPrice, maxPrice);
}

int main(){
    vector<int> prices{1, 2};

    cout<< bestTime(prices, 1, prices[0], 0) <<endl;
    return 0;
}