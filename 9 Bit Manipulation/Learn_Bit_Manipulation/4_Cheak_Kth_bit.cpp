/* -----------------------------------------------------------------------------------------------------------------

1 << 0 = 1
1 << 1 = 2
1 << 2 = 4
1 << 3 = 8
1 << 4 = 16
1 << 5 = 32

--------------------------------------------------------------------------------------------------------------------

Input: n = 4, k = 0
Output: false
Explanation: Binary representation of 4 is 100, in which 0th index bit from LSB is not set. So, return false.

Input: n = 4, k = 2
Output: true
Explanation: Binary representation of 4 is 100, in which 2nd index bit from LSB is set. So, return true.

Input: n = 500, k = 3
Output: false
Explanation: Binary representation of 500 is 111110100, in which 3rd index bit from LSB is not set. So, return false.

--------------------------------------------------------------------------------------------------------------------
Example 1

Suppose: n = 5 , k = 2
Binary representation: 5 = 0101

Positions:
0 1 2 3
↓ ↓ ↓ ↓
1 0 1 0

Actually, writing from right to left:

3 2 1 0
0 1 0 1

Therefore: bit 2 = 1
So the answer should be: true

-------------------------------------------------------------------------------------------------------------------- */

// Question: Given n and k, check whether the K-th bit of n is 1.

#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    bool checkKthBit(int n, int k) {
        return (n & (1 << k)) != 0;
    }
};



int main() {
    Solution obj;
    int n, k;
    cin >> n >> k;
    cout << boolalpha << obj.checkKthBit(n, k);
    return 0;
}




// Time Complexity: O(1)
// Space Complexity: O(1)