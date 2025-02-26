// 📂 Program : House Robber (Leetcode-198)
#include <iostream>
#include <vector>
using namespace std;
// Using memoization
class Solution {
public:
    int pickOrNot(vector<int>& nums, int i, vector<int>& dp) {
        if (i >= nums.size()) return 0;

        if (dp[i] != -1) {
            return dp[i];
        }
        int pick = nums[i] + pickOrNot(nums, i + 2, dp);
        int notPick = pickOrNot(nums, i + 1, dp);

        dp[i] = max(pick, notPick);
        return dp[i];
    }

    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return pickOrNot(nums, 0, dp);
    }
};

int main() {
    Solution solution;
    vector<int> nums = {2, 7, 9, 3, 1};
    cout << "Maximum money that can be robbed: " << solution.rob(nums) << endl;
    return 0;
}
