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

        // Count frequency of each character
        for (char ch : s) {
            mp[ch]++;
        }

        // Store (character, frequency) pairs
        vector<pair<char, int>> vec;

        for (auto it : mp) {
            vec.push_back({it.first, it.second});
        }

        // Sort by frequency in descending order
        sort(vec.begin(), vec.end(),
            [](pair<char, int> a, pair<char, int> b) {
                return a.second > b.second;
            });

        // Build the answer
        string ans = "";

        for (auto it : vec) {
            ans.append(it.second, it.first);
        }

        return ans;
    }
};


// Time Complexity : O(N)
// Space Complexity : O(N)
