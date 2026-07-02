/*

Input: nums = [3,1,-2,-5,2,-4]
Output: [3,-2,1,-5,2,-4]
Explanation: The positive integers in nums are [3,1,2]. The negative integers are [-2,-5,-4].
The only possible way to rearrange them such that they satisfy all conditions is [3,-2,1,-5,2,-4].
Other ways such as [1,-2,2,-5,3,-4], [3,1,2,-2,-5,-4], [-2,3,-5,1,-4,2] are incorrect because they do not satisfy one or more conditions.  

Input: nums = [-1,1]
Output: [1,-1]
Explanation: 1 is the only positive integer and -1 the only negative integer in nums.
So nums is rearranged to [1,-1].

Input : nums = [2, 4, 5, -1, -3, -4]
Output : [2, -1, 4, -3, 5, -4]
Explanation: The positive number 2, 4, 5 maintain their relative positions and -1, -3, -4 maintain their relative positions

Input : nums = [1, -1, -3, -4, 2, 3]
Output : [1, -1, 2, -3, 3, -4]
Explanation: The positive number 1, 2, 3 maintain their relative positions and -1, -3, -4 maintain their relative positions

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();                                // size of nums array
        vector<int> ans_nums(n);                            // returning array (answer array)
        vector<int> positive;                               // positive array 
        vector<int> negative;                               // negativr array

        for (int i = 0; i < n; i++) {                       // iterations through i = 0 to n 
            if (nums[i] > 0) positive.push_back(nums[i]);   // seprate positive numbers and store in +ve array
            else negative.push_back(nums[i]);               // seprate negative numbers and store in -ve array
        }

        for (int j = 0; j < n / 2; j++) {                   // iterations through j = 0 to n to stre in new array
            ans_nums[2 * j] = positive[j];                  // store positive number using index = 2n
            ans_nums[2 * j + 1] = negative[j];              // store negative number uding index = 2n+1
        }

        return ans_nums;                                    // return new array
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

    vector<int> result = obj.rearrangeArray(nums);
    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}
// Time Complexity : O(n)
// Space Complexity : O(n)