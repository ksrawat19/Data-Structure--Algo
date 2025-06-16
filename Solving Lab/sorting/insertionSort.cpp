#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void insertionSort(vector<int>& nums) {
        int size = nums.size();
        
        for(int i=1; i<size; i++){
            int key = nums[i];
            int j =  i-1;

            while(j>=0 && nums[j]>key){
                nums[j+1] = nums[j];
                j--;
            }
            nums[j+1] = key;
        }
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
    printArray(nums);
    s.insertionSort(nums);
    printArray(nums);

    return 0;
}