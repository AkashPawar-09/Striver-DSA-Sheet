/*

You are given a string s and an integer k. You can choose any character of the string and 
change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

Input: s = "AAAA", k = 2
Output: 4

Input: s = "ABCD", k = 1
Output: 2

Input: s = "AABBC", k = 1
Output: 4

Input: s = "AABBC", k = 2
Output: 5

Input: s = "BAAAB", k = 1
Output: 4

Input: s = "ABBB", k = 1
Output: 4

Input: s = "ABBB", k = 0
Output: 3

Input: s = "ABABBA", k = 2
Output: 6

Input: s = "ABCDE", k = 2
Output: 3

Input: s = "AAABBB", k = 2
Output: 5

*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int characterReplacement(string s, int k) {

        // Store frequency of each character inside the current sliding window
        unordered_map<char, int> freq;

        int left = 0;
        int maxFreq = 0;
        int ans = 0;

        for (int right = 0; right < s.size(); right++) {

            // Add the current character to the window
            freq[s[right]]++;

            // Update the highest frequency of any character in the window
            maxFreq = max(maxFreq, freq[s[right]]);

            // Characters that need to be replaced: window length - most frequent character count
            while ((right - left + 1) - maxFreq > k) {

                // Remove the leftmost character from the current window
                freq[s[left]]--;

                // Move left pointer forward
                left++;
            }

            // Current window is valid, so update the maximum length
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};




int main() {
    Solution obj;
    string s;
    int k;
    cout << "Enter string: ";
    cin >> s;
    cout << "Enter k: ";
    cin >> k;

    cout << "Answer: " << obj.characterReplacement(s, k);
    return 0;
}