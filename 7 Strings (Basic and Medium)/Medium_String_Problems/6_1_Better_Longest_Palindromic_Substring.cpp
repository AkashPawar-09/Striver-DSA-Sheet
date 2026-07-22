/*

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.


Input: s = "cbbd"
Output: "bb"

*/


#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();

        vector<vector<bool>> dp(n, vector<bool>(n, false));

        int start = 0;
        int maxLen = 1;

        // All substrings of length 1 are palindromes
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }

        // Check substrings of length 2
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                start = i;
                maxLen = 2;
            }
        }

        // Check substrings of length 3 and more
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {

                int j = i + len - 1;

                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;

                    if (len > maxLen) {
                        start = i;
                        maxLen = len;
                    }
                }
            }
        }

        return s.substr(start, maxLen);
    }
};


int main() {
    Solution obj;

    string s;
    cout << "Enter the string: ";
    cin >> s;

    cout << "Longest Palindromic Substring: " << obj.longestPalindrome(s) << endl;

    return 0;
}


// Time Complexity : O(N²)
// Space Complexity : O(N²)

