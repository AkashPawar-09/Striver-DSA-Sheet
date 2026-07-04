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
        int n = nums.size();

        vector<int> ans(n);                     // created answer vector

        int positiveIndex = 0;
        int negativeIndex = 1;

        for (int x : nums) {                    // cheak every number in nums

            if (x > 0) {                        // if element is positive
                ans[positiveIndex] = x;         // add it to correct positive index 
                positiveIndex += 2;             // increment to next positive index
            }
            else {                              // else : if element is negative 
                ans[negativeIndex] = x;         // add it to correct negative index 
                negativeIndex += 2;             // increment to next negative index
            }
        }
        return ans;                             // return answer vector
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