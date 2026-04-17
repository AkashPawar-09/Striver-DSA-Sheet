/*
Example 1:
Input: Str =  “ABCDCBA”
Output: Palindrome
Explanation: String when reversed is the same as string.

Example 2:
Input: Str = “TAKE U FORWARD”
Output: Not Palindrome
Explanation: String when reversed is not the same as string.
*/


#include<bits/stdc++.h>
using namespace std ;

class Solution{	
	public:		
		bool palindromeCheck(string& s){
			string s2 = s ;
            int n = s.length() ;
            for(int i = 0; i < n/2; i++){
                swap(s[i], s[n - i - 1]);
            }
            return s==s2 ;
		}
};




int main() {
    string s;
    getline (cin , s );

    Solution obj;
    cout << obj.palindromeCheck(s);   // Printing 

    return 0;
}













