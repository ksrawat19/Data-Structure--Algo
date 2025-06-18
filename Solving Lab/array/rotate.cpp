// 189. Rotate Array (left)
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void reverse(vector<int>& nums, int start, int end){
        while(start<end){
            swap(nums[start++], nums[end--]);
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        k = k%n;
        reverse(nums, 0, n-1);
        reverse(nums, 0, k-1);
        reverse(nums, k, n-1);
    }

    // // M2
    void rotate2(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;

        vector<int>rotatedArr(n, 0);
        for(int i=0; i<n; i++){
            rotatedArr[(k+i) % n] = nums[i];
        }
        for(int j=0; j<n; j++){
            nums[j] = rotatedArr[j];
        }
    }
};

void print(const vector<int>& nums){
    for(int it: nums) cout<<it<<" ";
    cout<<endl;
}

int main() {
    Solution s;
    vector<int> nums{1,2,3,4,5,6,7};
    int k = 3;

    print(nums);
    s.rotate2(nums, k);
    print(nums);

    return 0;
}