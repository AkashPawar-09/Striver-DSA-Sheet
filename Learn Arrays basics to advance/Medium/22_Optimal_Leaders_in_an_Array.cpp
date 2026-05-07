/*

Input: nums = [-3, 4, 5, 1, -4, -5]
Output: [5, 1, -4, -5]
Explanation: -5 is the rightmost element, -4 is the largest element in the index range [4, 5], 
1 is the largest element in the index range [3, 5] and 5 is the largest element in the range [2, 5]

Input: arr = [10, 22, 12, 3, 0, 6]  
Output: 22 12 6  
Explanation: 6 is a leader because there are no elements after it.  
12 is greater than all the elements to its right (3, 0, 6), and 22 is greater than 12, 3, 0, 6, 
making them leaders as well.

Input: arr[] = [16, 17, 4, 3, 5, 2]
Output: [17 5 2]
Explanation: 17 is greater than all the elements to its right i.e., [4, 3, 5, 2], 
therefore 17 is a leader. 5 is greater than all the elements to its right i.e., [2], therefore 5 is a leader.
2 has no element to its right, therefore 2 is a leader.

Input: arr[] = [1, 2, 3, 4, 5, 2]
Output: [5 2]
Explanation: 5 is greater than all the elements to its right i.e., [2], therefore 5 is a leader. 
2 has no element to its right, therefore 2 is a leader.

Input: arr = [10, 4, 2, 4, 1]
Output: [10, 4, 4, 1]
Explanation: Note that both of the 4s are in output, as to be a leader an equal element is also allowed on the right. side

Input: arr = [30, 10, 10, 5]
Output: [30, 10, 10, 5]
Explanation: When an array is sorted in non-increasing order, all elements are leaders.

Input: arr = [5, 10, 20, 40]
Output: [40]
Explanation: When an array is sorted in increasing order, only the rightmost element is leader.

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