/*
================================================================================================================
Q11. Longest Substring Without Repeating Characters

Problem :
Given a string s, find the length of the longest substring
that contains no repeating characters.


Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
================================================================================================================
*/


#include<bits/stdc++.h>
using namespace std ;


class Solution {
public:
    int longestSubstring(string s) {
        int n = s.size() ;
        int i = 0 ;
        int maxLength = 0 ;
        unordered_map<char,int> freq ;

        for(int j = 0 ; j < n ; j++) {
            freq[s[j]]++;                   // store frequency of each char like <alphabet,occurance> 
            while(freq[s[j]] > 1){          // if element have freq 2 (repeated character)
                freq[s[i]]--;               // then decrease frequency of leftmost element
                if (freq[s[i]] == 0) {      // until frequency becomes 0
                    freq.erase(s[i]);       // when its frequency becomes 0 , remove that char
                }
                i++;                        // increse leftmost pointer to get new char
            }
            maxLength = max(maxLength , j-i+1 ) ;   // calculate max Length of substring
        }
        return maxLength ;
    }
};


int main() {
    string s;
    cin >> s;

    Solution obj;
    cout << obj.longestSubstring(s);
    return 0;
}
