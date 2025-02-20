#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maximumSegment(vector<int>& v, int n){
    if(n<=0){
        return (n==0)? 0: INT_MIN;
    }
    int maxSegment = INT_MIN;
    
    for(int i=0; i<v.size(); i++){
        int ans = maximumSegment(v, n-v[i]);
        if(ans!=INT_MIN){
            maxSegment = max(maxSegment, ans+1);
        }
    }
    return maxSegment;
}

int main(){
    vector<int> v{5 , 2};
    int oakLog = 0;
    cout<<"oakLog : "; cin>>oakLog;

    cout<<maximumSegment(v, oakLog)<<endl;   

}