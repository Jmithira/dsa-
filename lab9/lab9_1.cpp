// Program to solve Nene's game problem
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(vector<int>,int);


int main(){
    int t;
    cin>>t;
    while (t--){
        int k,q;
        cin>>k>>q;
        vector<int> a(k);
        for (int i=0; i<k; i++){
            cin>>a[i];
        }

        vector<int> query(q);
        for (int i=0; i<q; i++){
            cin>>query[i];
        }

        for (int pos:query){
            cout<<solve(a,pos)<<" ";
        }
    }
}

// Function to return number of winners 

int solve(vector<int> arr, int n)
{
    int min_idx=arr[0];
    int winners;
    if (n >=min_idx){
        winners = min_idx - 1;
    }
    else if (n < min_idx){
        winners = n;
    }
    
    return winners;
}