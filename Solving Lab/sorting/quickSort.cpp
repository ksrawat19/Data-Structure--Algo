#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int partition(vector<int>& nums, int low, int high){
        int pivot = nums[high];

        int i=low;
        for(int j=low; j<=high; j++){
            if(nums[j] <= pivot){
                swap(nums[j], nums[i]);
                i++;
            }
        }
        return i-1;
    }
    void quickSortHelper(vector<int>& nums, int low, int high){
        if(low>=high) return;

        int pivot = partition(nums, low, high);

        quickSortHelper(nums, low, pivot-1);
        quickSortHelper(nums, pivot+1, high);
    }
    void quickSort(vector<int>& nums) {
        
        int low = 0;
        int high = nums.size()-1;

        quickSortHelper(nums, low, high);
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
    
    vector<int> nums = {3, 7, 8, 5, 2, 1, 9};
    printArray(nums);
    s.quickSort(nums);
    printArray(nums);

    return 0;
}