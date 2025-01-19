#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>

// Selective using directives
using std::cout;
using std::endl;
using std::string;
using std::unordered_multimap;
using std::unordered_multiset;

int main() {
//  M U L T I - U N O R D E R E D_M A P 

    // Create an unordered_multimap that maps integers to strings
    unordered_multimap<int, string> myUnorderedMultimap;

    // Insert elements into the unordered_multimap
    myUnorderedMultimap.insert({1, "one"});
    myUnorderedMultimap.insert({2, "two"});
    myUnorderedMultimap.insert({2, "duplicate two"});
    myUnorderedMultimap.insert({3, "three"});

    // Print elements of the unordered_multimap
    cout << "Elements in myUnorderedMultimap:" << endl;
    for (const auto &pair : myUnorderedMultimap) {
        cout << pair.first << ": " << pair.second << endl;
    }

//  M U L T I - U N O R D E R E D_S E T 

    // Create an unordered_multiset of integers
    unordered_multiset<int> myUnorderedMultiset;

    // Insert elements into the unordered_multiset
    myUnorderedMultiset.insert(10);
    myUnorderedMultiset.insert(20);
    myUnorderedMultiset.insert(20); // Duplicate element
    myUnorderedMultiset.insert(30);

    // Print elements of the unordered_multiset
    cout << "Elements in myUnorderedMultiset:" << endl;
    for (const auto &elem : myUnorderedMultiset) {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}