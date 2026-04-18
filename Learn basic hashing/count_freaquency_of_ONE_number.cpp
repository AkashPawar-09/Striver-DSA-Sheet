/*
input :    // inputs for array defining 
6
1 2 2 3 1 4

output :   // how many times our query appears
1 -> 2
2 -> 2
3 -> 1
4 -> 1
6 -> 0

--------------------------------------------------------------------------------
input : 
5                   // number of elements 
1 2 3 4 4           // elements want to store in array
3                   // how many numbers want to see frequency 
1 4 3               // elements want to find 

output : 
1                   // 1 ----> 1        // 1 appears 1 time
2                   // 4 ----> 2        // 4 appears 2 times
1                   // 3 ----> 1        // 3 appears 1 time

*/

// Count frequency of ONE number 


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> frequencyQuery(vector<int>& arr, vector<int>& queries) {
        int hash[100000 + 1] = {0}; // adjust size if needed  
        // all values in hash are filled with zeros then it is updated as loop goes      
        // hash -----> array (not a kayword) 
        // Size = 100001 (so we can store values from 0 → 100000)

        // precompute all elements 
        for(int x : arr) {
            hash[x]++;          // hash[i] = frequency of number i
        }

        // answer queries
        vector<int> result;
        for(int q : queries) {
            result.push_back(hash[q]);
        }

        return result;
    }
};

int main() {
    int n;
    cin >> n;                           // number of elements in array 

    vector<int> arr(n);
    for(int i = 0; i < n; i++) 
    cin >> arr[i];                      // arr = {1, 3, 2, 1, 3}

    int q;                              // q = 5
    cin >> q;                           // queries = {1, 4, 2, 3, 12}  ----> want to ask, how many times found

    vector<int> queries(q);
    for(int i = 0; i < q; i++) cin >> queries[i];           // cheak queries 
                                                            // how many times it appears and store it in new array 

    Solution obj;
    vector<int> ans = obj.frequencyQuery(arr, queries);     // Function Call

    for(int x : ans) {
        cout << x << endl;                                  // answer output 
    }

    return 0;
}





/*

First loop → precompute frequencies
Then queries → O(1) lookup each
Total → O(n + q) (very efficient)

*/