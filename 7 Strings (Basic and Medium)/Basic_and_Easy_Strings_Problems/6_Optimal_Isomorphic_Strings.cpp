/*

Input: s = "egg", t = "add"
Output: true
Explanation:
The strings s and t can be made identical by:
Mapping 'e' to 'a'.
Mapping 'g' to 'd'.


Input: s = "f11", t = "b23"
Output: false
Explanation:
The strings s and t can not be made identical as '1' needs to be mapped to both '2' and '3'.


Input: s = "paper", t = "title"
Output: true

*/


#include<bits/stdc++.h>
using namespace std ;


class Solution {
public:
    bool isIsomorphic(string s, string t) {

        if (s.size() != t.size())
            return false;

        unordered_map<char, char> mp1;
        unordered_map<char, char> mp2;

        for (int i = 0; i < s.size(); i++) {

            // Check mapping from s -> t
            if (mp1.count(s[i])) {
                if (mp1[s[i]] != t[i])
                    return false;
            }
            else {
                mp1[s[i]] = t[i];
            }

            // Check mapping from t -> s
            if (mp2.count(t[i])) {
                if (mp2[t[i]] != s[i])
                    return false;
            }
            else {
                mp2[t[i]] = s[i];
            }
        }

        return true;
    }
};

int main() {

    Solution obj;

    string s, t;
    cin >> s >> t;

    if (obj.isIsomorphic(s, t))
        cout << "true";
    else
        cout << "false";

    return 0;
}

// Time Complexity : O(N)
// Space Complexity : O(1)