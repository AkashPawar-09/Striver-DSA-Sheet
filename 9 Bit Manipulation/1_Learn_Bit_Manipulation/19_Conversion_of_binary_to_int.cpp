#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int binaryToInt(string s) {
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            ans = (ans << 1) | (s[i] - '0');
        }
        return ans;
    }
};


int main() {
    Solution obj;
    string s;
    cin >> s;
    cout << obj.binaryToInt(s);
    return 0;
}



// Time Complexity: O(N)
// Space Complexity: O(1)