// 485. Max Consecutive Ones
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();

        int count = 0, maxCount = 0;
        for(int num: nums){
            maxCount = max(maxCount, (num == 1) ? ++count : (count = 0));
            // which is -->
            // count = (num == 1) ? count+1 : 0;
            // maxCount = max(maxCount, count);
        }
        return maxCount;
    }
};

void print(const vector<int>& nums){
    for(int it: nums) cout<<it<<" ";
    cout<<endl;
}

int main() {
    Solution s;
    vector<int> nums{1,1,0,1,1,1,0,1};

    print(nums);
    cout<<""<<s.findMaxConsecutiveOnes(nums);

    return 0;
}