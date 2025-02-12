#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minimumCoins(vector<int>& v, int coin){
    if(coin<=0){
        return (coin==0)? 0: INT_MAX;
    }
    int minCoin = INT_MAX;

    for(int i=0; i<v.size(); i++){
        int ans = minimumCoins(v, coin-v[i]);
        if(ans!=INT_MAX){
            minCoin = min(minCoin, ans+1);
        }
    }

    return minCoin;
}

int main(){
    vector<int> v{1, 2, 3};
    int coin = 0;
    cout<<"coin : "; cin>>coin;

    cout<<minimumCoins(v, coin)<<endl;   

}
// int minimumCoins(int coin, int i, int a, int b, int c){
//     if(coin==0){
//         return i;
//     }
//     if(coin<0){
//         return INT_MAX;
//     }

//     return min(
//         min(minimumCoins(coin-a, i+1, a, b, c), 
//             minimumCoins(coin-b, i+1, a, b, c)), 
//             minimumCoins(coin-c, i+1, a, b, c)
//         );
// }

// void minimumCoins(int& coin){
//     int ans = 0;
//     cout<<minimumCoins(coin, ans, 1, 2, 3)<<endl;
// }

// int main() {
//     int coin = 0;
//     cout<<"coin : "; cin>>coin;

//     minimumCoins(coin);

//     return 0;
// }