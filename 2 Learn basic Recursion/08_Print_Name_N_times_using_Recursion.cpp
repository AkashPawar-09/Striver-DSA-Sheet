/*
Input: N = 3
Output: Ashish Ashish Ashish 
Explanation: Name is printed 3 times.

Input: N = 1
Output: Ashish 
Explanation: Name is printed once.

*/


#include<bits/stdc++.h>
using namespace std ;


class Solution {
public:
    void printName(int i, int n, string name) {
        if(i > n) return;  
        cout << name << " " ;   // Printing 
        printName(i + 1, n, name);        
    }
    
};

int main() {
    string name;
    getline (cin , name );

    int n ; 
    cin >> n ;

    Solution obj;
    obj.printName(1, n, name);

    return 0;
}

