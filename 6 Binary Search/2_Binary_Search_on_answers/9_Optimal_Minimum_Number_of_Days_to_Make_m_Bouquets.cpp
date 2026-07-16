/* -------------------------------------------------------------------------------------------------------------------------

Input: bloomDay = [1,10,3,10,2], m = 3, k = 1
Output: 3
Explanation: Let us see what happened in the first three days. 
x means flower bloomed and _ means flower did not bloom in the garden.
We need 3 bouquets each should contain 1 flower.
After day 1: [x, _, _, _, _]   // we can only make one bouquet.
After day 2: [x, _, _, _, x]   // we can only make two bouquets.
After day 3: [x, _, x, _, x]   // we can make 3 bouquets. The answer is 3.


Input: bloomDay = [7,7,7,7,12,7,7], m = 2, k = 3
Output: 12
Explanation: We need 2 bouquets each should have 3 flowers.
Here is the garden after the 7 and 12 days:
After day 7: [x, x, x, x, _, x, x]
We can make one bouquet of the first three flowers that bloomed. 
We cannot make another bouquet from the last three flowers that bloomed because they are not adjacent.
After day 12: [x, x, x, x, x, x, x]
It is obvious that we can make two bouquets in different ways.


Input: arr[] = [5, 5, 5, 5, 10, 5, 5], m = 2, k = 3,
Output: 10
Explanation: We need to make 2 bouquets, each consisting of 3 adjacent flowers.
-> By day 5, all flowers have bloomed except the flower at position 5 (1-indexed).
-> We can form the 1st bouquet using the first 3 bloomed flowers.
-> It is not possible to form the 2nd bouquet now.
-> By day 10, all the flowers have bloomed.
-> We can then form 2 bouquets, each consisting of 3 adjacent flowers.

------------------------------------------------------------------------------------------------------------------------- */


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();                  // size of bloomDay vector

        if ((long long)m * k > n)                 // if total flowers needed > available flowers
            return -1;

        int mini = *min_element(bloomDay.begin(), bloomDay.end()); // minimum bloom day
        int maxi = *max_element(bloomDay.begin(), bloomDay.end()); // maximum bloom day

        int low = mini;
        int high = maxi;

        while (low <= high) {
            int mid = low + (high - low) / 2;       // Calculate mid everytime 

            int flowers = 0;                        // stores consecutive bloomed flowers
            int bouquets = 0;                       // total bouquets formed

            for (int i = 0; i < n; i++) {
                if (bloomDay[i] <= mid) {            // cheaks adjecent flowers is smaller than or equal to mid OR NOT
                    flowers ++;                      // then increase count of flowers
                }
                else {
                    bouquets = bouquets + flowers / k;  // make bouquets from consecutive flowers
                    flowers = 0;                        // reset consecutive flowers
                }
            }

            bouquets = bouquets + flowers / k;      // last consecutive flowers

            if (bouquets >= m)                      // if possible to make m bouquets
                high = mid - 1;                     // search for smaller answer (eliminate right side)
                
            else                                    // if not possible to make m bouquets (bouquets < m)
                low = mid + 1;                      // search on right side
        }
        return low;                                 // minimum day required
    }
};


int main() {

    int n;
    cin >> n;

    vector<int> bloomDay(n);

    for (int i = 0; i < n; i++)
        cin >> bloomDay[i];

    int m, k;
    cin >> m >> k;

    Solution obj;

    cout << obj.minDays(bloomDay, m, k);

    return 0;
}


// Time Complexity : O(N * log(maxi - mini))
// Space Complexity : O(1)