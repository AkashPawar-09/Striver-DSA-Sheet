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



// #include <iostream>
// #include <algorithm>

// using namespace std;

// int findGcd(int a, int b) {
//     // Continue loop as long as both
//     // a and b are greater than 0
//     while(a > 0 && b > 0) {
//         // If a is greater than b,
//         // subtract b from a and update a
//         if(a > b) {
//              // Update a to the remainder
//              // of a divided by b
//             a = a % b;
//         }
//         // If b is greater than or equal
//         // to a, subtract a from b and update b
//         else {
//             // Update b to the remainder
//             // of b divided by a
//             b = b % a; 
//         }
//     }
//     // Check if a becomes 0,
//     // if so, return b as the GCD
//     if(a == 0) {
//         return b;
//     }
//     // If a is not 0,
//     // return a as the GCD
//     return a;
// }




// int main() {
//     int n1 = 20, n2 = 15;
    
//     // Find the GCD of n1 and n2
//     int gcd = findGcd(n1, n2);

//     cout << "GCD of " << n1 << " and " << n2 << " is: " << gcd << endl;

//     return 0;
// }
    