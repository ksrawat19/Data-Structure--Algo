// 136. Single Number
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int single = 0;

        for(int num: nums){
            single ^= num;
        }
        return single;
    }
};

void print(const vector<int>& nums){
    for(int it: nums) cout<<it<<" ";
    cout<<endl;
}

int main() {
    Solution s;
    vector<int> nums{6,6,4,1,2,1,2};
    int k = 3;

    print(nums);
    cout<<""<<s.singleNumber(nums);

    return 0;
}
// ALSO
// M2 -> using hashMap
// M3 -> by sorting array