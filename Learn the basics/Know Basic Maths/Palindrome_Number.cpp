/*
Example 1 :
Input: n = 121
Output: true
Explanation: When read from left to right : 121.
When read from right to left : 121.

Example 2 : 
Input: n = 123
Output: false
Explanation: When read from left to right : 123.
When read from right to left : 321.
*/



#include<iostream> 
using namespace std ;


class Solution {
public:
    bool isPalindrome(int n) {

        int original = n;  // store original number (required)
        int rev = 0;

        for ( ; n!=0 ; n = n / 10 ){
            int digit = n % 10 ;
            rev = rev*10  + digit ;
        }
    
        return original == rev ;
    }
};




int main() {
    int n;
    cout << "Enter number: ";
    cin >> n;
    Solution obj;   
    int result = obj.isPalindrome(n);  
    cout << result << endl;
    return 0;
}

// Time Complexity: O(log n)
// Space Complexity: O(1)