/*

Input: arr[] = [1, 2, 3, 4, 5], x = 11 
Output: 10
Explanation: Subarray having maximum sum is [1, 2, 3, 4].

Input: arr[] = [2, 4, 6, 8, 10], x = 7 
Output: 6
Explanation: Subarray having maximum sum is [2, 4] or [6].

*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxSum(vector<int>& arr, int x) {
        int n = arr.size();                         // n = size of given array
        set<long long> st;                          // create set st
        st.insert(0);                               // insert 1st element in set is 0
        
        long long prefix = 0;                       // prefix is like sum from the beginning up to current index
        long long ans = LLONG_MIN;                  // stores answer (valid sum limited by x)

        for(int i = 0; i < n; i++) {                // travese all elements in array 
            prefix = prefix + arr[i];               // it is sum of all elements from start to current element

            // we want max (prefix - prevPrefix) such that (prefix - prevPrefix) <= x
            // i.e. prevPrefix >= prefix - x
            // lower_bound finds smallest prevPrefix satisfying that -> gives max valid subarray sum

            auto it = st.lower_bound(prefix - x);   // finds it which is if smaller than 0 (negative (i.e. false) ) 
            // if -ve , then it will become zero causes next if condition
            if(it != st.end()) {                    // if sum is negative (i.e. it = 0)
                ans = max(ans, prefix - *it);       // subarray sum = prefix - prevPrefix
            }
            st.insert(prefix);                      // add current prefix for future iterations
        }

        return (int)ans;
    }
};



int main() {
    int n, x;
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cin >> x;

    Solution obj;

    cout << obj.maxSum(arr, x) << endl;

    return 0;
}

// Time Complexity : O(N log N)
// Space Complexity : O(N)