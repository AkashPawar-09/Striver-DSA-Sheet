/*

Input: nums = [3, 5, 4, 1, 1]
Output: [1, 2]
Explanation: 1 appears two times in the array and 2 is missing from nums


Input: nums = [1, 2, 3, 6, 7, 5, 7]
Output: [7, 4]
Explanation: 7 appears two times in the array and 4 is missing from nums.


Input: arr[] = [3, 1, 3]
Output: [3, 2]
Explanation: 3 is occurs twice and 2 is missing.


Input: arr[] = [4, 3, 6, 2, 1, 1]
Output: [1, 5] 
Explanation: 1 is occurs twice and 5 is missing.

*/

#include<bits/stdc++.h>
using namespace std ;


class Solution {
public:
    vector<int> findMissingRepeatingNumbers(vector<int> nums) {

        int n = nums.size();                        // Store the size of the array.
        int repeating = -1;                         // Stores the repeating number.

        // Mark visited indices by making the value at
        // the corresponding index negative.
        for (int i = 0; i < n; i++) {

            int value = abs(nums[i]);               // Get the absolute value of the current element.

            if (nums[value - 1] > 0) {              // If this index has not been visited yet,
                nums[value - 1] = -nums[value - 1]; // mark it as visited by making it negative.
            }
            else {                                  // If it is already negative,
                repeating = value;                  // then this value is repeating.
            }
        }

        int missing = -1;                           // Stores the missing number.

        // The index that still contains a positive value
        // corresponds to the missing number.
        for (int i = 0; i < n; i++) {

            if (nums[i] > 0) {                      // Positive means this index was never visited.
                missing = i + 1;                    // Missing number is index + 1.
                break;                              // Missing number found.
            }
        }

        return {repeating, missing};                // Return [repeating, missing].
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
    vector<int> ans = obj.findMissingRepeatingNumbers(nums);

    cout << ans[0] << " " << ans[1] << endl;

    return 0;
}


// Time Complexity : O(N)
// Space Complexity : O(1)



/* -------------------------------------------------- Explanation ----------------------------------------------


Example
nums = {4, 3, 6, 2, 1, 1}

Initially:

Index	0	1	2	3	4	5
Value	4	3	6	2	1	1
Iteration 1 (i = 0)

value = abs(nums[0]) = 4, so visit index 4 - 1 = 3 and make it negative:

nums[3] = -nums[3];

Array becomes:

{4, 3, 6, -2, 1, 1}
Iteration 2 (i = 1)

value = abs(nums[1]) = 3, so visit index 3 - 1 = 2 and make it negative:

nums[2] = -nums[2];

Array becomes:

{4, 3, -6, -2, 1, 1}
Iteration 3 (i = 2)

Now nums[2] is -6 because it was marked negative in the previous iteration.

Without abs(): value = nums[2] = -6, so the index becomes value - 1 = -7, i.e., nums[-7], 
which is an invalid index and may crash the program.
With abs(): value = abs(nums[2]) = abs(-6) = 6, so the index becomes 6 - 1 = 5, i.e., nums[5], which is correct.
Why do we make numbers negative?

The statement

nums[value - 1] = -nums[value - 1];

marks a number as visited. For example, when the number 4 is encountered, 
we go to index 4 - 1 = 3 and make nums[3] negative. If 4 appears again later, 
nums[3] is already negative, which tells us that 4 has already been visited, 
so 4 is the repeating number. Therefore, abs() is used because elements may already have been made negative during marking, 
but we always need their original positive value to calculate the correct index.


----------------------------------------------------------------------------------------------------------------------- */