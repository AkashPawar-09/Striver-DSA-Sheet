/*
Input: nums = [2, 3, 4, 5, 3], target = 3
Output: 1
Explanation: The first occurence of 3 in nums is at index 1

Input: nums = [2, -4, 4, 0, 10], target = 6
Output: -1
Explanation: The value 6 does not occur in the array, hence output is -1

Input: arr[] = 1 2 3 4 5, num = 3  
Output: 2
Explanation: 3 is present at the 2nd index of the array.

Input: arr[] = 5 4 3 2 1, num = 5  
Output: 0  
Explanation: 5 is present at the 0th index of the array.

*/


#include<bits/stdc++.h>
using namespace std ;


class Solution {
public:
    int linearSearch(vector<int>& nums, int target) {
        int n = nums.size() ;
        if(n==0) return -1 ;
        if (target > n-1) return -1 ;
        for (int i =  0 ; i < n ; i++ ) {
            if (target == nums[i]) {
                return i ;
                break ;
            }
        }
        
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
    int target ;
    cin >> target ;

    Solution obj;   
    int result = obj.linearSearch(nums,target);  
    cout << result << endl;
    return 0;
}
