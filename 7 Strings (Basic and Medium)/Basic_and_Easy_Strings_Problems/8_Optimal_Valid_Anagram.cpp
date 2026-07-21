/*

Input: s = "anagram", t = "nagaram"
Output: true


Input: s = "rat", t = "car"
Output: false

*/

#include<bits/stdc++.h>
using namespace std ;


class Solution {
public:
    bool isAnagram(string s, string t) {
        int freq[26] = {0};                 // created hash map with all elements 0

        for (char ch : s)                   // for each char in "s" 
            freq[ch - 'a']++;               // increase frequency of each char

        for (char ch : t)                   // for each char in "t" 
            freq[ch - 'a']--;               // decrease frequency of each char

        for (int i = 0; i < 26; i++) {      // iteration to cheak each frequency
            if (freq[i] != 0) {             // cheak all the frequencies are equal to 0
                return false;               // if not then return false (Not Anagram)
            }
        }

        return true;                        // otherwise return true (Anagram)
    }
};


int main() {

    Solution obj;

    string s, t;
    cin >> s >> t;

    if (s.size() != t.size()) {
        cout << "Not Anagram";
        return 0;
    }

    if (obj.isAnagram(s, t))
        cout << "Anagram";
    else
        cout << "Not Anagram";

    return 0;
}



// Time Complexity : O(N)
// Space Complexity : O(1)


/* --------------------------------------------------------------------------------------------------------------------------

Logic : If both words are anagram then their letter frequencies cancels each other in 2 loop using increament and decreament.

-------------------------------------------------------------------------------------------------------------------------- */