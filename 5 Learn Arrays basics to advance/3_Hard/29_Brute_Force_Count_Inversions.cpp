/*

Input: arr[] = [2, 4, 1, 3, 5]
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).


Input: arr[] = [2, 3, 4, 5, 6]
Output: 0
Explanation: As the sequence is already sorted so there is no inversion count.


Input: arr[] = [10, 10, 10]
Output: 0
Explanation: As all the elements of array are same, so there is no inversion count.


Input: nums = [2, 3, 7, 1, 3, 5]
Output: 5
Explanation: The responsible indexes are:
nums[0], nums[3], values: 2 > 1 & indexes: 0 < 3
nums[1], nums[3], values: 3 > 1 & indexes: 1 < 3
nums[2], nums[3], values: 7 > 1 & indexes: 2 < 3
nums[2], nums[4], values: 7 > 3 & indexes: 2 < 4
nums[2], nums[5], values: 7 > 5 & indexes: 2 < 5


Input: nums = [-10, -5, 6, 11, 15, 17]
Output: 0
Explanation:
nums is sorted, hence no inversions present.

*/

#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
   long long int numberOfInversions(vector<int> nums) {
        int n = nums.size() ;
        int count = 0 ;
        for (int i = 0 ; i < n ; i++) {
            for (int j = i+1 ; j<n ; j++) {
                if (nums[i] > nums[j] ) count++ ;
            }
        }
        return count  ;
    }
};


int main() {
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;

    cout << obj.numberOfInversions(nums);

    return 0;
}


// Time Complexity : O(N²)
// Space Complexity : O(1)