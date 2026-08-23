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
using namespace std ;


class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;                            // create answer vecctor to store answers
        for (int i = 0; i < nums1.size(); i++) {    // traverse every element in nums1 vector
            int j = 0;                              // j = 0 
            while (nums2[j] != nums1[i]) {          // loop until we find element of nums1 in nums2
                j++;                                // travese every element
            }       
            bool found = false;                     // make bool found false 
            for (int k = j + 1; k < nums2.size(); k++){ // travese all elements in nums2 from next element of founded element nums2[j]
                if (nums2[k] > nums1[i]) {          // if element in nums2 is grater than element nums1 
                    ans.push_back(nums2[k]);        // push it answer vector
                    found = true;                   // make found true
                    break;                          // break the for loop 
                }
            }
            if (!found) {                           // if element is not founded (i.e. greater element is not in nums2 )
                ans.push_back(-1);                  // then push -1 for that
            }
        }
        return ans;                                 // return that answer
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



// Time Complexity: O(N × M)
// Space Complexity: O(N)