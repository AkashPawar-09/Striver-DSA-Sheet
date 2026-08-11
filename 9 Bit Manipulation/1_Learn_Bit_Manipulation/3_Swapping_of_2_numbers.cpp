#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void swapNumbers(int &a, int &b) {
        a = a ^ b;      // a = a ^ b
        b = a ^ b;      // b = (a^b) ^ b = a
        a = a ^ b;      // a = (a^b) ^ a = b
    }
};

int main() {
    Solution obj;
    int a, b;
    cin >> a >> b;
    obj.swapNumbers(a, b);
    cout << a << endl << b;
    return 0;
}




// Time Complexity: O(1)
// Space Complexity: O(1)