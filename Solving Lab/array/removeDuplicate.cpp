// 26. Remove Duplicates from Sorted Array
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();

        int i = 0;
        int j = 1;
        while(j<size){
            if(nums[i] != nums[j]){
                i++;
                swap(nums[i], nums[j]);
            }
            j++;
        }
        return i+1;
    }

    // // friend's code
    // int removeDuplicates(vector<int>& nums) {
    //     int size = nums.size();

    //     int low = 1, high = 1;
    //     while(high<size){
    //         if(nums[high] != nums[high-1]){
    //             nums[low] = nums[high];
    //             low++;
    //         }
    //         high++;
    //     }
    //     return low;
    // }
};

void print(const vector<int>& nums, int k){
    for(int i=0; i<k; i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
}

int main() {
    Solution s;
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};

    int k = s.removeDuplicates(nums);

    print(nums, k);

    return 0;
}