// Program to solve stregths problem
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solve(int ,vector<int>&);


int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for (int i=0;i<n; i++){
            cin>>arr[i];
        }
        vector<int> res= solve(n,arr);
        cout<<"Output:";
        for (int i=0; i<n; i++){
            cout<<res[i]<<" ";
        }
        cout<<endl;
    }

    return 0;
}

// Function to solve and return vector
vector<int> solve(int n,vector<int>& arr){
    int max1=*max_element(arr.begin(), arr.end());
    int max2 = 0;
    int flag = 0; 
    for (int i=0; i<n; i++){
        if (arr[i]!=max1){
            max2=max(max2,arr[i]);
            flag = 1; 
        }
    }
    if (flag==0){
        max2 = max1;
    }
    vector<int> res(n);
    for (int i=0; i<n; i++){
        if (arr[i]==max1){
            res[i]=arr[i]-max2;
        }
        else{
            res[i]=arr[i]-max1;
        }
    }
    return res;
}
