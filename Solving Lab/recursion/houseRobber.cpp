// 📂 Program : House Robber (Leetcode-198)
#include <iostream>
#include <vector>
using namespace std;
// using pick--notPick (include-exclude)
class Solution {
    public:
    int pickOrNot(vector<int>& nums, int i){
        if(i>=nums.size()) return 0;

        int pick = nums[i]+pickOrNot(nums, i+2);
        int notPick = pickOrNot(nums, i+1);
        return max(pick, notPick);
    }
    int rob(vector<int>& nums){
        return pickOrNot(nums, 0);
    }
};

int main() {
    Solution solution;
    vector<int> nums = {2, 7, 9, 3, 1};
    cout << "Maximum money that can be robbed: " << solution.rob(nums) << endl;
    return 0;
}
