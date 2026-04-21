/*

input : 

7                   // number of inputs in array
1 2 4 5 4 6 2       // elements in array
5                   // query elements numbers
1 2 3 4 5           // actual query elements 


output :

1                   // appearence of 1
2                   // appearence of 2
0                   // appearence of 3
2                   // appearence of 4
1                   // appearence of 5

*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> frequencyQuery(vector<int>& arr, vector<int>& queries) {
        unordered_map<int, int> freq;

        // precompute
        for(int x : arr) {
            freq[x]++;
        }

        // answer queries
        vector<int> result;
        for(int q : queries) {
            result.push_back(freq[q]); // returns 0 if not present
        }

        return result;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    int q;
    cin >> q;

    vector<int> queries(q);
    for(int i = 0; i < q; i++) cin >> queries[i];

    Solution obj;
    vector<int> ans = obj.frequencyQuery(arr, queries);

    for(int x : ans) {
        cout << x << endl;
    }

    return 0;
}


// Time Complexity: O(n + q)
// Space Complexity: O(n)