/*

Input: s = "(()())(())"
Output: "()()()"
Explanation: 
The input string is "(()())(())", with primitive decomposition "(()())" + "(())".
After removing outer parentheses of each part, this is "()()" + "()" = "()()()".


Input: s = "(()())(())(()(()))"
Output: "()()()()(())"
Explanation: 
The input string is "(()())(())(()(()))", with primitive decomposition "(()())" + "(())" + "(()(()))".
After removing outer parentheses of each part, this is "()()" + "()" + "()(())" = "()()()()(())".


Input: s = "()()"
Output: ""
Explanation: 
The input string is "()()", with primitive decomposition "()" + "()".
After removing outer parentheses of each part, this is "" + "" = "".

*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {

        string ans = "";                // Stores final answer
        int n = s.size();               // Length of string

        int start = 0;                  // Starting index of current primitive
        int balance = 0;                // Tracks open and close brackets

        for (int i = 0; i < n; i++) {

            if (s[i] == '(')
                balance++;              // Opening bracket

            else
                balance--;              // Closing bracket

            if (balance == 0) {                             // Primitive ends whenever balance becomes 0

                for (int j = start + 1; j < i; j++) {       // Copy everything except first and last bracket
                    ans += s[j];
                }

                start = i + 1;                              // Next primitive starts after current one
            }
        }

        return ans;                                         // return the answer string  
    }
};

int main() {

    Solution obj;

    string s;
    cin >> s;

    cout << obj.removeOuterParentheses(s);

    return 0;
}

// Time Complexity : O(N)
// Space Complexity : O(N)




/* =======================================================================================================================

Approach 

--------------------------------------------------------------------------------------------------------------------------

Observation :

Whenever we enter a primitive,
the first '(' is outermost.

Whenever we leave a primitive,
the last ')' is outermost.

So,

Ignore first '('
Ignore last ')'
Keep everything else.

To know whether a bracket is outermost, maintain a balance.

--------------------------------------------------------------------------------------------------------------------------

Brute Force Approach
Idea : 

Traverse the string.
Find one primitive at a time using balance.
Store its starting index.
When balance becomes 0, primitive ends.
Copy everything except first and last bracket.

-------------------------------------------------------------------------------------------------------------------------

DRY RUN CONCEPT :

INDEX   :    0   1   2   3   4   5    6   7   8   9
INPUT   :    (   (   )   (   )   )    (   (   )   )
BALANCE :    1   2   1   2   1   0    1   2   1   0 
             ↓                   ↓    ↓           ↓
            start from 1 to this 0    from 1  to  0
                 ↓           ↓            ↓   ↓
                j pointer (ans)           (ans)

======================================================================================================================= */