/*

Input: s = "(1+(2*3)+((8)/4))+1"
Output: 3
Explanation:
Digit 8 is inside of 3 nested parentheses in the string.


Input: s = "(1)+((2))+(((3)))"
Output: 3
Explanation:
Digit 3 is inside of 3 nested parentheses in the string.


Input: s = "()(())((()()))"
Output: 3

*/


#include<bits/stdc++.h>
using namespace std ;


class Solution {
public:
    int maxDepth(string s) {

        int balance = 0;
        int depth = 0;

        for (char ch : s) {                     // traverse through all chars in string "s"

            if (ch == '(') {                    // if char is "("
                balance++;                      // increament balance 
                depth = max(depth, balance);    // store maximum depth using current balance
            }
            else if (ch == ')') {               // else if char is "("
                balance--;                      // decreament balance 
            }
        }

        return depth;                           // return updated depth 
    }
};  


// Time Complexity : O(N)
// Space Complexity : O(1)
