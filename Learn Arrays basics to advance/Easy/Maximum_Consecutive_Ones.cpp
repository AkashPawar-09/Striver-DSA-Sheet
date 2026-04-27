/*

Input: nums = [1, 1, 0, 0, 1, 1, 1, 0]
Output: 3
Explanation: The maximum consecutive 1s are present from index 4 to index 6, amounting to 3 1s

Input: nums = [0, 0, 0, 0, 0, 0, 0, 0]
Output: 0
Explanation: No 1s are present in nums, thus we return 0

Input: nums = {1, 1, 0, 1, 1, 1}
Output: 3
Explanation: There are two consecutive 1’s and three consecutive 1’s in the array out of which maximum is 3.

Input: nums = {1, 0, 1, 1, 0, 1} 
Output: 2
Explanation: There are two consecutive 1's in the array. 

*/

#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size() ;
        int count = 0 ;
        int max_count = 0 ;
        for (int i = 0 ; i < n ; i++ ) {
            if(nums[i]==1){
                count++ ;
                max_count = max(max_count, count);
            }
            else {
                count = 0;
            }
        }
        return max_count ;
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
    int result = obj.findMaxConsecutiveOnes(nums);  
    cout << result << endl;
    return 0;
}


// 
// 