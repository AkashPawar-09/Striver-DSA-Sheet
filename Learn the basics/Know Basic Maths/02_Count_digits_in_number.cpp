/*
Example 1:
Input:N = 12345
Output:5
Explanation:  The number 12345 has 5 digits.
                        
Example 2:
Input:N = 7789              
Output: 4
Explanation: The number 7789 has 4 digits. 
*/



#include <iostream>
using namespace std;

class Solution {
public:
    int countDigit(int n) {
        if (n == 0) {return 1 ;}
        
        int count = 0 ;

        for ( ; n>0 ; n=n/10){
            count++;
        }
        return count ;
    }
};

//      while (n>0){
//          n = n / 10 ; 
//          count ++ ; 
//      }



int main() {
    int n;
    cout << "Enter number: ";
    cin >> n;
    Solution obj;   
    int result = obj.countDigit(n);  
    cout << result << endl;
    return 0;
}
