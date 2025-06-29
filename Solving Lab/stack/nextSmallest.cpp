#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextSmallerElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() >= nums[i]) {
            st.pop();
        }

        if (!st.empty()) {
            result[i] = st.top();
        }

        st.push(nums[i]);
    }

    return result;
}

// previous smaller
vector<int> nextSmallerToLeft(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && st.top() >= nums[i]) {
            st.pop();
        }

        if (!st.empty()) {
            result[i] = st.top();
        }

        st.push(nums[i]);
    }

    return result;
}

int main() {
    vector<int> arr = {1, 3, 0, 2, 4};
    vector<int> resRight = nextSmallerElements(arr);
    vector<int> resLeft = nextSmallerToLeft(arr);

    cout << "Next Smallest Elements:\n";
    cout << "Next Smallest Elements to Left:\n";
    for (int val : resRight) {
        cout << val << " ";
    }
    cout << endl;
    for (int val : resLeft) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}