/* --------------------------------------------------------------------------------------------------------------------

Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
Output: [-1,3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
- 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
- 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.


Input: nums1 = [2,4], nums2 = [1,2,3,4]
Output: [3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 2 is underlined in nums2 = [1,2,3,4]. The next greater element is 3.
- 4 is underlined in nums2 = [1,2,3,4]. There is no next greater element, so the answer is -1.

-------------------------------------------------------------------------------------------------------------------- */


#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;                             // maps each value in nums2 to its next greater element
        stack<int> st;                                          // monotonic decreasing stack (bottom to top)
        for (int i = nums2.size() - 1; i >= 0; i--) {           // traverse nums2 from right to left
            while (!st.empty() && st.top() <= nums2[i]) {       // pop all elements <= current (they can't be "next greater" for anything further left)
                st.pop();
            }
            if (st.empty()) {                                   // no element left on stack is greater
                mp[nums2[i]] = -1;                              // so no next greater element exists
            } else {
                mp[nums2[i]] = st.top();                        // top of stack is the nearest greater element to the right
            }
            st.push(nums2[i]);                                  // push current element for future (leftward) comparisons
        }
        vector<int> ans;                                        // result array aligned with nums1
        for (int x : nums1) {                                   // for each query element in nums1
            ans.push_back(mp[x]);                               // look up its precomputed next greater element
        }
        return ans;                                             // return final answer
    }
};



int main() {
    Solution obj;
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    vector<int> ans = obj.nextGreaterElement(nums1, nums2);
    cout << "Next Greater Elements: ";
    for (int x : ans) {
        cout << x << " ";
    }
    return 0;
}



// Time Complexity: O(N + M)
// Space Complexity: O(M)