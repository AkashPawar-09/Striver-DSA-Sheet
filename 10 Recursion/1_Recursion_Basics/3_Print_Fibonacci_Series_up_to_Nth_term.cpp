#include<bits/stdc++.h>
using namespace std ;


class Solution {
public:
    int fib(int n) {
        if (n==0) {return 0;}                   // base case of fib(n-2)
        if (n==1) {return 1;}                   // base case of fib(n-1)
        int result = fib(n-1) + fib(n-2) ;      // actual recursion
        return result ;                         // return total updated result after all recursion
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




// Time Complexity : O(2^N)
// Space Complexity : O(N)