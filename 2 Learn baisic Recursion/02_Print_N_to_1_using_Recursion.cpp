/*
Input: N = 4
Output: 4, 3, 2, 1
Explanation: All the numbers from 4 to 1 are printed.

Input: N = 1
Output: 1 
Explanation: This is the base case.
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void printNto1(int n) {
        if (n == 0) return;
        cout << n << " ";   // Printing 
        printNto1(n - 1);
    }
};

int main() {
    int n;
    cin >> n;

    Solution obj; 
    obj.printNto1(n); 

    return 0;
}



