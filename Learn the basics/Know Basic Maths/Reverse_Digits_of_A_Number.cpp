/*
Example 1 : 
Input: N = 12345
Output:54321
Explanation: The reverse of 12345 is 54321.

Example 2 : 
Input: N = 7789                
Output: 9877
Explanation: The reverse of number 7789 is 9877.
*/


#include <iostream>
using namespace std;

class Solution {
public:
    int reverseNumber(int n) {
        
        int rev = 0;

        for ( ; n!=0 ; n = n / 10 ){
            int digit = n % 10 ;
            rev = rev*10  + digit ;
        }
    return rev;
    }
};


//      while(n != 0) {
//          int digit = n % 10;     
//          rev = rev * 10 + digit; 
//          n = n / 10;             
//      }




int main() {
    int n;
    cout << "Enter number: ";
    cin >> n;
    Solution obj;   
    int result = obj.reverseNumber(n); 
    cout << result << endl;
    return 0;
}

// Time Complexity: O(log n)
// Space Complexity: O(1)