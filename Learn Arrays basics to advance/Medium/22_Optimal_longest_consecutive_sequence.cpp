/*

Input: nums = [100, 4, 200, 1, 3, 2]
Output: 4
Explanation: The longest sequence of consecutive elements in the array is [1, 2, 3, 4], which has a length of 4. 
This sequence can be formed regardless of the initial order of the elements in the array.

Input: nums = [0, 3, 7, 2, 5, 8, 4, 6, 0, 1]
Output: 9
Explanation: The longest sequence of consecutive elements in the array is [0, 1, 2, 3, 4, 5, 6, 7, 8], which has a length of 9. 

Input: arr[] = [2, 6, 1, 9, 4, 5, 3]
Output: 6
Explanation:  The longest consecutive subsequence [2, 6, 1, 4, 5, 3].

Input: arr[] = [1,1,1,2,2,3]
Output: 3
Explanation: The subsequence [1, 2,3] is the longest subsequence of consecutive elements

*/


#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int n = nums.size();                        // n = size of nums array

        if (n == 0) return 0;                       // return if empty 

        unordered_set<int> st;                      // use set to stor all elements

        for (int i = 0; i < n; i++) {
            st.insert(nums[i]);                     // insert one by one
        }

        int longest = 1;                            // declare longest = 1

            for (auto it : st) {     
            // Loop through every element present in the set 'st'
            // 'auto' automatically detects datatype
            // 'it' stores current element one by one

                if (st.find(it - 1) == st.end()) {     
                // Check whether previous number (it - 1) exists or not
                // If previous number is NOT present,
                // then current element is the STARTING of a sequence

                // Example:
                // if it = 5
                // check whether 4 exists
                // if 4 does not exist -> sequence starts from 5

                int x = it;                         
                // Store current number in x
                // x will move forward to check consecutive numbers

                int cnt = 1;                        
                // Current sequence length starts from 1
                // because current number itself is counted

                // find consecutive numbers
                while (st.find(x + 1) != st.end()) {
                // Keep checking whether next consecutive number exists

                // Example:
                // if x = 5
                // check whether 6 exists

                    x++;                            
                    // Move to next number

                    cnt++;                          
                    // Increase sequence count
                }

                // update longest
                longest = max(longest, cnt);
                // Compare current sequence length with longest sequence
                // Store maximum value in longest

                // Example:
                // longest = 3
                // cnt = 5
                // longest becomes 5
            }
        }
        return longest;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    Solution obj;
    int ans = obj.longestConsecutive(nums);

    return 0;
}

// Time Complexity : O(N)
// Space Complexity : O(N)