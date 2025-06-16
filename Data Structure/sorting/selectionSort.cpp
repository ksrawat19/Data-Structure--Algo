#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void selectionSort(vector<int>& nums) {
        int size = nums.size();
        int &n = size;
        
        int minIndex;
        for(int i=0; i<n-1; i++){
            minIndex = i;
            for(int j=i+1; j<n; j++){
                if(nums[j] < nums[minIndex]){
                    minIndex = j;
                }
            }
            swap(nums[i], nums[minIndex]);
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
    s.selectionSort(nums);
    printArray(nums);

    return 0;
}