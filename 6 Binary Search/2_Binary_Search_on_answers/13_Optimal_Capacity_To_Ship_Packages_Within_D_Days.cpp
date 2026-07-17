/*

Input: weights = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], days = 5
Output: 15
Explanation: 
Minimum ship capacity = 15. One way to ship in 5 days:
Day 1: 1 + 2 + 3 + 4 + 5 = 15
Day 2: 6 + 7 = 13
Day 3: 8
Day 4: 9
Day 5: 10
No day exceeds capacity 15 and all packages are shipped in order in 5 days.
Note that the cargo must be shipped in the order given, so using a ship of capacity 14 and splitting the packages into parts like (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) is not allowed.


Input: weights = [3, 2, 2, 4, 1, 4], days = 3
Output: 6
Explanation:
One possible division with capacity 6:
Day 1: 3 + 2 = 5
Day 2: 2 + 4 = 6
Day 3: 1 + 4 = 5
All packages shipped in order within 3 days.


Input: weights = [1,2,3,1,1], days = 4
Output: 3
Explanation:
1st day: 1
2nd day: 2
3rd day: 3
4th day: 1, 1

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();                                     // size of weights array

        int mini = *max_element(weights.begin(), weights.end());    // minimum possible capacity i.e. Maximum element in given vector
        int maxi = accumulate(weights.begin(), weights.end(), 0);   // maximum possible capacity i.e. Sum of all elments in vector

        int low = mini ;
        int high = maxi ;

        while (low <= high) {

            int mid = low + (high - low) / 2;                       // check every capacity
            int load = 0;                                           // initilise load = 0 everytime
            int requiredDays = 1;                                   // initially 1 day

            for (int j = 0; j < n; j++) {
                if (load + weights[j] <= mid) {                       // if total load is greater than current capacity 
                    load = load + weights[j];                       // add extra load until complete capacity 
                }
                else {                                              // if package is overload 
                    requiredDays++;                                 // then start next day
                    load = weights[j];                              // and fill the leftover load
                }
            }

            if (requiredDays <= days) {                             // if require days are smaller than given days to ship 
                high = mid - 1;                                     // move high before mid
            }
            else {
                low = mid + 1;                                      // else move low to right after mid
            }
        }

        return low;                                                // return low
    }
};



int main() {

    int n;
    cout << "Enter number of packages: ";
    cin >> n;

    vector<int> weights(n);

    cout << "Enter package weights: ";
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    int days;
    cout << "Enter number of days: ";
    cin >> days;

    Solution obj;

    cout << "Minimum Ship Capacity = " << obj.shipWithinDays(weights, days);

    return 0;
}

// Time Complexity = O(n × log(sum - maxWeight + 1))
// Space Complexity : O(1)