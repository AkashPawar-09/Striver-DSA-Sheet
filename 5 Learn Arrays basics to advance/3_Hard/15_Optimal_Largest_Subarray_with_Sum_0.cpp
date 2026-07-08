/*

Input: arr = [15, -2, 2, -8, 1, 7, 10, 23]
Output: 5
Explanation: The subarray [-2, 2, -8, 1, 7] sums up to 0 and has the maximum length among all such subarrays.


Input: arr = [2, 10, 4]
Output: 0
Explanation: There is no subarray whose elements sum to 0.


Input: N = 6, array[] = {9, -3, 3, -1, 6, -5}  
Result: 5  
Explanation: The following subarrays sum to zero: {-3, 3} , {-1, 6, -5} , {-3, 3, -1, 6, -5}
The length of the longest subarray with sum zero is 5.


*/

#include<bits/stdc++.h>
using namespace std ;

class Solution {
  public:
    int maxLen(vector<int>& arr) {
        unordered_map<int, int> mp;         // stores prefix_sum -> earliest index where that sum occurred
        int sum = 0;                        // running prefix sum
        int maxLen = 0;                     // stores length of longest zero-sum subarray found so far

        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];                      // add current element to running prefix sum

            if (sum == 0) {                     // if prefix sum itself is 0
                maxLen = i + 1;                 // whole subarray arr[0..i] sums to 0, update maxLen
            }

            if (mp.find(sum) != mp.end()) {             // if this prefix sum has occurred before
                maxLen = max(maxLen, i - mp[sum]);      // subarray between previous index and i sums to 0, update maxLen
            }
            else {                              // if this prefix sum is new
                mp[sum] = i;                    // store first occurrence index of this sum
            }
        }

        return maxLen;                          // return length of longest zero-sum subarray
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution obj;
    cout << obj.maxLen(arr);

    return 0;
}


// Time Complexity : O(N)
// Space Complexity : O(N)




/*-------------------------------------------------- Explanation ----------------------------------------------
What is unordered_map?
It is a hash table.

It stores data as
Key  --->  Value

Here,
Key   = Prefix Sum
Value = Index where that prefix sum first appeared

So, unordered_map<int, int> mp;
means "Store every unique prefix sum along with the index where it first occurs."

---------------------------------------------------------------------------------------------------------------
Why store prefix sums?
The whole algorithm depends on the observation that
If the same prefix sum appears more than once, then the elements between those two occurrences have a sum of 0.
Therefore we need a data structure that can
insert a prefix sum
check whether it already exists
Both operations are approximately O(1) using unordered_map.

---------------------------------------------------------------------------------------------------------------

for (int i = 0; i < arr.size(); i++)

Meaning : Traverse the entire array exactly once.

The algorithm processes :
current element
current prefix sum
map updates

all in one traversal.
Hence : Time Complexity = O(n)

---------------------------------------------------------------------------------------------------------------

Start
↓
Create Hash Map
↓
sum = 0
↓
maxLen = 0
↓
Traverse Array
↓
Update Prefix Sum
↓
Is Prefix Sum = 0 ?
↓
Yes
↓
Update maxLen
↓
No
↓
Has this Prefix Sum appeared before ?
↓
Yes
↓
Calculate Length
↓
Update maxLen
↓
No
↓
Store Prefix Sum and Index
↓
Continue
↓
Return maxLen

------------------------------------------------------------------------------------------------------------- */