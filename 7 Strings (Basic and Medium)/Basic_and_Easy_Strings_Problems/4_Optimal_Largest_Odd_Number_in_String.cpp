/*

Input: num = "52"
Output: "5"
Explanation: The only non-empty substrings are "5", "2", and "52". "5" is the only odd number.


Input: num = "4206"
Output: ""
Explanation: There are no odd numbers in "4206".


Input: num = "35427"
Output: "35427"
Explanation: "35427" is already an odd number.


Input: num = "35420"
Output: "35"


Input: num = "42132"
Output: "4213"

*/



#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    string largestOddNumber(string num) {
        for (int i = num.size() - 1; i >= 0; i--) {     // traverse from last element to first 
            if ((num[i] - '0') % 2 == 1) {              // if any element is found odd
                return num.substr(0, i + 1);            // then return substring from start to that element 
            }
        }
        return "";                                      // if no element is odd then return ""
    }
};

int main() {
    Solution obj;

    string num;
    cin >> num;

    cout << obj.largestOddNumber(num);

    return 0;
}


// Time Complexity : O(N)
// Space Complexity : O(1)



/* --------------------------------------------------------------------------------------------------------------------------

You are given a string containing digits.

Example:
"42132"
Notice this is not an integer.
It is a string.

So

num[0] = '4'
num[1] = '2'
num[2] = '1'
num[3] = '3'
num[4] = '2'

These are characters, not integers.

--------------------------------------------------------------------------------------------------------------------------

Why are digits stored as characters?

Every character has an ASCII value.
_____________________
| Character | ASCII |
| --------- | ----- |
| '0'       | 48    |
| '1'       | 49    |
| '2'       | 50    |
| '3'       | 51    |
| '4'       | 52    |
| '5'       | 53    |
| '6'       | 54    |
| '7'       | 55    |
| '8'       | 56    |
| '9'       | 57    |

--------------------------------------------------------------------------------------------------------------------------

Why do we subtract '0'

Suppose
num[i] = '4'

Internally
num[i] = 52
But we need
4

How?

'4' - '0'
becomes
52 - 48 = 4

Similarly,
'8' - '0'
56 - 48
= 8

Another example :
'1' - '0'
49 - 48
=1

So
(num[i] - '0')

means
Convert the character digit into its integer value.

--------------------------------------------------------------------------------------------------------------------------

Character   :   '4'     '2'     '1'     '3'     '2'
ASCII       :    52     50      49      51      50

-------------------------------------------------------------------------------------------------------------------------- */