/*

Input: Str =  “ABCDCBA”
Output: Palindrome
Explanation: String when reversed is the same as string.

Input: Str = “TAKE U FORWARD”
Output: Not Palindrome
Explanation: String when reversed is not the same as string.

*/

#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s, int start, int end) {
        if (start >= end) {return true;}
        if (s[start] != s[end]) {return false;}
        return isPalindrome(s, start + 1, end - 1);
    }
};


/*  without Recursion 

class Solution{	
public:		
	bool isPalindrome(string& s){
		string s2 = s ;
        int n = s.length() ;
        for(int i = 0; i < n/2; i++){
            swap(s[i], s[n - i - 1]);
        }
        return s==s2 ;
	}
};

*/

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    Solution obj;
    if (obj.isPalindrome(s, 0, s.size() - 1))
        cout << "Palindrome" << endl;
    else
        cout << "Not Palindrome" << endl;

    return 0;
}




// Time Complexity : O(N/2)
// Space Complexity : O(N)