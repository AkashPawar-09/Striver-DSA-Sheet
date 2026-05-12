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
    int secondLargestElement(vector<int>& nums) {  // function to find second largest element
        
        int largest = INT_MIN;   // initialize largest as minimum possible integer
        int second = INT_MIN;    // initialize second largest as minimum possible integer

        for (int x : nums) {     // iterate through each element in the array
            if (x > largest) {  // if current element is greater than largest
                second = largest;  // update second as previous largest
                largest = x;       // update largest with current element
            } 
            else if (x > second && x != largest) {  // if x is between largest and second largest
                second = x;     // update second largest
            }
        }

        return (second == INT_MIN) ? -1 : second;  // return -1 if no second largest, else return second
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


