/*

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.


Input: s = "cbbd"
Output: "bb"

*/


#include <iostream>
using namespace std;


string getLongestPal(string &s) {
    int n = s.size();

    int maxLen = 1;
    int start = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {

            bool isPal = true;
            int low = i;
            int high = j;

            while (low < high) {
                if (s[low] != s[high]) {
                    isPal = false;
                    break;
                }
                low++;
                high--;
            }

            if (isPal && (j - i + 1) > maxLen) {
                start = i;
                maxLen = j - i + 1;
            }
        }
    }

    return s.substr(start, maxLen);
}


int main() {
    string s;

    cout << "Enter the string: ";
    cin >> s;

    cout << "Longest Palindromic Substring: " << getLongestPal(s) << endl;

    return 0;
}


// Time Complexity : O(N³)
// Space Complexity : O(1)

