// 268. Missing Number
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        // M1
        // sort(nums.begin(), nums.end());
        // for(int i=0; i<n; i++){
        //     if(nums[i] != i) return i;
        // }
        // return n;

        // M2
        int expectedSum = n*(n+1)/2;
        int actualSum = 0;
        for(int i=0; i<n; i++){
            actualSum += nums[i];
        }
        return (expectedSum - actualSum);

        // M3
        // int missing = n;
        // for(int i=0; i<n; i++){
        //     missing ^= i^nums[i];
        // }
        // return missing;
    }
};

void print(const vector<int>& nums){
    for(int it: nums) cout<<it<<" ";
    cout<<endl;
}

int main() {
    Solution s;
    vector<int> nums{7,0,3,1,5,6,4};

    print(nums);
    cout<<""<<s.missingNumber(nums);

    return 0;
}