// recursive approach
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void insertionSortR(vector<int>& nums, int n) {
        if(n<=1) return;

        insertionSortR(nums, n-1);

        int key = nums[n-1];
        int i = n-2;
        while(i>=0 && nums[i]>key){
            nums[i+1] = nums[i];
            i--;
        }
        nums[i+1] = key;
    }
};
void printArray(const vector<int>& nums) {
    for (auto i : nums) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    Solution s;
    
    vector<int> nums{7, 4, 1, 3, 2};
    int n = nums.size();
    printArray(nums);
    s.insertionSortR(nums, n);
    printArray(nums);

    return 0;
}