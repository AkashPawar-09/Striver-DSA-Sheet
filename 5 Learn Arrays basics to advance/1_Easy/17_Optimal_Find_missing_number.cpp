/*

Input: nums = [0, 2, 3, 1, 4]
Output: 5
Explanation: nums contains 0, 1, 2, 3, 4 thus leaving 5 as the only missing number in the range [0, 5]

Input: nums = [0, 1, 2, 4, 5, 6]
Output: 3
Explanation: nums contains 0, 1, 2, 4, 5, 6 thus leaving 3 as the only missing number in the range [0, 6]

*/

#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int n = nums.size();                    // n = size of nums
        int expectedSum = n * (n + 1) / 2;      // expected sum formula
        int actualSum = 0;                      // variable that measures actualSum
        for (int i = 0; i < n; i++) {           // iteration over nums array
            actualSum += nums[i];               // actualSum stores all Element sum in it 
        }
        return expectedSum - actualSum;         // return the missing number by this method 
    }
};



int main () {
    int n;
    cin >> n;
    vector<int> nums(n) ;
    for (int  i = 0  ; i < n ; i++ ){
        cin >> nums[i] ;
    }
    Solution obj;   
    int result = obj.missingNumber(nums);  
    cout << result << endl;
    return 0;
}

// Time Compleity : O(N)
// Spcae Complexity : O(1)