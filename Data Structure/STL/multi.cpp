#include <iostream>
#include <map>
#include <set>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::multimap;
using std::multiset;

int main() {
//  M U L T I - M A P

    // Create a multimap that maps integers to strings
    multimap<int, string> myMultimap;

    // Insert elements into the multimap
    myMultimap.insert({1, "one"});
    myMultimap.insert({2, "two"});
    myMultimap.insert({2, "duplicate two"});
    myMultimap.insert({3, "three"});

    // Print elements of the multimap
    cout << "Elements in myMultimap:" << endl;
    for (const auto &pair : myMultimap) {
        cout << pair.first << ": " << pair.second << endl;
    }

//  M U L T I - S E T

    // Create a multiset of integers
    multiset<int> myMultiset;

    // Insert elements into the multiset
    myMultiset.insert(10);
    myMultiset.insert(20);
    myMultiset.insert(20); // Duplicate element
    myMultiset.insert(30);

    // Print elements of the multiset
    cout << "Elements in myMultiset:" << endl;
    for (const auto &elem : myMultiset) {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}