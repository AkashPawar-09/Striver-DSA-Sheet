/*

// LeetCode : 509. Fibonacci Number

Input: n = 2
Output: 1
Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.

Input: n = 3
Output: 2
Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.

Input: n = 4
Output: 3
Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.
*/


#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int fib(int n) {
        if(n==0) return 0;                  // base case 1 
        if(n==1) return 1;                  // base case 2
        int a = 0;                          // a = 0 
        int b = 1;                          // b = 1
        for(int i = 2; i <=n; i++){         // start loop from i = 2 to n
            int c = a + b;                  // make next element of fib = c
            a=b;                            // make value of a = value of b
            b=c;                            // make value of b = value of c
        }
        return b;                           // return the value of b (current required solution)
    }
};



int main() {
    int n;
    cin >> n ;

    Solution obj; 
    obj.fib(n); 

    cout << obj.fib(n) ;
    return 0;
}
