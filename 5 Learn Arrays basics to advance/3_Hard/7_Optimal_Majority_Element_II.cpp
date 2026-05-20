/*

Input: nums = [1, 2, 1, 1, 3, 2]
Output: [1]
Explanation: Here, n / 3 = 6 / 3 = 2.
Therefore the elements appearing 3 or more times is : [1]

Input: arr[] = [2, 2, 3, 1, 3, 2, 1, 1]
Output: [1, 2]
Explanation: The frequency of 1 and 2 is 3, which is more than floor n/3 (8/3 = 2).

Input: arr[] = [-5, 3, -5]
Output: [-5]
Explanation: The frequency of -5 is 2, which is more than floor n/3 (3/3 = 1).

Input: arr[] = [3, 2, 2, 4, 1, 4]
Output: [ ]
Explanation: n/3 = (6/3 = 2)
here number should occur more than 2 times 
There is no majority element.

Input: nums = [3,2,3]
Output: [3]
Explanation: n/3 = (3/3 = 1)
here number should occur more than 1 times 
majority element = [3]

Input: nums = [1]
Output: [1]
Explanation: 1/3 = (1/3 = 0)
here number should occur more than 0 times (i.e. at least 1 time) 
majority element = [1]

Input: nums = [1,2]
Output: [1,2]

*/

#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    vector<int> majorityElementTwo(vector<int>& nums) {
        int n = nums.size();                                // n = size of nums vector
        int cnt1 = 0, cnt2 = 0;                             // set counting of two elements el1 and el2 
        int el1 = INT_MIN, el2 = INT_MIN;                   // initialized 2 elements to lowest to update further
        
        for (int i = 0; i < n; i++) {                       // traverse every element in nums array
            if (cnt1 == 0 && el2 != nums[i]) {              // Slot 1 is empty & not already candidate 2
                cnt1 = 1;                                   // Assign current element as candidate 1
                el1 = nums[i];                              // and assign el1 = nums[i]
            }
            else if (cnt2 == 0 && el1 != nums[i]) {         // Slot 2 is empty & not already candidate 1
                cnt2 = 1;                                   // Assign current element as candidate 2
                el2 = nums[i];                              //
            }   
            else if (nums[i] == el1) {                      // Seen candidate 1 again
                cnt1++;                                     // increase count1 by 1
            }
            else if (nums[i] == el2) {                      // Seen candidate 2 again 
                cnt2++;                                     // increase count2 by 1
            }
            else {                                          // Seen a 3rd distinct element
                cnt1--;                                     // Cancel one vote from each candidate
                cnt2--;                                     // (Boyer-Moore: triplets cancel each other)
            }
        }

        cnt1 = 0;
        cnt2 = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == el1) cnt1++;                     // Count real occurrences of candidate 1
            if (nums[i] == el2) cnt2++;                     // Count real occurrences of candidate 2
        }

        int mini = (n / 3) + 1;                             // Minimum frequency threshold (> n/3)
        vector<int> ans;                                    // Create an empty result vector to store the answer

        if (cnt1 >= mini) {ans.push_back(el1);}                 // el1 qualifies
        if (cnt2 >= mini && el1 != el2) {ans.push_back(el2);}   // el2 qualifies (and avoid duplicates)

        return ans;                                         // At most 2 elements in result
    }
};


int main () {
    int n ; 
    cin >> n ;

    vector<int> nums ;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nums.push_back(x);
    }

    Solution obj ;
    
    vector<int> result = obj.majorityElementTwo(nums) ;
    for (int x : result) {
        cout << x << " ";
    }

    return 0;

}

// Imp Note : Understand and rewise algorithm many times



// Time Complexity : O(N)
// Space Complexity : O(1)
