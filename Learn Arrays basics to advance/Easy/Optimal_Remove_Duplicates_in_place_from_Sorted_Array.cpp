/*

Input: arr[]=[1,1,2,2,2,3,3]
Output: [1,2,3,_,_,_,_]
Explanation: Total number of unique elements are 3, i.e[1,2,3] and 
Therefore return 3 after assigning [1,2,3] in the beginning of the array.

Input: arr[]=[1,1,1,2,2,3,3,3,3,4,4]
Output: [1,2,3,4,_,_,_,_,_,_,_]
Explanation: Total number of unique elements are 4, i.e[1,2,3,4] and 
Therefore return 4 after assigning [1,2,3,4] in the beginning of the array.

Input: nums = [0, 0, 3, 3, 5, 6]
Output: 4
Explanation: Resulting array = [0, 3, 5, 6, _, _]
There are 4 distinct elements in nums and the elements marked as _ can have any value.

Input: nums = [-2, 2, 4, 4, 4, 4, 5, 5]
Output: 4
Explanation: Resulting array = [-2, 2, 4, 5, _, _, _, _]
There are 4 distinct elements in nums and the elements marked as _ can have any value.


*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;     // if array is empty return 0

        int k = 1;                          // pointer to place next unique element

        for (int i = 1; i < nums.size(); i++) {     // iterate from second element
            if (nums[i] != nums[i - 1]) {           // check if current element in nums is different from previous elelment 
                nums[k] = nums[i];                  // then only place unique element at index k (starts from index 1)
                // modifying the actual input array 
                k++;                                // increment position for next unique element
            }
        }

        return k;                                   // It returns only the count of unique elements
        // NOT the array
    }
};


int main() {
    int n;
    cin >> n;

    vector<int> nums(n);

    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;

    int k = obj.removeDuplicates(nums);

    for(int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }

    return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(1)