/*

Input: nums = [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2; 
The number 2 can't find next greater number. 
The second 1's next greater number needs to search circularly, which is also 2.

Input: nums = [1,2,3,4,3]
Output: [2,3,4,-1,4]

*/


#include<bits/stdc++.h>
using namespace std ;


class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();                                
        vector<int> arr = nums;                             // vector arr = nums
        arr.insert(arr.end(), nums.begin(), nums.end());    // arr = arr + nums = nums + nums

        vector<int> ans(n, -1);             // answer vector having size n and all elements are -1
        // BECAUSE OF THIS ALL ELEMENTS ARE CURRENTLY HOLDING -1 , LATER ON UPDATES BY NEXT GREATER ELEMENT FOR THAT ELEMENT
        stack<int> st;                      // stack st

        for (int i = 2 * n - 1; i >= n; i--) {              // iteration form last element of arr
            while (!st.empty() && st.top() <= arr[i]) {
            // while stack is not empty AND top of stack is smaller than previous elements
                st.pop();           // UNTIL DECREASING ORDER OF STACK FROM LAST TO MID
            }
            st.push(arr[i]);        // push elements in stack
        }

        for (int i = n - 1; i >= 0; i--) {                  // loop FROM MID TO START
            while (!st.empty() && st.top() <= arr[i]) {     // while stack is not empty or front element id not smaller than previous
                st.pop();           // UNTIL DECREASING ORDER OF STACK FROM LAST TO MID
            }

            if (!st.empty()) {          // if stack is not empty 
                ans[i] = st.top();      // then push top of element(PREVIOUS ELEMENT OF CURRENT ELEMENT)
            }

            st.push(arr[i]);            // push current element in stack
        }

        return ans;                     // return ans vector
    }
};




int main() {
    Solution obj;
    vector<int> nums1 = {1, 2, 1};
    vector<int> ans = obj.nextGreaterElements(nums1);
    cout << "Next Greater Elements: ";
    for (int x : ans) {
        cout << x << " ";
    }
    return 0;
}



// Time Complexity: O(N)
// Space Complexity: O(N)