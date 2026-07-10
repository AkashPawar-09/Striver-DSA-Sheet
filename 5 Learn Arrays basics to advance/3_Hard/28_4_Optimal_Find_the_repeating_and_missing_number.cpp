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

        int n = nums.size();                            // Store the size of the array.
        int xorValue = 0;                               // Stores XOR of all array elements and numbers from 1 to n.

        // Find XOR of all array elements and numbers from 1 to n.
        for (int i = 0; i < n; i++) {
            xorValue ^= nums[i];                        // XOR with array element.
            xorValue ^= (i + 1);                        // XOR with numbers from 1 to n.
        }

        // Find the rightmost set bit in xorValue.
        int setBit = xorValue & ~(xorValue - 1);
        int x = 0, y = 0;                               // These will store the missing and repeating numbers.

        // Divide numbers into two groups based on the rightmost set bit.
        for (int i = 0; i < n; i++) {

            // Divide array elements.
            if (nums[i] & setBit) {                     // If the set bit is present,
                x ^= nums[i];                           // XOR into first group.
            }
            else {                                      // Otherwise,
                y ^= nums[i];                           // XOR into second group.
            }

            // Divide numbers from 1 to n.
            if ((i + 1) & setBit) {                     // If the set bit is present,
                x ^= (i + 1);                           // XOR into first group.
            }
            else {                                      // Otherwise,
                y ^= (i + 1);                           // XOR into second group.
            }
        }

        // x and y contain the missing and repeating numbers,
        // but we don't know which is which yet.

        int missing, repeating;
        int count = 0;

        // Count how many times x appears in the array.
        for (int i = 0; i < n; i++) {

            if (nums[i] == x) {
                count++;
            }
        }

        if (count == 0) {                               // x is not present, so it is missing.
            missing = x;
            repeating = y;
        }
        else {                                          // x appears in the array, so it is repeating.
            missing = y;
            repeating = x;
        }

        return {repeating, missing};                    // Return [repeating, missing].
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



/*-------------------------------------------------- Explanation ----------------------------------------------

// Step 1:
// Store the size of the array.
// Example:
// nums = [1,2,3,6,7,5,7]
// n = 7
int n = nums.size();

-----------------------------------------------------------------------------------------------------------------------
// Step 2:
// Initialize xorValue to store the XOR of all array elements
// and all numbers from 1 to n.
int xorValue = 0;

-----------------------------------------------------------------------------------------------------------------------
// Step 3:
// XOR every array element and every number from 1 to n.
//
// Array      : 1 ^ 2 ^ 3 ^ 6 ^ 7 ^ 5 ^ 7
// Numbers    : 1 ^ 2 ^ 3 ^ 4 ^ 5 ^ 6 ^ 7
//
// Common numbers cancel each other because:
// a ^ a = 0
//
// Finally,
// xorValue = Missing ^ Repeating
//
// Example:
// xorValue = 4 ^ 7 = 3
for (int i = 0; i < n; i++) {
    xorValue ^= nums[i];
    xorValue ^= (i + 1);
}

-----------------------------------------------------------------------------------------------------------------------
// Step 4:
// Find the rightmost set bit in xorValue.
//
// Formula:
// setBit = xorValue & ~(xorValue - 1)
//
// Example:
// xorValue = 3
// Binary = 011
//
// xorValue-1 = 2
// Binary = 010
//
// ~(010) = 101
//
// 011 & 101 = 001
//
// setBit = 1
//
// This bit is different in the missing and repeating numbers,
// so it helps separate them into two groups.
int setBit = xorValue & ~(xorValue - 1);

-----------------------------------------------------------------------------------------------------------------------
// Step 5:
// Initialize x and y.
// After grouping and XORing,
// one will become the missing number
// and the other will become the repeating number.
int x = 0, y = 0;

-----------------------------------------------------------------------------------------------------------------------
// Step 6:
// Divide all array elements and numbers from 1 to n
// into two groups based on the rightmost set bit.
//
// Group 1 -> set bit is 1
// Group 2 -> set bit is 0
//
// XOR numbers within each group.
//
// Since equal numbers cancel each other,
// only the missing and repeating numbers remain.
//
// Example:
//
// Group 1:
// Array + Numbers -> x = 7
//
// Group 2:
// Array + Numbers -> y = 4
//
// (or vice versa)
for (int i = 0; i < n; i++) {

    // Divide array elements.
    if (nums[i] & setBit) {
        x ^= nums[i];
    }
    else {
        y ^= nums[i];
    }

    // Divide numbers from 1 to n.
    if ((i + 1) & setBit) {
        x ^= (i + 1);
    }
    else {
        y ^= (i + 1);
    }
}

-----------------------------------------------------------------------------------------------------------------------
// Step 7:
// At this point,
// x and y contain the two required numbers,
// but we don't yet know which one is missing
// and which one is repeating.

-----------------------------------------------------------------------------------------------------------------------
// Step 8:
// Declare variables for the final answer
// and initialize count to count occurrences of x.
int missing, repeating;
int count = 0;

-----------------------------------------------------------------------------------------------------------------------
// Step 9:
// Count how many times x appears in the array.
//
// If x appears:
// x is the repeating number.
//
// If x never appears:
// x is the missing number.
for (int i = 0; i < n; i++) {

    if (nums[i] == x) {
        count++;
    }
}

-----------------------------------------------------------------------------------------------------------------------
// Step 10:
// Decide which value is missing
// and which is repeating.
//
// count == 0
// x is missing
// y is repeating
//
// Otherwise
// x is repeating
// y is missing.
if (count == 0) {
    missing = x;
    repeating = y;
}
else {
    missing = y;
    repeating = x;
}

-----------------------------------------------------------------------------------------------------------------------
// Step 11:
// Return the repeating number first
// and the missing number second.
//
// Example:
// Output = [7,4]
return {repeating, missing};



=======================================================================================================================
One-line explanation of each code statement (compact)
=======================================================================================================================

int n = nums.size();

Stores the total number of elements in the array.

-----------------------------------------------------------------------------------------------------------------------
int xorValue = 0;

Initializes a variable to store the XOR of all array elements and numbers from 1 to n.

-----------------------------------------------------------------------------------------------------------------------
for (int i = 0; i < n; i++) {

Traverses the array once to compute the combined XOR.

-----------------------------------------------------------------------------------------------------------------------
xorValue ^= nums[i];

XORs the current array element with xorValue.

-----------------------------------------------------------------------------------------------------------------------
xorValue ^= (i + 1);

XORs the corresponding number from 1 to n with xorValue, leaving missing ^ repeating after all common numbers cancel.

-----------------------------------------------------------------------------------------------------------------------
int setBit = xorValue & ~(xorValue - 1);

Finds the rightmost set bit in xorValue to separate the missing and repeating numbers into two different groups.

-----------------------------------------------------------------------------------------------------------------------
int x = 0, y = 0;

Initializes two variables that will eventually store the missing and repeating numbers.

-----------------------------------------------------------------------------------------------------------------------
if (nums[i] & setBit)

Checks whether the current array element belongs to the first group based on the selected set bit.

-----------------------------------------------------------------------------------------------------------------------
x ^= nums[i];

XORs the array element into the first group.

-----------------------------------------------------------------------------------------------------------------------
y ^= nums[i];

XORs the array element into the second group.

-----------------------------------------------------------------------------------------------------------------------
if ((i + 1) & setBit)

Checks whether the current number from 1 to n belongs to the first group.

-----------------------------------------------------------------------------------------------------------------------
x ^= (i + 1);

XORs the number from 1 to n into the first group.

-----------------------------------------------------------------------------------------------------------------------
y ^= (i + 1);

XORs the number from 1 to n into the second group.

-----------------------------------------------------------------------------------------------------------------------
int missing, repeating;

Declares variables to store the final missing and repeating numbers.

-----------------------------------------------------------------------------------------------------------------------
int count = 0;

Initializes a counter to check whether x exists in the array.

-----------------------------------------------------------------------------------------------------------------------
for (int i = 0; i < n; i++)

Traverses the array to count the occurrences of x.

-----------------------------------------------------------------------------------------------------------------------
if (nums[i] == x)

Checks whether the current element is equal to x.

-----------------------------------------------------------------------------------------------------------------------
count++;

Increments the count whenever x is found in the array.

-----------------------------------------------------------------------------------------------------------------------
if (count == 0)

If x does not appear in the array, then x is the missing number.

-----------------------------------------------------------------------------------------------------------------------
missing = x;

Assigns x as the missing number.

-----------------------------------------------------------------------------------------------------------------------
repeating = y;

Assigns y as the repeating number.

-----------------------------------------------------------------------------------------------------------------------
missing = y;

Assigns y as the missing number when x is found in the array.

-----------------------------------------------------------------------------------------------------------------------
repeating = x;

Assigns x as the repeating number.

-----------------------------------------------------------------------------------------------------------------------
return {repeating, missing};

Returns the repeating number first and the missing number second as the required answer.


----------------------------------------------------------------------------------------------------------------------- */