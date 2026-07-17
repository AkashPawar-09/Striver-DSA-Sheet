/*  NOTE : THIS QUESTION IS EXACT SAME AS Koko Eating Bananas

Input: nums = [1, 2, 3, 4, 5], limit = 8
Output: 3
Explanation: We can get a sum of 15(1 + 2 + 3 + 4 + 5) if we choose 1 as a divisor. 
The sum is 9(1 + 1 + 2 + 2 + 3) if we choose 2 as a divisor. 
Upon dividing all the elements of the array by 3, we get 1,1,1,2,2 respectively. 
Now, their sum is equal to 7 <= 8 i.e. the threshold value. So, 3 is the minimum possible answer.


Input: nums = [8,4,2,3], limit = 10
Output: 2
Explanation: If we choose 1, we get 17 as the sum. If we choose 2, we get 9 (4+2+1+2) <= 10 as the answer. 
So, 2 is the answer.


Input: nums = [1,2,5,9], threshold = 6
Output: 5
Explanation: We can get a sum to 17 (1+2+5+9) if the divisor is 1. 
If the divisor is 4 we can get a sum of 7 (1+1+2+3) and if the divisor is 5 the sum will be 5 (1+1+1+2).


Input: nums = [44,22,33,11,1], threshold = 5
Output: 44

*/


#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size() ;

        int maxi = *max_element(nums.begin(), nums.end());          // find maximum number of banana's

        int low = 1 ; 
        int high = maxi ;

        while(low <= high ) {

            int mid = low + (high-low) / 2 ;                        // calculate mid
              
            long long divSums = 0;                                  // initiate divSum = 0
            
            for (int num : nums) {                                  // foreach loop to calculate divSum
                divSums = divSums + (num + mid - 1) / mid ;         // calculate divSum & also ceil of division 
            }

            if (divSums <= threshold) {                             // if divSum is smaller than or equal to threshold
                high = mid - 1;                                     // eliminate the right side 
            }
            else {
                low = mid + 1;                                      // eliminate the left side 
            }
        }
        return low;                                                // otherwise return maximum element
    }
};


int main() {

    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int threshold;
    cout << "Enter threshold: ";
    cin >> threshold;

    Solution obj;

    int ans = obj.smallestDivisor(nums, threshold);

    cout << "Smallest Divisor = " << ans << endl;

    return 0;
}

// Time Complexity : O(n × max(nums))
// Space Complexity : O(1)