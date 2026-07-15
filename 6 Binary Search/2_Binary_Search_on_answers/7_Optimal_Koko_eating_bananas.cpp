/*

Input: n = 4, nums = [7, 15, 6, 3], h = 8
Output: 5
Explanation: If Koko eats 5 bananas/hr, he will take 2, 3, 2, and 1 hour to eat the piles accordingly. 
So, he will take 8 hours to complete all the piles.  


Input: n = 5, nums = [25, 12, 8, 14, 19], h = 5
Output: 25
Explanation: If Koko eats 25 bananas/hr, he will take 1, 1, 1, 1, and 1 hour to eat the piles accordingly. 
So, he will take 5 hours to complete all the piles.


Input: piles = [3,6,7,11], h = 8
Output: 4


Input: piles = [30,11,23,4,20], h = 5
Output: 30


Input: piles = [30,11,23,4,20], h = 6
Output: 23

*/


#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while (low <= high) {

            int mid = low + (high - low) / 2;
            
            int totalHours = 0;
            
            for (int i = 0; i < piles.size(); i++) {
                totalHours = totalHours + (piles[i] + mid - 1) / mid;
            }
            
            if (totalHours <= h) {high = mid - 1;}
            
            else {low = mid + 1;}
        }
        return low;
    }
};


int main() {

    int n, h;

    cout << "Enter number of piles: ";
    cin >> n;

    vector<int> piles(n);

    cout << "Enter bananas in each pile: ";
    for (int i = 0; i < n; i++) {
        cin >> piles[i];
    }

    cout << "Enter total hours: ";
    cin >> h;

    Solution obj;

    cout << "Minimum Eating Speed = "
         << obj.minEatingSpeed(piles, h);

    return 0;
}


// Time Complexity : O(n × log(max(piles)))
// Space Complexity : O(1)





/* ======================================== Explanation =====================================================

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while (low <= high) {

            int mid = low + (high - low) / 2;
            
            int totalHours = 0;
            
            for (int i = 0; i < piles.size(); i++) {
                totalHours = totalHours + (piles[i] + mid - 1) / mid;
            }
            
            if (totalHours <= h) {high = mid - 1;}
            
            else {low = mid + 1;}
        }
        return low;
    }
};


--------------------------------------------------------------------------------------------------------------------------


int low = 1 
// lowest elment for BS is 1


int high = *max_element(piles.begin(), piles.end()); 
// high is the highest element in piles


while (low <= high) {
// Simple BS Condition 


int mid = low + (high - low) / 2;
// Calculate mid


int totalHours = 0;
// Assume totalHours to be zero each time to calculate total time during 1 iteration 


for (int i = 0; i < piles.size(); i++) {
    totalHours = totalHours + (piles[i] + mid - 1) / mid;
}
// for loop to traverse each element in piles vector
// update totalHours by given statement 


(piles[i] + mid - 1) / mid
// gives ceil() value


if (totalHours <= h) {high = mid - 1;}
// if after calculating totalHours , exceeds h , trim search space of right side
// that means answer must belongs to left side 


else {low = mid + 1;}
// otherwise trim search space of left side


return low;
return the low (answer of BS)

======================================================================================================================= */