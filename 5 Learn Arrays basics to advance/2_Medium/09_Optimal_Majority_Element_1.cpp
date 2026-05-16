/* --------------- Boyer–Moore Voting Algorithm ---------------

// LeetCode 169. Majority Element

Input: nums = [7, 0, 0, 1, 7, 7, 2, 7, 7]  
Output: 7  
Explanation: The number 7 appears 5 times in the 9-sized array, making it the most frequent element.

Input: nums = [1, 1, 1, 2, 1, 2]  
Output: 1  
Explanation: The number 1 appears 4 times in the 6-sized array, making it the most frequent element.

Input: nums = [3,2,3]
Output: 3

Input: nums = [2,2,1,1,1,2,2]
Output: 2

*/


#include<bits/stdc++.h>
using namespace std ;


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;              // Tracks balance
        int element = 0;            // Candidate for majority

        for (int i : nums) {

            if (count == 0) {       // If count is 0 (default) 
                element = i;        // take new number
            }
            if (i == element) {     // if i equals to element while increament of i
                count++;            // increase count 
            }
            else {
                count--;            // other-wise decreament it (after decreament it becomes -1 )
            }
        }

        // Verification step

        int freq = 0;
        for (int num : nums) {
            if (num == element) freq++;     // increase frquency of
        }

        if (freq > nums.size() / 2) {       // cheaks condition of majority element 
            return element;                 // if condition is passed , return that element
        }

        return -1;                          // if no majority element exists
    }
};


int main() {
    int n;
    cout << "Enter number: ";
    cin >> n;
    vector<int> nums(n) ;
    for (int  i = 0  ; i < n ; i++ ){
        cin >> nums[i] ;
    }

    Solution obj;   
    int result = obj.majorityElement(nums);  
    cout << result << endl;
    return 0;
}


// Time Comlexity : O(n)
// Space Complexity : O(1)

