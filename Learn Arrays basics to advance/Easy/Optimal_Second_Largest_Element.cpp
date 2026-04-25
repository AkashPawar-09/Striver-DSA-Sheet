/*

Input: nums = [8, 8, 7, 6, 5]
Output: 7
Explanation: The largest value in nums is 8, the second largest is 7

Input: nums = [10, 10, 10, 10, 10]
Output: -1
Explanation: The only value in nums is 10, so there is no second largest value, thus -1 is returned


Input:[1, 2, 4, 7, 7, 5]  
Output:
Second Smallest : 2  
Second Largest : 5  
Explanation: The elements are sorted as 1, 2, 4, 5, 7, 7.  
Hence, the second smallest element is 2, and the second largest element is 5.

Input: [1]  
Output:Second Smallest : -1  
Second Largest : -1  
Explanation: Since there is only one element in the array, it is both the largest and smallest element.  
Therefore, there is no second smallest or second largest element present.

*/


#include<bits/stdc++.h>
using namespace std ;


class Solution {
public:
    int secondLargestElement(vector<int>& nums) {
        
        int largest = INT_MIN;
        int second = INT_MIN;

        for (int x : nums) {
            if (x > largest) {
                second = largest;
                largest = x;
            } else if (x > second && x != largest) {
                second = x;
            }
            
        }
        if (second == INT_MIN) return -1;
        else return second;
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

// Time Complexity = O(n)
// Space Complexity = O(1)
