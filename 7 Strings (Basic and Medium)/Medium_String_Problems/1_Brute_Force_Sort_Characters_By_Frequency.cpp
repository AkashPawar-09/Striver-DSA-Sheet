/*

Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.


Input: s = "cccaaa"
Output: "aaaccc"
Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
Note that "cacaca" is incorrect, as the same characters must be together.


Input: s = "Aabb"
Output: "bbAa"
Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.


*/


#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    string frequencySort(string s) {

        unordered_map<char, int> mp;

        // Count frequency
        for (char ch : s) {
            mp[ch]++;
        }

        string ans = "";

        while (!mp.empty()) {

            char maxChar;
            int maxFreq = 0;

            // Find character with maximum frequency
            for (auto it : mp) {
                if (it.second > maxFreq) {
                    maxFreq = it.second;
                    maxChar = it.first;
                }
            }

            // Add that character maxFreq times
            while (maxFreq--) {
                ans += maxChar;
            }

            // Remove it from the map
            mp.erase(maxChar);
        }

        return ans;
    }
};


// Time Complexity : O(N²)
// Space Complexity : O(N)