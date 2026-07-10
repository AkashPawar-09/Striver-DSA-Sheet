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

        long long n = nums.size();                           // Store the size of the array.

        // SN = Sum of first n natural numbers.
        long long SN = (n * (n + 1)) / 2;

        // S2N = Sum of squares of first n natural numbers.
        long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;

        long long S = 0, S2 = 0;                             // Store actual sum and actual square sum.

        // Calculate the actual sum and actual square sum.
        for (int i = 0; i < n; i++) {

            S += nums[i];

            S2 += (long long)nums[i] * (long long)nums[i];
        }

        // S - SN = repeating - missing.
        long long val1 = S - SN;

        // S2 - S2N = repeating² - missing².
        long long val2 = S2 - S2N;

        // val2 / val1 = repeating + missing.
        val2 = val2 / val1;

        // repeating = ( (repeating - missing) + (repeating + missing) ) / 2.
        long long repeating = (val1 + val2) / 2;

        // missing = repeating - (repeating - missing).
        long long missing = repeating - val1;

        return {(int)repeating, (int)missing};               // Return [repeating, missing].
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



/*-------------------------------------------------- Explanation ------------------------------------------------------

// Step 1:
// Store the size of the array.
// n = total number of elements (numbers should ideally be from 1 to n).
long long n = nums.size();

-----------------------------------------------------------------------------------------------------------------------
// Step 2:
// Calculate the expected sum of the first n natural numbers using:
// SN = n * (n + 1) / 2
// Example: n = 7
// SN = 7 * 8 / 2 = 28
long long SN = (n * (n + 1)) / 2;

-----------------------------------------------------------------------------------------------------------------------
// Step 3:
// Calculate the expected sum of squares of the first n natural numbers using:
// S2N = n * (n + 1) * (2 * n + 1) / 6
// Example: n = 7
// S2N = 7 * 8 * 15 / 6 = 140
long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;

-----------------------------------------------------------------------------------------------------------------------
// Step 4:
// Initialize variables to store the actual sum (S)
// and actual sum of squares (S2) of the given array.
long long S = 0, S2 = 0;

-----------------------------------------------------------------------------------------------------------------------
// Step 5:
// Traverse the array once.
// Add each element to S.
// Add the square of each element to S2.
// Example:
// nums = [1,2,3,6,7,5,7]
// S  = 31
// S2 = 173
for (int i = 0; i < n; i++) {
    S += nums[i];
    S2 += (long long)nums[i] * (long long)nums[i];
}

-----------------------------------------------------------------------------------------------------------------------
// Step 6:
// Find the difference between the actual sum and expected sum.
// Since one number is repeated and one is missing:
//
// S - SN = repeating - missing
//
// Example:
// 31 - 28 = 3
// val1 = 7 - 4 = 3
long long val1 = S - SN;

-----------------------------------------------------------------------------------------------------------------------
// Step 7:
// Find the difference between the actual square sum and expected square sum.
//
// S2 - S2N = repeating² - missing²
//
// Example:
// 173 - 140 = 33
// val2 = 7² - 4² = 49 - 16 = 33
long long val2 = S2 - S2N;

-----------------------------------------------------------------------------------------------------------------------
// Step 8:
// Use the identity:
//
// a² - b² = (a - b)(a + b)
//
// Therefore:
//
// val2 / val1 = repeating + missing
//
// Example:
// 33 / 3 = 11
// val2 = 11 = 7 + 4
val2 = val2 / val1;

-----------------------------------------------------------------------------------------------------------------------
// Step 9:
// Now we know:
//
// repeating - missing = val1
// repeating + missing = val2
//
// Adding both equations:
//
// 2 × repeating = val1 + val2
//
// repeating = (val1 + val2) / 2
//
// Example:
// (3 + 11) / 2 = 7
long long repeating = (val1 + val2) / 2;

-----------------------------------------------------------------------------------------------------------------------
// Step 10:
// Find the missing number using:
//
// missing = repeating - (repeating - missing)
//
// missing = repeating - val1
//
// Example:
// 7 - 3 = 4
long long missing = repeating - val1;

-----------------------------------------------------------------------------------------------------------------------
// Step 11:
// Return the repeating number first
// and the missing number second.
//
// Example:
// Output = [7, 4]
return {(int)repeating, (int)missing};


=======================================================================================================================
One-line explanation of each code statement (compact)
=======================================================================================================================


long long n = nums.size();                           // Store the size of the array.

Stores the total number of elements in the array, which is also the range of numbers from 1 to n.

-----------------------------------------------------------------------------------------------------------------------
long long SN = (n * (n + 1)) / 2;

Calculates the expected sum of numbers from 1 to n using the arithmetic progression formula.

-----------------------------------------------------------------------------------------------------------------------
long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;

Calculates the expected sum of squares of numbers from 1 to n using the mathematical square-sum formula.

-----------------------------------------------------------------------------------------------------------------------
long long S = 0, S2 = 0;

Initializes variables to store the actual sum and actual sum of squares of the given array.

-----------------------------------------------------------------------------------------------------------------------
for (int i = 0; i < n; i++) {

Traverses every element of the array exactly once.

-----------------------------------------------------------------------------------------------------------------------
S += nums[i];

Adds the current element to compute the actual total sum of the array.

-----------------------------------------------------------------------------------------------------------------------
S2 += (long long)nums[i] * (long long)nums[i];

Adds the square of the current element to compute the actual sum of squares while using long long to prevent overflow.

-----------------------------------------------------------------------------------------------------------------------
long long val1 = S - SN;

Finds the difference between actual and expected sums, which equals repeating − missing.

-----------------------------------------------------------------------------------------------------------------------
long long val2 = S2 - S2N;

Finds the difference between actual and expected square sums, which equals repeating² − missing².

-----------------------------------------------------------------------------------------------------------------------
val2 = val2 / val1;

Uses the identity a²−b²=(a−b)(a+b) to obtain repeating + missing.

-----------------------------------------------------------------------------------------------------------------------
long long repeating = (val1 + val2) / 2;

Adds the two equations (repeating−missing) and (repeating+missing) to calculate the repeating number.

-----------------------------------------------------------------------------------------------------------------------
long long missing = repeating - val1;

Uses missing = repeating − (repeating−missing) to calculate the missing number.

-----------------------------------------------------------------------------------------------------------------------
return {(int)repeating, (int)missing};

Returns the repeating number first and the missing number second as the required answer.


----------------------------------------------------------------------------------------------------------------------- */