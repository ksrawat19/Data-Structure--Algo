#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // int search(vector<int>& nums, int target) {
    //     int low = 0; 
    //     int high = nums.size()-1;

    //     while(low<=high){
    //         int mid = low + (high - low)/2;
    //         if(nums[mid] == target) return mid;
    //         else if(nums[mid] < target) low=mid+1;
    //         else high=mid-1;
    //     }
    //     return -1;
    // }

    // M2 -> recursive
    int searchHelperR(vector<int>& nums, int low, int high, int target){
        if(low>high) return -1;
        int mid = low + (high - low)/2;

        if(nums[mid] == target) return mid;
        else if(nums[mid]<target){
            return searchHelperR(nums, low+1, high, target);
        } 
        else{
            return searchHelperR(nums, low, mid-1, target);
        } 
    }
    int searchR(vector<int>& nums, int target){
        int low = 0;
        int high = nums.size()-1;

        return searchHelperR(nums, low, high, target);
    }
};

void print(vector<int>& nums){
    for(auto num: nums){
        cout<<num<<" ";
    }
    cout<<endl;
}

int main(){
    Solution s;
    vector<int> nums{-3, 5, 7, 9, 23, 24};
    print(nums);

    int target = 0;
    cin>>target;
    int ans = s.searchR(nums, target);

    cout<<"target's position is: "<<ans<<endl;

    return 0;
}