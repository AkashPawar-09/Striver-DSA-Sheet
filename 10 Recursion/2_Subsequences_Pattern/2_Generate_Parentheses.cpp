/*
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]

*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void generate(int n, int open, int close, string &current, vector<string> &ans) {
        if (current.size() == 2 * n) {
            ans.push_back(current);
            return;
        }

        if (open < n) {
            current.push_back('(');
            generate(n, open + 1, close, current, ans);
            current.pop_back();
        }

        if (close < open) {
            current.push_back(')');
            generate(n, open, close + 1, current, ans);
            current.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string current;

        generate(n, 0, 0, current, ans);

        return ans;
    }
};

int main() {
    Solution obj;

    int n;
    cin >> n;

    vector<string> ans = obj.generateParenthesis(n);

    for (string s : ans) {
        cout << s << " ";
    }

    return 0;
}



// Time Complexity: O(Cₙ × n) where Cₙ is the nth Catalan number
// Space Complexity: O(Cₙ × n) for storing all valid strings and recursion