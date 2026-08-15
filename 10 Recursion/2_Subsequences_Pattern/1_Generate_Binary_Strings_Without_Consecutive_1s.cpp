/*
Input: n = 3
Output: ["000", "001", "010", "100", "101"]
Explanation: All strings are of length 3 and do not contain consecutive 1s.

Input: n = 2
Output: ["00", "01", "10"]

*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    void generate(int n, string &current, vector<string> &ans) {
        if (current.size() == n) {
            ans.push_back(current);
            return;
        }

        current.push_back('0');
        generate(n, current, ans);
        current.pop_back();

        if (current.empty() || current.back() != '1') {
            current.push_back('1');
            generate(n, current, ans);
            current.pop_back();
        }
    }
    vector<string> generateBinaryStrings(int n) {
        vector<string> ans;
        string current;
        generate(n, current, ans);
        return ans;
    }
};



int main() {
    Solution obj;
    int n;
    cin >> n;
    vector<string> ans = obj.generateBinaryStrings(n);
    for (string s : ans) {
        cout << s << " ";
    }
    return 0;
}


// Time Complexity: O(2^n * n)
// Space Complexity: O(2^n * n)