/*
Input: Arr[] = {1,3,2}
Output: {2,1,3}
Explanation: All permutations of {1,2,3} are {{1,2,3} , {1,3,2}, {2,13} , {2,3,1} , {3,1,2} , {3,2,1}}. 
So, the next permutation just after {1,3,2} is {2,1,3}.

Input : Arr[] = {3,2,1}
Output: {1,2,3}
Explanation : As we see all permutations of {1,2,3}, we find {3,2,1} at the last position. 
So, we have to return the lowest permutation.

Input: nums = [1,2,3]
Output: [1,3,2]
Explanation: The next permutation of [1,2,3] is [1,3,2].

Input: nums = [3,2,1]
Output: [1,2,3]
Explanation: [3,2,1] is the last permutation. So we return the first: [1,2,3].

*/

#include<bits/stdc++.h>
using namespace std ;

// Time Complexity: O(N!*N)
// Space Complexity: O(N!)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();                                    // total elements in array

        // Step 1: Calculate n! (total number of permutations possible)
        int total = 1;
        for(int i = 1; i <= n; i++) {                          // multiply 1 * 2 * 3 * ... * n
            total *= i;                                        // total = n!  eg: n=3 → total=6
        }

        // Step 2: Generate ALL permutations and store them
        vector<vector<int>> allPerms;                          // stores all n! permutations
        vector<int> temp = nums;                               // working copy of array
        sort(temp.begin(), temp.end());                        // sort to always start from first(smallest) permutation

        for(int p = 0; p < total; p++) {                       // loop runs exactly n! times
            allPerms.push_back(temp);                          // store current permutation in list
            next_permutation(temp.begin(), temp.end());        // move temp to its next permutation
        }
        // allPerms = [ [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], [3,2,1] ]  for n=3

        // Step 3: Find where current nums is in the list, then return next one
        for(int i = 0; i < total; i++) {                       // scan through all stored permutations
            if(allPerms[i] == nums) {                          // found current permutation at index i
                if(i == total - 1) {                           // if it's the last permutation (eg: 3,2,1)
                    nums = allPerms[0];                        // wrap around → return first permutation (eg: 1,2,3)
                } else {
                    nums = allPerms[i + 1];                    // simply return the next permutation in list
                }
                return;                                        // done, exit
            }
        }
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> nums;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nums.push_back(x);
    }

    Solution obj;
    obj.nextPermutation(nums);

    for(int k : nums ){
        cout << k << " ";
    }
    return 0;
}


// Time Complexity: O(N!*N)
// Space Complexity: O(N!)


/*

////////////////////////////////////   Explanation   //////////////////////////////////////////

eg: nums = [1, 2, 3]  →  n = 3

total permutations = 3! = 6

allPerms stores:        each comparison (==) costs:
[1, 2, 3]              O(N)
[1, 3, 2]              O(N)
[2, 1, 3]              O(N)
[2, 3, 1]              O(N)
[3, 1, 2]              O(N)
[3, 2, 1]              O(N)
─────────────────────────────
 N! arrays stored      N! × N comparisons
 → Space = O(N!)       → Time = O(N! × N)
 
*/