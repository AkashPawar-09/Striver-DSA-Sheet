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

        vector<int> freq(n + 1, 0);                 // Frequency array of size n+1.
        // to go thorough n elements of nums , create n+1 size frequency array & fill it with 0 
        // Index represents the number and value represents its frequency.
        
        int repeating = -1;                         // Stores the repeating number.
        int missing = -1;                           // Stores the missing number.

        for (int i = 0; i < n; i++) {               // Traverse the given array.
            freq[nums[i]]++;                        // Increase the frequency of each element.
        }

        for (int i = 1; i <= n; i++) {              // Check the frequency of every number from 1 to n.

            if (freq[i] == 0)                       // If frequency is 0,
                missing = i;                        // then this number is missing.

            else if (freq[i] == 2)                  // If frequency is 2,
                repeating = i;                      // then this number is repeating.
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


// Time Complexity : O(2N)
// Space Complexity : O(N)


/* -------------------------------------------------- Explanation --------------------------------------------------

======================================== Example : nums = {4, 3, 6, 2, 1, 1} =======================================

Step 1: Create the frequency array
vector<int> freq(n + 1, 0);

Since n = 6, the frequency array has size 7.

Index	0	1	2	3	4	5	6
freq	0	0	0	0	0	0	0

====================================================================================================================

First Loop : 
----------------------------------------+
for (int i = 0; i < n; i++) {           |
    freq[nums[i]]++;                    |
}                                       |
----------------------------------------+

-- What does this do?

It counts how many times every number appears in the array.

---------------------------------------- Iteration 1 ----------------------------------------

============================|| Example : nums = {4, 3, 6, 2, 1, 1} ||========================

i = 0
nums[0] = 4
freq[4]++;

Frequency array becomes

Number	1	2	3	4	5	6
Freq	0	0	0	1	0	0


---------------------------------------- Iteration 2 ----------------------------------------

i = 1
nums[1] = 3
freq[3]++;
Number	1	2	3	4	5	6
Freq	0	0	1	1	0	0


---------------------------------------- Iteration 3 ----------------------------------------

i = 2
nums[2] = 6
freq[6]++;
Number	1	2	3	4	5	6
Freq	0	0	1	1	0	1


---------------------------------------- Iteration 4 ----------------------------------------

i = 3
nums[3] = 2
freq[2]++;
Number	1	2	3	4	5	6
Freq	0	1	1	1	0	1


---------------------------------------- Iteration 5 ----------------------------------------

i = 4
nums[4] = 1
freq[1]++;
Number	1	2	3	4	5	6
Freq	1	1	1	1	0	1


---------------------------------------- Iteration 6 ----------------------------------------

i = 5
nums[5] = 1
freq[1]++;
Number	1	2	3	4	5	6
Freq	2	1	1	1	0	1


Now the frequency array is complete.

====================================================================================================================


Second Loop : 

------------------------------------+
for (int i = 1; i <= n; i++) {      |
    if (freq[i] == 0)               |
        missing = i;                |
                                    |
    else if (freq[i] == 2)          |
        repeating = i;              |
}                                   |
                                    |
return {repeating, missing};        |
------------------------------------+

In this loop , we cheak conditions and return answer 

==================================================================================================================== */