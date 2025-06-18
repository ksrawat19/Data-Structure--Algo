// 1752. Check if Array Is Sorted and Rotated
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();

        int countBreak = 0;
        for(int i=0; i<n; i++){
            if(nums[i] > nums[(i+1) % n]) countBreak++;
            if(countBreak > 1) return false;
        }
        return true;
    }
};

int main() {
    Solution s;
    vector<int> nums = {3,4,5,1,2};

    if(s.check(nums)){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }

    return 0;
}