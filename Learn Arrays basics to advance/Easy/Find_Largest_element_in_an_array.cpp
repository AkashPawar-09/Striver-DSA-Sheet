/*

Input: arr[] = {2, 5, 1, 3, 0}  
Output: 5  
Explanation: 5 is the largest element in the array.

Input: arr[] = {8, 10, 5, 7, 9}  
Output: 10  
Explanation: 10 is the largest element in the array.

Input: nums = [3, 3, 6, 1]
Output: 6
Explanation: The largest element in array is 6

Input: nums = [3, 3, 0, 99, -40]
Output: 99
Explanation: The largest element in array is 99

*/

#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int largestElement(vector<int>& nums) {
        int n = nums.size() ;
        sort(nums.begin() , nums.end()) ;
        return nums[n-1] ;
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
    int result = obj.largestElement(nums);  
    cout << result << endl;
    return 0;
}


// Time Complexity : O(n log n)
// Space Complexity : O(log n)
