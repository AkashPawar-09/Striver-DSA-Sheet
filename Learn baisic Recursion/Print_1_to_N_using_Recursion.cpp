/*
Input: N = 4
Output: 1, 2, 3, 4
Explanation: All the numbers from 1 to 4 are printed.

Input: N = 1
Output: 1 
Explanation: This is the base case.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void print1toN(int n) {
        if (n == 0) return;
        print1toN(n - 1);
        cout << n << " ";      // Printing 
    }
};

int main() {
    int n;
    cin >> n;

    Solution obj;
    obj.print1toN(n); 

    
    
    return 0;
}

//  Time Complexity: O(n)
//  Space Complexity: O(n)