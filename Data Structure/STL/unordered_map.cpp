#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
    unordered_map<int, string> um = {{1, "khem"}};
    pair<int, string> p = make_pair(2, "pritam");
    um[3] = "rawat";
    um.insert(p);

    for(auto value : um){
        cout<<value.first<<" "<<value.second<<" "<<endl;
    }
    cout<<um[3]<<endl;
    cout<<um.count(3)<<endl;

    cout << "Elements in um:" << endl;
    for (const auto &pair : um) {
        cout << pair.first << ": " << pair.second << endl;
    }

    // Accessing elements by key
    cout << "Element with key 2: " << um[2] << endl;

    // Check if a key exists
    int key = 4;
    if (um.count(key)) {
        cout << "Key " << key << " exists in the unordered_map." << endl;
    } else {
        cout << "Key " << key << " does not exist in the unordered_map." << endl;
    }

    // Find an element in the unordered_map
    auto it = um.find(3);
    if (it != um.end()) {
        cout << "Element found: " << it->first << ": " << it->second << endl;
    } else {
        cout << "Element not found." << endl;
    }

    // Erase an element by key
    um.erase(2);
    cout << "Elements in um after erasing key 2:" << endl;
    for (const auto &pair : um) {
        cout << pair.first << ": " << pair.second << endl;
    }

    return 0;
}