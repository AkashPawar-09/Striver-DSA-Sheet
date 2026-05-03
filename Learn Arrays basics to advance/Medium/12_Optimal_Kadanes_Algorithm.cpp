/* --------------- Kadane's Algorithm ---------------

// LeetCode 53. Maximum Subarray

// Que . find the subarray with the largest sum and return the sum of the elements present in that subarray.
// A subarray is a contiguous non-empty sequence of elements within an array.

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

        long long minimum = LLONG_MIN;                          // int → usually 32-bit → range: about −2 billion to +2 billion
        // by using int INT_MIN , it may stack overflow         // long long → 64-bit → range: about −9 × 10¹⁸ to +9 × 10¹⁸
        // INT_MIN = -2,147,483,648 , but for LLONG_MIN value is -9223372036854775808

        long long sum = 0;                                      // defined some as long long data type
        
        for (int i = 0; i < nums.size(); i++) {                 // iteration through i = 0 to size of nums
            
            sum += nums[i];                                     // updation of sum variable
            
            if (sum > minimum) {                                // if sum is grater than maxi (-9223372036854775808)
                minimum = sum;                                  // update minimum with sum
            }
            
            if (sum < 0) {                                      // if sum becomes negative 
                sum = 0;                                        // reset sum to zero 
            }
        }
        
        return minimum;                                         // return updated value of minimum
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


// Time Complexity: O(N)
// Space Complexity: O(1)