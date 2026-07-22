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

        int n = s.length();

        int start = 0;
        int maxLen = 1;

        for (int i = 0; i < n; i++) {

            // j = 0 -> Odd length palindrome
            // j = 1 -> Even length palindrome
            for (int j = 0; j <= 1; j++) {

                int low = i;
                int high = i + j;

                while (low >= 0 && high < n && s[low] == s[high]) {

                    int currLen = high - low + 1;

                    if (currLen > maxLen) {
                        start = low;
                        maxLen = currLen;
                    }

                    low--;
                    high++;
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
// Space Complexity : O(1)

