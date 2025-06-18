// 283. Move Zeroes, while maintaining the relative order of the non-zero elements.
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // void moveZeros(vector<int>& nums) {
    //     int n = nums.size();
    //     if(n<=1) return;

    //     int i=0; int j=0;
    //     while(j<n){
    //         if(nums[j]!=0){
    //             swap(nums[i], nums[j]);
    //             i++;
    //         }
    //         j++;
    //     }
    // }

    // M2
    void moveZeros(vector<int>& nums) {
        int n = nums.size();
        int inserPos = 0;
        for(int i=0; i<n; i++){
            if(nums[i]!=0){
                nums[inserPos] = nums[i]; 
                inserPos++;
            }
        }
        while(inserPos<n) nums[inserPos++]=0;
    }
};

void print(const vector<int>& nums){
    for(int it: nums) cout<<it<<" ";
    cout<<endl;
}

int main() {
    Solution s;
    vector<int> nums{0,1,0,3,12};

    print(nums);
    s.moveZeros(nums);
    print(nums);

    return 0;
}