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
        int ans = 0;
        int priority = 0;
        
        for(int i = s.size() - 1 ; i >= 0 ; i--){

            char c = s[i];
            
            if(c == 'I'){
                if(priority > 1) { ans--; continue;}
                ans++;
                priority = 1;
            }
            
            else if(c == 'V'){
                if(priority > 2) { ans-=5; continue;}
                ans+=5;
                priority = 2;
            }
            
            else if(c == 'X'){
                if(priority > 3) { ans-=10; continue;}
                ans+=10;
                priority = 3;
            }
            
            else if(c == 'L'){
                if(priority > 4) { ans-=50; continue;}
                ans+=50;
                priority = 4;
            }
            
            else if(c == 'C'){
                if(priority > 5) { ans-=100; continue;}
                ans+=100;
                priority = 5;
            }
            
            else if(c == 'D'){
                if(priority > 6) { ans-=500; continue;}
                ans+=500;
                priority = 6;
            }
            
            else if(c == 'M'){
                if(priority > 7) { ans-=1000; continue;}
                ans+=1000;
                priority = 7;
            }
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

Input : s = "MCMXCIV"

Initial State
ans = 0
priority = 0


We traverse from right to left : 
______________________________________________________________________________________________________
|  i | Character | Value | Priority Before |    Condition    |   Operation   |  ans | Priority After |
| -: | :-------: | ----: | :-------------: | :-------------: | :-----------: | ---: | :------------: |
|  6 |     V     |     5 |        0        | `0 > 2` (False) |   `ans += 5`  |    5 |        2       |
|  5 |     I     |     1 |        2        |  `2 > 1` (True) |   `ans -= 1`  |    4 |        2       |
|  4 |     C     |   100 |        2        | `2 > 5` (False) |  `ans += 100` |  104 |        5       |
|  3 |     X     |    10 |        5        |  `5 > 3` (True) |  `ans -= 10`  |   94 |        5       |
|  2 |     M     |  1000 |        5        | `5 > 7` (False) | `ans += 1000` | 1094 |        7       |
|  1 |     C     |   100 |        7        |  `7 > 5` (True) |  `ans -= 100` |  994 |        7       |
|  0 |     M     |  1000 |        7        | `7 > 7` (False) | `ans += 1000` | 1994 |        7       |






What does priority mean?
priority stores the largest Roman numeral seen so far while scanning from right to left.
____________________
| Roman | Priority |
| ----- | -------- |
| I     | 1        |
| V     | 2        |
| X     | 3        |
| L     | 4        |
| C     | 5        |
| D     | 6        |
| M     | 7        |




Rule : 

If the current symbol has lower priority than a symbol already seen on its right (priority > currentPriority), subtract its value.
Otherwise, add its value and update priority to the current symbol's priority.

For example, in "IV":

Start at V → add 5, priority = 2.
Move to I → priority (2) > 1, so subtract 1.

Result: 5 - 1 = 4.

-------------------------------------------------------------------------------------------------------------------------- */