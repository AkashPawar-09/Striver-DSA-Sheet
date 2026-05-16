/*
Input: N=5
Output: 15
Explanation: 1+2+3+4+5=15

Input: N=6
Output: 21
Explanation: 1+2+3+4+5+6=15
*/



#include<bits/stdc++.h>
using namespace std ;

class Solution{	
	public:
		int NnumbersSum(int n){     
            if (n == 0) return 0;
            return n + NnumbersSum(n - 1);        
		}
};


int main () {
    int n ;
    cin >> n ;
    
    Solution obj ;
    cout << obj.NnumbersSum(n); // Printing 

    return 0 ;
}







