/*
================================================================================================================
Q12. Longest Substring With At Most K Distinct Characters

Problem :
Given a string s and an integer k, find the length of the
longest substring containing at most k distinct characters.

Input : s = "eceba", k = 2
Output: 3

Input : s = "aa", k = 1
Output: 2

Input : s = "eceba", k = 2
Output: 3

Input : s = "ccaabbb", k = 2
Output: 5

Input : s = "abc", k = 2
Output: 2

Input : s = "aaaaa", k = 1
Output: 5

Input : s = "abcabc", k = 3
Output: 6

Input : s = "aabbcc", k = 2
Output: 4

Input : s = "abaccc", k = 2
Output: 4

Input : s = "a", k = 1
Output: 1

Input : s = "abcdef", k = 1
Output: 1
================================================================================================================
*/


#include<bits/stdc++.h>
using namespace std ;


class Solution {
public:
    int longestSubstring(string s, int k) {
        
    }
};


int main() {
    string s;
    int k;
    cin >> s >> k;

    Solution obj;
    cout << obj.longestSubstring(s, k);
    return 0;
}
