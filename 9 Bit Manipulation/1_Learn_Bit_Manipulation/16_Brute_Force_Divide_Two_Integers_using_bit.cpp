#include <iostream>
#include <climits>
using namespace std;


// FOR LEETCODE , Time Limit Exceeded

class Solution {
public:
    int divide(int dividend, int divisor) {

        if(dividend == divisor) return 1;               
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        if(divisor == 1) return dividend;
        
        long long dd = dividend;
        long long ds = divisor;

        bool negative = (dd < 0) ^ (ds < 0);        // XOR of 1 negative and 1 postive is always negative

        dd = abs(dd);                   // removes negative sign if it have     
        ds = abs(ds);                   // removes negative sign if it have 

        long long sum = 0;              // initilise sum = 0    ----> for counting sum dynamically
        long long count = 0;            // initilise count = 0  ----> for counting quotient 

        while (sum + ds <= dd) {        // while sum overflows dividend
            sum = sum + ds;             // increse sum with iteration 
            count++;                    // increase count with iteration
        }

        if (negative) {                 // if answer wants to be negative
            count = -count;             // make count negative
        }

        if (count > INT_MAX)            // controls INT_MAX overflow
            return INT_MAX;

        if (count < INT_MIN)            // controls INT_MIN overflow
            return INT_MIN;

        return count;                   // return count
    }
};




int main() {

    int dividend = 29;
    int divisor = -5;

    Solution obj;

    int result = obj.divide(dividend, divisor);

    cout << "Dividend: " << dividend << endl;
    cout << "Divisor: " << divisor << endl;
    cout << "Result: " << result << endl;

    return 0;
}



// Time Complexity : O(|dividend / divisor|)
// Space Complexity : O(1)