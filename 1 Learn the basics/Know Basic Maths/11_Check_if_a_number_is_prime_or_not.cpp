/*
Example 1

Input: n = 5

Output: true

Explanation: The only divisors of 5 are 1 and 5 , So the number 5 is prime.

Example 2

Input: n = 8

Output: false

Explanation: The divisors of 8 are 1, 2, 4, 8, thus it is not a prime number.
*/



#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    bool isPrime(int n) {
        vector<int> v;

        for (int i = 1 ; i <= n ; i++ ){
            if (n % i == 0){
                v.push_back(i);
            }
        }

        if (v.size () == 2 ){
            return true ;
        }
        else {return false ;}
    }
};





int main() {
    int n;
    cout << "Enter number: ";
    cin >> n;
    Solution obj;   
    int result = obj.isPrime(n);  
    cout << result << endl;
    return 0;
}
