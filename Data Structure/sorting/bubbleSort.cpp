#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void bubbleSort(vector<int>& nums) {
        int size = nums.size();
        bool swapped;

        for (int i = 0; i < size - 1; i++) {
            swapped = false;
            for (int j = 0; j < size - i - 1; j++) {
                if (nums[j] > nums[j + 1]) {
                    swap(nums[j], nums[j + 1]);
                    swapped = true;
                }
            }
            if (!swapped) break;
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
    s.bubbleSort(nums);
    printArray(nums);

    return 0;
}