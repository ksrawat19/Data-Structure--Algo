#include <iostream>
#include <map>
using namespace std;

int main(){
    map<int, int> m;
    m.insert({1, 9});
    m.insert(make_pair(2, 8));
    m[3] = 7;

    map<int, int> :: iterator it;
    for(it = m.begin(); it!=m.end(); ++it){
        cout<<(*it).first<<" "<<it->second<<" "<<endl;
    }
    cout<<endl;
// O R ------------
    // map<int, int> :: iterator it = m.begin();
    // for(it; it!=m.end(); ++it){
    //     cout<<(*it).first<<" "<<it->second<<" "<<endl;
    // }
    // cout<<endl;
// O R -------------
    for(auto it2 = m.begin(); it2!=m.end(); ++it2){
        cout<<(*it2).first<<" "<<it2->second<<" "<<endl;
    }
    cout<<endl;

// O R -------------
    auto it3 = m.begin();

    m.erase(it3);
    pair<int, int> p = make_pair(4, 6);
    pair<int, int> p1 = {5, 6};
    m.insert(p);
    m.insert(p1);
    
    for(auto value : m){
        cout<<value.first<<" "<<value.second<<" "<<endl;
    }
    cout<<endl;

    // m.clear();

    cout<<m.count(5);
    cout<<endl;
    if(m.find(2) != m.end())
        cout<<"element founded"<<endl;
    else 
        cout<<"not founded"<<endl;

    return 0;
}