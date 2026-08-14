#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    string toBinary(int n) {
        string ans = "";
        while (n > 0) {
            int bit = n & 1;
            ans += char(bit + '0');

            n = n >> 1;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};



int main() {
    Solution obj;
    int n;
    cin >> n;
    cout << obj.toBinary(n);
    return 0;
}



// Time Complexity : O(log N)
// Space Complexity : O(log N)