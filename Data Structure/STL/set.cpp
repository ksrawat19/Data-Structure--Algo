#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
    set<int> mySet;

    mySet.insert(10);
    mySet.insert(20);
    mySet.insert(30);
    mySet.insert(20); // Duplicate element, will not be added

    // Print elements of the set
    cout << "Elements in mySet:" << endl;
    for (const auto &elem : mySet) {
        cout << elem << " ";
    }
    cout << endl;

    // Check if an element is present in the set
    int key = 20;
    if (mySet.count(key)) {
        cout << key << " is present in the set." << endl;
    } else {
        cout << key << " is not present in the set." << endl;
    }

    // Find an element in the set
    auto it = mySet.find(30);
    if (it != mySet.end()) {
        cout << "Element found: " << *it << endl;
    } else {
        cout << "Element not found." << endl;
    }

    // Erase an element from the set
    mySet.erase(10);
    cout << "Elements in mySet after erasing 10:" << endl;
    for (const auto &elem : mySet) {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}
