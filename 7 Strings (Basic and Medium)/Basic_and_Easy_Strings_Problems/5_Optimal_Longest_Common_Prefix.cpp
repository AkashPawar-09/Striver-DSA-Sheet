/*

Input: strs = ["flower","flow","flight"]
Output: "fl"


Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

*/


#include<bits/stdc++.h>
using namespace std ;


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        string prefix = strs[0];                    // first string in strs vector stored in prefix string

        for (int i = 1; i < strs.size(); i++) {     // iteration from 2nd string in strs

            while (strs[i].find(prefix) != 0) {     // if first element is not exactly 2nd element 
                prefix.pop_back();                  // then remove last character in 1st element

                if (prefix.empty()) {               // if nothing is same two strings become different 
                    return "";                      // then after pop_back each element cause empty string
                } // then return "" 
            }
        }

        return prefix;                              // after comparing prefix with every element return updated prefix
    }
};


int main() {
    Solution obj;

    int n;
    cin >> n;

    vector<string> strs(n);

    for (int i = 0; i < n; i++) {
        cin >> strs[i];
    }

    cout << obj.longestCommonPrefix(strs);

    return 0;
}


// Time Complexity : O(N × M)
// Space Complexity : O(1)