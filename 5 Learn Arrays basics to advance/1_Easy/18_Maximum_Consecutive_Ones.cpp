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





/*

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int count = (nums[0] == 1) ? 1 : 0;             // if 1st element is 1 then count is 1 , otherwise 0
        int maxCount = count;                           // maxcount is initially count
        for (int i = 1; i < n; i++) {                   // iteration on elements of nums from 2nd element to last
            if (nums[i] == 1 && nums[i - 1] == 1) {     // if previous and current elements both are 1
                count++;                                // then increase count 
            }
            else if (nums[i] == 1) {                    // if not consecutive not found then this condition 
                count = 1;                              // if any element is 1 then count is 1
            }
            else {                                      // if not any 1 found 
                count = 0;                              // then count is 0
            }

            maxCount = max(maxCount, count);            // maxCount is maximum between maxCount & count
        }

        return maxCount;                                // return maximum count
    }
};

*/





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
