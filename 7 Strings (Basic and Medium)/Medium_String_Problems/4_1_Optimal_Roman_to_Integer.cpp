/*

Input: s = "III"
Output: 3
Explanation: III = 3.


Input: s = "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.


Input: s = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.

*/


#include<bits/stdc++.h>
using namespace std ;


class Solution {
public:
    int romanToInt(string s) {
        int n = s.size() ;
        
        unordered_map<char, int> mp = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int ans = 0;

        for (int i = 0; i < n; i++) {

            if (i + 1 < n && mp[s[i]] < mp[s[i + 1]])
                ans = ans - mp[s[i]];
            else
                ans = ans + mp[s[i]];
        }

        return ans;
    }
};


int main() {

    Solution obj;

    string s;
    cin >> s;

    cout << obj.romanToInt(s);

    return 0;
}


// Time Complexity : O(n)
// Space Complexity : O(1)


/* --------------------------------------------------------------------------------------------------------------------------

INPUT : s = "MCMXCIV"
Output: 1994

+-----------+------+-----+------+----+-----+----+----+
| Index     |    0 |   1 |    2 |  3 |   4 |  5 |  6 |
| --------- | ---- | --- | ---- | -- | --- | -- | -- |
| Char      |    M |   C |    M |  X |   C |  I |  V |
| Value     | 1000 | 100 | 1000 | 10 | 100 |  1 |  5 |
+-----------+------+-----+------+----+-----+----+----+



DRY RUN TABLE :
_____________________________________________________________________________________
|  i | Current | Value | Next | Condition (`current < next`) | Operation |      ans |
| -- | ------- | ----- | ---- | ---------------------------- | --------- | -------- |
|  0 |    M    |  1000 |   C  |             False            |     +1000 |     1000 |
|  1 |    C    |   100 |   M  |             True             |      -100 |      900 |
|  2 |    M    |  1000 |   X  |             False            |     +1000 |     1900 |
|  3 |    X    |    10 |   C  |             True             |       -10 |     1890 |
|  4 |    C    |   100 |   I  |             False            |      +100 |     1990 |
|  5 |    I    |     1 |   V  |             True             |        -1 |     1989 |
|  6 |    V    |     5 |   —  |             False            |        +5 |     1994 |
+----+---------+-------+------+------------------------------+-----------+----------+



Why do we subtract sometimes?
    - Roman numerals follow a special rule:
____________________________
| Roman |            Value |
| ----- | ---------------: |
| IV    |        4 = 5 − 1 |
| IX    |       9 = 10 − 1 |
| XL    |     40 = 50 − 10 |
| XC    |    90 = 100 − 10 |
| CD    |  400 = 500 − 100 |
| CM    | 900 = 1000 − 100 |


-------------------------------------------------------------------------------------------------------------------------- */