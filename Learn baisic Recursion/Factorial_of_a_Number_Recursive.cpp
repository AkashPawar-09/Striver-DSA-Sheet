/*
Input: X = 5
Output: 120
Explanation: 5! = 5*4*3*2*1

Input:X = 3
Output: 6
Explanation: 3!=3*2*1
*/



#include<bits/stdc++.h>
using namespace std ;

class Solution {
public :
    int factorial(int n) {
        if (n==0) return 1 ;
        return n * factorial (n-1) ;        
    }
};


int main () {
    int n ;
    cin >> n ;

    Solution obj ;
    cout << obj.factorial (n) ;  // Printing 

    
    return 0 ;
}



// Time Complexity: O(n)
// Space Complexity: O(n)