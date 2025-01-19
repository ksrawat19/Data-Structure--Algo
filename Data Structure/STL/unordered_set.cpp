#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

int main() {
    unordered_set<int> myUnorderedSet;

    myUnorderedSet.insert(10);
    myUnorderedSet.insert(20);
    myUnorderedSet.insert(30);
    myUnorderedSet.insert(20); // Duplicate element, will not be added

    // Print elements of the unordered_set
    cout << "Elements in myUnorderedSet:" << endl;
    for (const auto &elem : myUnorderedSet) {
        cout << elem << " ";
    }
    cout << endl;

    // Check if an element is present in the unordered_set
    int key = 20;
    if (myUnorderedSet.count(key)) {
        cout << key << " is present in the unordered_set." << endl;
    } else {
        cout << key << " is not present in the unordered_set." << endl;
    }

    // Find an element in the unordered_set
    auto it = myUnorderedSet.find(30);
    if (it != myUnorderedSet.end()) {
        cout << "Element found: " << *it << endl;
    } else {
        cout << "Element not found." << endl;
    }

    // Erase an element from the unordered_set
    myUnorderedSet.erase(10);
    cout << "Elements in myUnorderedSet after erasing 10:" << endl;
    for (const auto &elem : myUnorderedSet) {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}