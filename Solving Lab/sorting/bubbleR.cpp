// recursive approach
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void bubbleSortR(vector<int>& nums, int n) {
        if(n==1) return;

        for(int i=0; i<n-1; i++){
            if(nums[i] > nums[i+1]){
                swap(nums[i], nums[i+1]);
            }
        }
        bubbleSortR(nums, n-1);
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
    s.bubbleSortR(nums, n);
    printArray(nums);

    return 0;
}