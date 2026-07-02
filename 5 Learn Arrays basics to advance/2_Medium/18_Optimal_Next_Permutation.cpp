/*
Input: Arr[] = {1,3,2}
Output: {2,1,3}
Explanation: All permutations of {1,2,3} are {{1,2,3} , {1,3,2}, {2,1,3} , {2,3,1} , {3,1,2} , {3,2,1}}. 
So, the next permutation just after {1,3,2} is {2,1,3}.

Input : Arr[] = {3,2,1}
Output: {1,2,3}
Explanation : As we see all permutations of {1,2,3}, we find {3,2,1} at the last position. 
So, we have to return the lowest permutation.

Input: nums = [1,2,3]
Output: [1,3,2]
Explanation: The next permutation of [1,2,3] is [1,3,2].

Input: nums = [3,2,1]
Output: [1,2,3]
Explanation: [3,2,1] is the last permutation. So we return the first: [1,2,3].

*/

#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();                            // total elements in array
        int i;                                          // stores the break point index

        // Step 1: Find breaking point
        for (i = n - 2; i >= 0; i--) {                  // start from second-last, scan left
            if (nums[i] < nums[i + 1]) {                // found element smaller than its right neighbor
                break;                                  // this is our break point, stop here
            }
        }
        // if whole array is descending (eg: 5,4,3), loop ends with i = -1

        // Step 2: Find next greater element and swap
        if (i >= 0) {                                   // skip this step if no break point found
            for (int j = n - 1; j > i; j--) {           // scan from rightmost element towards i
                if (nums[j] > nums[i]) {                // find the smallest element greater than nums[i]
                    swap(nums[i], nums[j]);             // swap break point with that element
                    break;                              // one swap is enough, stop
                }
            }
        }

        // Step 3: Reverse suffix using for loop
        for (int left = i + 1, right = n - 1; left < right; left++, right--) {     // two pointers on both ends of suffix
            swap(nums[left], nums[right]);                                          // reverse suffix to make it smallest order
        }
        // suffix was in descending order, reversing gives ascending = smallest arrangement
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> nums;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nums.push_back(x);
    }

    Solution obj;
    obj.nextPermutation(nums);

    for(int k : nums ){
        cout << k << " ";
    }
    return 0;
}


// Time Complexity: O(N)
// Space Complexity: O(1)
