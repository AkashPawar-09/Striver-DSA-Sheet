/*
Euclidean Algorithm:

The Euclidean Algorithm is a method for finding the greatest common divisor (GCD)
of two numbers. It operates on the principle that the GCD of two numbers remains
the same even if the smaller number is subtracted from the larger number.

To find the GCD of n1 and n2 where n1 > n2:
1. Repeatedly subtract the smaller number from the larger number until one of them becomes 0.
2. Once one becomes 0, the other is the GCD of the original numbers.

Example:
n1 = 20, n2 = 15

gcd(20, 15) = gcd(20 - 15, 15) = gcd(5, 15)
gcd(5, 15)  = gcd(15 - 5, 5)  = gcd(10, 5)
gcd(10, 5)  = gcd(10 - 5, 5) = gcd(5, 5)
gcd(5, 5)   = gcd(5 - 5, 5)  = gcd(0, 5)

Hence, return 5 as the GCD.

*/



#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int GCD(int n1,int n2) {
        int diff ;
        int gcd ;
        while(n1 != n2) {
            if(n1 > n2) {
                n1 = n1 - n2;
            } else {
                n2 = n2 - n1;
            }
}
return n1;
        
    }
};

 


// while(n2 != 0) {
//     int temp = n2;
//     n2 = n1 % n2;
//     n1 = temp;
// }
// return n1; 
        


int main() {
    int n1, n2;
    cout << "Enter two numbers: ";
    cin >> n1 >> n2;

    Solution obj;
    int result = obj.GCD(n1, n2);

    cout << result << endl;
    return 0;
}

// Time Complexity: O(max(n1, n2))
// Space Complexity: O(1)