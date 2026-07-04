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
    vector<int> leaders(vector<int>& nums) {
        vector<int> res;                        // creating answer vector
        int n = nums.size();
        int maxRight = nums[n - 1];             // rightmost element
        res.push_back(maxRight);                // added rightmost element in answer vector
        for (int i = n - 2; i >= 0; i--) {      // loop from 2nd last element to first
            if (nums[i] >= maxRight) {          // if right is smalller than left 
                maxRight = nums[i];             // then update right to current number
                res.push_back(maxRight);        // then add that right number to answer vector
            }
        }
        reverse(res.begin(), res.end());        // to maintain order(ascending)
        return res; 
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
    vector<int> ans = obj.leaders(nums);
    for(int k : ans) {
        cout << k << " ";
    }
    return 0;
}

// Time Complexity : O(N)
// Space Complexity : O(1)