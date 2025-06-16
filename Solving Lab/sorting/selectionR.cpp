// recursive approach
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void selectionSort(vector<int>& nums,int start, int n) {
        if(start>=n-1) return;

        int minIndex = start;
        for(int i=start+1; i<n; i++){
            if(nums[minIndex] > nums[i]){
                minIndex = i;
            }
        }
        swap(nums[start], nums[minIndex]);
        selectionSort(nums, start+1, n);
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
    s.selectionSort(nums, 0, n);
    printArray(nums);

    return 0;
}