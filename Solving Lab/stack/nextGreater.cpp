#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= nums[i]) {
            st.pop();
        }
        if (!st.empty()) {
            result[i] = st.top();
        }
        st.push(nums[i]);
    }

    return result;
}

// also previos next greater. (just loop left to right)

int main() {
    vector<int> arr = {4, 5, 2, 25};
    vector<int> res = nextGreaterElements(arr);

    cout << "Next Greater Elements:\n";
    for (int val : res) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}