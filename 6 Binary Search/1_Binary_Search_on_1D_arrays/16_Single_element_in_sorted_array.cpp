/*

Input :nums = [1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6]
Output:4
Explanation: Only the number 4 appears once in the array.


Input : nums = [1, 1, 3, 5, 5]
Output:3
Explanation: Only the number 3 appears once in the array.

*/

#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];

        if (nums[0] != nums[1])
            return nums[0];

        if (nums[n - 1] != nums[n - 2])
            return nums[n - 1];

        int low = 1, high = n - 2;
        
        while (low <= high) {
            int mid = (low + high) / 2;

            // condition for an element which is single element
            if (nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1]) {
                return nums[mid];
            }

            // We are in the Left half , Trim it and Go towards Right
            if ((mid % 2 == 1 && nums[mid] == nums[mid - 1]) ||
                (mid % 2 == 0 && nums[mid] == nums[mid + 1])) {
                low = mid + 1;
            }

            // We are in the Right half , Trim it and Go towards Left
            else {
                high = mid - 1;
            }
        }

        return -1;
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

    cout << obj.singleNonDuplicate(nums) << endl;

    return 0;
}


// Time Complexity : O(log N)
// Space Complexity : O(1)


/* ============================================== Explanation ==============================================

The array is sorted, and every element appears exactly twice
except one element, which appears only once.

Before the single element:
- Every pair starts at an EVEN index.
- Every pair ends at an ODD index.

Example:

Index : 0   1   2    3   4    5   6
Array : 1   1   2    2   3    3   4
        ^   ^   ^    ^   ^    ^   ^
       Even Odd Even Odd Even Odd Even

After the single element appears, this even-odd pairing pattern
breaks because one element has no pair.

Since the array is sorted, we can use Binary Search to find
where this pattern breaks.

If the pair at mid is correct:
    - mid is even  and nums[mid] == nums[mid + 1]
      OR
    - mid is odd   and nums[mid] == nums[mid - 1]

Then the single element must be on the RIGHT side.

Otherwise, the pairing is broken, so the single element
lies on the LEFT side.

This lets us eliminate half of the array in every step,
giving an O(log n) solution.


---------------------------------- Algorithm ----------------------------------

1. If the array contains only one element, return it.

2. If the first element is different from the second,
   return the first element.

3. If the last element is different from the second last,
   return the last element.

4. Initialize:
      low = 1
      high = n - 2

5. While (low <= high):
      - Find mid.
      - If nums[mid] is different from both neighbours,
        return nums[mid].

      - If:
            (mid is even && nums[mid] == nums[mid + 1])
                     OR
            (mid is odd  && nums[mid] == nums[mid - 1])

        then move to the right:
            low = mid + 1;

      - Otherwise move to the left:
            high = mid - 1;

6. Return -1 (This case never occurs for valid input).


---------------------------------- Example ------------------------------------

Input:
nums = [1,1,2,3,3,4,4,8,8]

Output:
2

Explanation:
The element 2 appears only once, while every other element
appears exactly twice.

==================================================== END ==================================================== */