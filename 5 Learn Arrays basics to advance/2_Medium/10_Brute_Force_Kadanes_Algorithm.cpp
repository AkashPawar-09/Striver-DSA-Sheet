/*

Input: nums = [2, 3, 5, -2, 7, -4]
Output: 15
Explanation: The subarray from index 0 to index 4 has the largest sum = 15

Input: nums = [2, 3, 5, -2, 7, -4]  
Output: 15  
Explanation: The subarray from index 0 to index 4 has the largest sum = 15, which is the maximum sum of any contiguous subarray.

Input: nums = [-2, -3, -7, -2, -10, -4]  
Output: -2  
Explanation: The largest sum is -2, which comes from taking the element at index 0 or index 3 as the subarray. 
Since all numbers are negative, the subarray with the least negative number gives the largest sum.

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.

Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.

Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.

*/


#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size() ;                       // n = total elements
        int minimum = INT_MIN;                      // used minimum possible number to compare at sum to overcome stack overflow
        for (int i = 0 ; i < n ; i++ ) {            // iteration for starting index
            for (int j = i ; j < n ; j++ ) {        // iteration for ending index
                int sum = 0;                        // initilise sum = 0
                for (int k = i; k <= j ; k++) {     // loop for sum from starting index to ending index
                    sum = sum + nums[k] ;           // updating sum 
                }
                minimum = max ( minimum , sum );    // store maximum between sum (updated at last loop) and minimum
            }
        }
        return minimum ;                            // returning condition for other possible cases
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
    int result = obj.maxSubArray(nums);  
    cout << result << endl;
    return 0;
}


// Time Complexity: O(N³)
// Space Complexity: O(1)