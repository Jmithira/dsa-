// Program to increase number of blocks in tower1
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(){
    int n; //no. of towers
    cin>>n;
    vector<int> towers(n);
    
    for (int i=0; i<n;++i){
        cin>>towers[i];
    }

    sort(towers.begin(), towers.end());
    int blocks_t1=towers[0];
    for (int i=1; i<n; ++i){
        int avg_blocks=(blocks_t1+towers[i])/2;
        blocks_t1=avg_blocks + (blocks_t1+towers[i])%2;

    }

    return blocks_t1;


}
int main(){
    int t;
    cin>>t;
    while (t--){
        solve();
    }
    return 0;
}