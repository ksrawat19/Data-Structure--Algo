// Union of two sorted arrays
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();

        vector<int> unionArr;
        int i=0;
        int j=0;

        while(i<size1 && j<size2){
            if(i>0 && nums1[i]==nums1[i-1]) { i++; continue; }
            if(j>0 && nums2[j]==nums2[j-1]) { j++; continue; }

            if(nums1[i]<nums2[j]) unionArr.push_back(nums1[i++]);
            else if(nums1[i]>nums2[j]) unionArr.push_back(nums2[j++]);
            else{
               unionArr.push_back(nums1[i]);
               i++; j++; 
            }
        }

        while(i<size1){
            if(i==0 || nums1[i]!=nums1[i-1]){
                unionArr.push_back(nums1[i]);
            }
            i++;
        }
        while(j<size2){
            if(j==0 || nums2[j]!=nums2[j-1]){
                unionArr.push_back(nums2[j]);
            }
            j++;
        }
        return unionArr;
    }
};

void print(const vector<int>& nums){
    for(int it: nums) cout<<it<<" ";
    cout<<endl;
}

int main() {
    Solution s;
    vector<int> nums1{3, 4, 6, 7, 9, 9};
    vector<int> nums2{1, 5, 7, 8, 8};

    print(nums1);
    print(nums2);

    print(s.unionArray(nums1, nums2));

    return 0;
}