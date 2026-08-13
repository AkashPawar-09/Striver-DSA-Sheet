/*  Recursion — Basics

Definition: A function that calls itself to solve a smaller instance of the same problem, until it hits a case simple enough to answer directly.


Properties

Base case — the stopping condition. Without it, infinite calls → stack overflow.
Recursive case — function calls itself with a smaller/simpler input, moving toward the base case.
Call stack — each call gets pushed onto the stack with its own local variables; popped off when it returns.
Implicit backtracking — after the base case is hit, control returns back up through each pending call, resuming where it left off.


Why it matters

Naturally expresses problems defined in terms of themselves (factorial, Fibonacci, tree/graph traversal, divide-and-conquer like merge sort).
Cleaner code for problems that would need explicit stacks if written iteratively.
Foundation for backtracking, DP (recursion + memoization), and tree/graph algorithms — all upcoming topics.

*/



//  Example : Factorial
//  Concept: n! = n * (n-1)!, with 0! = 1 as base case.

#include <iostream>
using namespace std;


// Solution

int factorial(int n) {
    if (n == 0) return 1;        // base case: stops recursion
    return n * factorial(n - 1); // recursive case: smaller subproblem
}



// Driver Code :

int main() {
    cout << factorial(4) << endl; // 24
    return 0;
}




// Time Complexity : O(N) 
// Space Complexity : O(N)