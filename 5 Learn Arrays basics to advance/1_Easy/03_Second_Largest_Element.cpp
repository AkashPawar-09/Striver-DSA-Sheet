/*

Input: nums = [8, 8, 7, 6, 5]
Output: 7
Explanation: The largest value in nums is 8, the second largest is 7

Input: nums = [10, 10, 10, 10, 10]
Output: -1
Explanation: The only value in nums is 10, so there is no second largest value, thus -1 is returned

*/


#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int secondLargestElement(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return -1;

        sort(nums.begin(), nums.end());

        int largest = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] != largest) {
                return nums[i];
            }
        }

        return -1;
    }
};




int main () {
    int n ; 
    cin >> n ;
    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj ; 
    int result = obj.secondLargestElement(nums) ;
    cout << result ;
    return 0 ;
}



















