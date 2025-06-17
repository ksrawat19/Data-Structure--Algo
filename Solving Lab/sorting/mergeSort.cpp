#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums, int low, int mid, int high){
        vector<int> temp;
        int i = low;
        int j = mid+1;

        while(i<=mid && j<=high){
            if(nums[i] < nums[j]){
                temp.push_back(nums[i]);
                i++;
            }else{
                temp.push_back(nums[j]);
                j++;
            }
        }

        while(i<=mid){
            temp.push_back(nums[i]);
            i++;
        }
        while(j<=high){
            temp.push_back(nums[j]);
            j++;
        }

        for(int k=low; k<=high; k++){
            nums[k] = temp[k-low];
        }
    }
    void mergeSortHelper(vector<int>& nums, int low, int high){
        if(low>=high) return;

        int mid = low + (high - low)/2;

        mergeSortHelper(nums, low, mid);
        mergeSortHelper(nums, mid+1, high);
        merge(nums, low, mid, high);
    }
    void mergeSort(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;

        mergeSortHelper(nums, low, high);
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
    
    vector<int> nums = {7, 4, 1, 5, 3};
    printArray(nums);
    s.mergeSort(nums);
    printArray(nums);
    
    return 0;
}