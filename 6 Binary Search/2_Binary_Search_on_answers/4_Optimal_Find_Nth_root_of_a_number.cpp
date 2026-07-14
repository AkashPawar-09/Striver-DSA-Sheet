/*

Input: N = 3, M = 27
Output: 3
Explanation: The cube root of 27 is equal to 3.


Input: N = 4, M = 69
Output:-1
Explanation: The 4th root of 69 does not exist. So, the answer is -1.


Input: N = 4, M = 81
Output: 3

*/


#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
  int NthRoot(int N, int M) {
        int low = 1 ; 
        int high = M ;

        while (low <= high) {
            int mid = low + (high - low) / 2 ;
            if (pow(mid, N) == M) {             // if calculated answer is equal to M
                return mid;                     // return that mid (answer)
            }
            else if (pow(mid, N) < M) {         // if calculated answer is grater than M
                low = mid + 1;                  // Trim left part
            }
            else {                              // if calculated answer is smaller than M
                high = mid - 1;                 // Trim right part
            }
        }
        return -1 ;                             // return -1 
    }
};


int main() {
    int N, M;
    cin >> N >> M;

    Solution obj;

    cout << obj.NthRoot(N, M) << endl;

    return 0;
}

// Time Complexity : O(log N * log M)
// Space Complexity : O(1)