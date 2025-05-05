#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

// Function to determine minimum number of moves 
int solve() {
    int num_elements;
    cout<<"Enter number of elements: ";
    cin >> num_elements;
    vector<int> a(num_elements);
    
    cout<<"Enter the elements: ";
    for (int i = 0; i < num_elements; i++) {
        cin >> a[i];
    }

    unordered_set<int> seen;
    int min_prefix = 0;

    
    for (int i = num_elements - 1; i >= 0; i--) {
        if (seen.count(a[i])) break;
        seen.insert(a[i]);
        min_prefix++;
    }
    
    int min_moves = num_elements - min_prefix;
    return min_moves;
    
}

int main() {
    

    int n_testcases;
    cout<<"Enter the number of testcases:";
    cin >> n_testcases;
    while (n_testcases--) {
        cout<<solve()<<endl;
    }

    return 0;
}
