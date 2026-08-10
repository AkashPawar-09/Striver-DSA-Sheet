/* -----------------------------------------------------------------------------------------------------------------
Input:  12
Output: 8
Explanation: Binary representation of 12 is 00...01100. 
If we turn of the rightmost set bit, we get 00...01000 which is binary representation of 8

Input: 7 
Output: 6 
Explanation: Binary representation for 7 is 00...00111 and for 6, it is 00...00110

Input: 0
Output:0 
Explanation: There is no rightmost set bit

----------------------------------------------------------------------------------------------------------------------

//Bits :       128 64 32 16  8421
1 << 0 = 1      0   0  0  0  0001
1 << 1 = 2      0   0  0  0  0010
1 << 2 = 4      0   0  0  0  0100
1 << 3 = 8      0   0  0  0  1000
1 << 4 = 16     0   0  0  1  0000
1 << 5 = 32     0   0  1  0  0000
1 << 6 = 64     0   0  1  0  0000
1 << 7 = 128    0   0  1  0  0000

-------------------------------------------------------------------------------------------------------------------- */


// Question: Remove the rightmost 1 bit from n.

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

    int removeRightmostSetBit(int n) {
        if (n == 0) return 0;
        int pos = 0;
        while (((n >> pos) & 1) == 0) {
            pos++;
        }
        n = n ^ (1 << pos);
        return n;
    }

    // Time Complexity: O(log n)
    // Space Complexity: O(1)



    int removeRightmostSetBit2(int n) {
        return (n & (n - 1)); 
    }

    // Time Complexity: O(log n)
    // Space Complexity: O(1)



    int removeRightmostSetBit3(int n) {
        return n -= (n & (-n)); 
    }

    // Time Complexity: O(log n)
    // Space Complexity: O(1)

};



int main() {
    Solution obj;

    int n;
    cin >> n;

    cout << obj.removeRightmostSetBit(n) << endl ;
    cout << obj.removeRightmostSetBit2(n)<< endl ;
    cout << obj.removeRightmostSetBit3(n)<< endl ;

    return 0;
}





/*

Example 1: n = 12
12 = 1100
________________________________________________________________
| Step | `pos` | `(n >> pos) & 1` | Condition        | Action  |
| ---- | ----: | ---------------: | ---------------- | ------- |
| 1    |     0 |                0 | `0 == 0` → True  | `pos++` |
| 2    |     1 |                0 | `0 == 0` → True  | `pos++` |
| 3    |     2 |                1 | `1 == 0` → False | Stop    |

Now:
pos = 2

n = 1100
1 << 2 = 0100

1100
^0100

1000 = 8

Output: 8

*/