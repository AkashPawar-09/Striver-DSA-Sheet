/*

Input: s = "the sky is blue"
Output: "blue is sky the"


Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.


Input: s = "a good example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {

        reverse(s.begin(), s.end());                        // Reverse the entire string
        // "the sky is blue" -> "eulb si yks eht"

        int n = s.size();

        int i = 0, j = 0;

        while (i < n) {

            while (i < n && s[i] == ' ') i++;           // if there is space at starting skip it

            if (i >= n) break;                          // if i reach to end , stop the loop

            if (j != 0) s[j++] = ' ';                   // Add exactly one space before every word , except the first word

            int start = j;                              // Remember where current word starts

            while (i < n && s[i] != ' ') s[j++] = s[i++];       // Copy current word

            reverse(s.begin() + start, s.begin() + j);          // Reverse only the copied word
            // eulb -> blue

        }

        s.resize(j);                                    // Remove unused characters left at the end

        return s;                                       // returns string 
    }
};

int main() {

    Solution obj;

    string s;
    getline(cin, s);

    cout << obj.reverseWords(s);

    return 0;
}



// Time Complexity : O(N)
// Space Complexity : O(1)
