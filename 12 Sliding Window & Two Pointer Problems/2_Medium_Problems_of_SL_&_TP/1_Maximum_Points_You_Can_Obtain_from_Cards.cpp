/*

Input: cardPoints = [1,2,3,4,5,6,1], k = 3
Output: 12
Explanation: After the first step, your score will always be 1. However, 
choosing the rightmost card first will maximize your total score. 
The optimal strategy is to take the three cards on the right, giving a final score of 1 + 6 + 5 = 12.


Input: cardPoints = [2,2,2], k = 2
Output: 4
Explanation: Regardless of which two cards you take, your score will always be 4.


Input: cardPoints = [9,7,7,9,7,7,9], k = 7
Output: 55
Explanation: You have to take all the cards. Your score is the sum of points of all cards.

*/


#include<bits/stdc++.h>
using namespace std ;


class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size() ;                 // total elements in given array
        int Lsum = 0 ;                              // variable calculates Left side Sum
        int Rsum = 0 ;                              // variable calculates Right side Sum
        int R_end = n-1 ;                           // right sided end to calculate Sum from right

        for(int j = 0 ; j < k ; j++){               // calculate Sum from Left side in given array
            Lsum = Lsum + cardPoints[j] ;
        }

        int maximum = Lsum ;                        // make Lsum as maximum Sum (can be updated in next for loop)

        for (int i = k - 1; i >= 0; i--) {          // loop from (k-1)th element to 0th element
            Lsum = Lsum - cardPoints[i];            // decrease Left side Sum by 1 element (from(k-1)th element)
            Rsum = Rsum + cardPoints[R_end];        // increase right side Sum by 1 element from Right end towards left
            maximum = max(maximum,(Lsum+Rsum));     // find maximum between Lsum OR Rsum OR Lsum+Rsum
            R_end--;                                // dynamic iteration in one loop (R_end--)
        }

        return maximum ;                            // return updated maximum sum of elements
    }
};



int main() {
    Solution obj;
    vector<int> cardPoints = {1, 2, 3, 4, 5, 6, 1};
    int k = 3;
    cout << obj.maxScore(cardPoints, k);
    return 0;
}


// Time Complexity : O(2N)
// Space Complexity : O(1)